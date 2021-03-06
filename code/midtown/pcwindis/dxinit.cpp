/*
    Open1560 - An Open Source Re-Implementation of Midtown Madness 1 Beta
    Copyright (C) 2020 Brick

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program. If not, see <http://www.gnu.org/licenses/>.
*/

define_dummy_symbol(pcwindis_dxinit);

#include "dxinit.h"

#include <ddraw.h>
#include <dinput.h>

#include "pcwindis.h"
#include "setupdata.h"

template <typename T>
inline void SafeRelease(T*& ptr)
{
    if (ptr)
    {
        ptr->Release();
        ptr = nullptr;
    }
}

i32 dxiChangeDisplaySettings(i32 /*width*/, i32 /*height*/, i32 /*bpp*/)
{
    return 0;
}

static inline GUID* dxiGetInterfaceGUID()
{
    dxiRendererInfo_t& info = GetRendererInfo();

    return (info.IsHardware() && dxiIsFullScreen()) ? &info.InterfaceGuid : nullptr;
}

static GUID* dxiCurrentInterfaceGUID = nullptr;

void dxiDirectDrawCreate()
{
#ifndef ARTS_DISABLE_DDRAW
    HMODULE ddraw = GetModuleHandleA("DDRAW.DLL");

    if (ddraw == nullptr)
        Quitf("Failed to find DDRAW.DLL");

    auto pDirectDrawCreate = reinterpret_cast<decltype(&DirectDrawCreate)>(GetProcAddress(ddraw, "DirectDrawCreate"));

    if (pDirectDrawCreate == nullptr)
        Quitf("Failed to find DirectDrawCreate");

    dxiCurrentInterfaceGUID = dxiGetInterfaceGUID();

    IDirectDraw* lpDD = nullptr;

    if (pDirectDrawCreate(dxiCurrentInterfaceGUID, &lpDD, NULL) != 0)
        Quitf("dxiDirectDrawCreate: DirectDrawCreate failed.");

    if (lpDD->QueryInterface(IID_IDirectDraw4, (void**) &lpDD4) != 0)
        Quitf("dxiDirectDrawCreate: QI DD4 failed.");

    lpDD->Release();

    if (lpDD4->SetCooperativeLevel(
            hwndMain, dxiIsFullScreen() ? (DDSCL_FULLSCREEN | DDSCL_ALLOWREBOOT | DDSCL_EXCLUSIVE) : DDSCL_NORMAL) != 0)
    {
        Quitf("dxiDirectDrawCreate: SetCooperativeLevel failed.");
    }
#endif
}

void dxiDirectDrawSurfaceDestroy()
{
    SafeRelease(lpClip);
    SafeRelease(lpdsRend);
    SafeRelease(lpdsBack2);
    SafeRelease(lpdsBack);
    SafeRelease(lpdsFront);
}

extern "C" HRESULT WINAPI DirectInputCreateA_Impl(
    HINSTANCE hinst, DWORD dwVersion, LPDIRECTINPUTA* ppDI, LPUNKNOWN punkOuter);

static mem::cmd_param PARAM_dpiaware {"dpiaware"};

void dxiDirectInputCreate()
{
    if (PARAM_dpiaware.get_or(true))
    {
        // Fixes mouse drift when display scale is not 100%

        SetProcessDPIAware();
    }

#if DIRECTINPUT_VERSION == 0x0800
    HRESULT(WINAPI * pDirectInput8Create)
    (HINSTANCE hinst, DWORD dwVersion, REFIID riidltf, LPVOID * ppvOut, LPUNKNOWN punkOuter) =
        reinterpret_cast<decltype(pDirectInput8Create)>(
            GetProcAddress(LoadLibraryA("dinput8.dll"), "DirectInput8Create"));

    HRESULT err =
        pDirectInput8Create(GetModuleHandle(NULL), DIRECTINPUT_VERSION, IID_IDirectInput8A, (void**) &lpDI, NULL);
#else
    HRESULT err = DirectInputCreateA_Impl(GetModuleHandleA(NULL), DIRECTINPUT_VERSION, &lpDI, 0);
#endif

    if (err != 0)
        Quitf("DirectInputCreate failed, code %x", err);
}

static inline void dxiRestoreDisplayMode()
{
#ifndef ARTS_DISABLE_DDRAW
    if (dxiIsFullScreen() && lpDD4)
    {
        lpDD4->RestoreDisplayMode();
        lpDD4->SetCooperativeLevel(hwndMain, DDSCL_NORMAL);
    }
#endif
}

#ifdef ARTS_ENABLE_OPENGL
#    include "agigl/glpipe.h"

void dxiScreenShot(char* file_name)
{
    i32 width = 0;
    i32 height = 0;
    Ptr<u8[]> pixels = glScreenShot(width, height);

    if (pixels == nullptr)
        return;

    i32 pixels_size = 3 * width * height;

    BITMAPFILEHEADER file_header {};
    file_header.bfType = 0x4D42;
    file_header.bfSize = 54 + pixels_size;
    file_header.bfReserved1 = 0;
    file_header.bfReserved2 = 0;
    file_header.bfOffBits = 54;

    BITMAPINFOHEADER info_header {};
    info_header.biSize = sizeof(info_header);
    info_header.biWidth = width;
    info_header.biHeight = height;
    info_header.biPlanes = 1;
    info_header.biBitCount = 24;
    info_header.biCompression = BI_RGB;
    info_header.biSizeImage = 0;
    info_header.biXPelsPerMeter = width;
    info_header.biYPelsPerMeter = height;
    info_header.biClrUsed = 0;
    info_header.biClrImportant = 0;

    char name_buffer[64];

    if (file_name == nullptr)
    {
        i32 shot_num = 0;
        WIN32_FIND_DATAA find_data;

        if (HANDLE find_handle = FindFirstFileA("screen/SHOT*.BMP", &find_data); find_handle != INVALID_HANDLE_VALUE)
        {
            do
            {
                if (!arts_strnicmp(find_data.cFileName, "SHOT", 4))
                    shot_num = std::max<i32>(shot_num, std::atoi(find_data.cFileName + 4));
            } while (FindNextFileA(find_handle, &find_data));

            FindClose(find_handle);
        }

        CreateDirectoryA("screen", NULL);
        arts_sprintf(name_buffer, "screen/SHOT%04d.BMP", shot_num + 1);
        file_name = name_buffer;
    }

    if (HANDLE file = CreateFileA(file_name, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
        file != INVALID_HANDLE_VALUE)
    {
        DWORD written = 0;
        WriteFile(file, &file_header, sizeof(file_header), &written, NULL);
        WriteFile(file, &info_header, sizeof(info_header), &written, NULL);
        WriteFile(file, pixels.get(), pixels_size, &written, NULL);

        CloseHandle(file);
    }

    if (OpenClipboard(NULL))
    {
        if (EmptyClipboard())
        {
            if (HGLOBAL clip_handle = GlobalAlloc(GMEM_MOVEABLE, sizeof(info_header) + pixels_size))
            {
                if (u8* clip_data = static_cast<u8*>(GlobalLock(clip_handle)))
                {
                    std::memcpy(clip_data + 0x0, &info_header, sizeof(info_header));
                    std::memcpy(clip_data + sizeof(info_header), pixels.get(), pixels_size);

                    GlobalUnlock(clip_handle);
                }

                SetClipboardData(CF_DIB, clip_handle);

                GlobalFree(clip_handle);
            }
        }

        CloseClipboard();
    }
}
#endif

void dxiSetDisplayMode()
{
#ifndef ARTS_DISABLE_DDRAW
    dxiDirectDrawSurfaceDestroy();

    if (dxiCurrentInterfaceGUID != dxiGetInterfaceGUID())
    {
        dxiRestoreDisplayMode();
        SafeRelease(lpDD4);
        dxiDirectDrawCreate();
    }

    if (dxiIsFullScreen())
    {
        Displayf("dxiSetDisplayMode(%d,%d,%d)", dxiWidth, dxiHeight, dxiDepth);

        u32 err = lpDD4->SetDisplayMode(dxiWidth, dxiHeight, dxiDepth, 0, 0);

        if (err)
        {
            Quitf(
                "dxiDirectDrawCreate: SetDisplayMode(%d,%d,%d) failed: code %08X.", dxiWidth, dxiHeight, dxiDepth, err);
        }

        MONITORINFO info {sizeof(MONITORINFO)};
        GetMonitorInfo(MonitorFromWindow(hwndMain, MONITOR_DEFAULTTONEAREST), &info);

        SetWindowPos(hwndMain, HWND_TOP, info.rcMonitor.left, info.rcMonitor.top,
            info.rcMonitor.right - info.rcMonitor.left, info.rcMonitor.bottom - info.rcMonitor.top, SWP_NOZORDER);
    }
    else
    {
        SetWindowPos(hwndMain, HWND_TOP, 0, 0, dxiWidth, dxiHeight, SWP_NOMOVE | SWP_NOZORDER);
    }

    dxiDirectDrawSurfaceCreate();
#endif
}

void dxiShutdown()
{
    SafeRelease(lpDI);

#ifndef ARTS_DISABLE_DDRAW
    dxiDirectDrawSurfaceDestroy();
    dxiRestoreDisplayMode();

    SafeRelease(lpDD4);
#endif

    if (hwndMain)
    {
        DestroyWindow(hwndMain);
        hwndMain = NULL;
    }
}

static ATOM dxiWindowClass = 0;

void dxiWindowCreate(const char* title)
{
    if (hwndMain != NULL)
        return;

    if (!dxiWindowClass)
    {
        WNDCLASSA wnd_class {};

        wnd_class.style = CS_VREDRAW | CS_HREDRAW;
        wnd_class.lpfnWndProc = &MasterWindowProc;
        wnd_class.cbClsExtra = 0;
        wnd_class.cbWndExtra = 0;
        wnd_class.hInstance = 0;

        wnd_class.hIcon =
            dxiIcon ? LoadIcon(GetModuleHandleA(NULL), MAKEINTRESOURCE(dxiIcon)) : LoadIcon(NULL, IDI_APPLICATION);

        wnd_class.hCursor = LoadCursor(NULL, IDC_ARROW);

        wnd_class.hbrBackground = CreateSolidBrush(RGB(0, 0, 0));
        wnd_class.lpszMenuName = 0;
        wnd_class.lpszClassName = "agiwindow";

        dxiWindowClass = RegisterClassA(&wnd_class);
    }

    hwndMain = CreateWindowExA(0, "agiwindow", title, WS_POPUP, 0, 0, dxiWidth, dxiHeight, NULL, NULL, NULL, NULL);

    ShowWindow(hwndMain, SW_SHOWNORMAL);
    UpdateWindow(hwndMain);
}

// 0x574940 | ?translate555@@YAXPAEPAGI@Z
ARTS_IMPORT /*static*/ void translate555(u8* arg1, u16* arg2, u32 arg3);

// 0x5748D0 | ?translate565@@YAXPAEPAGI@Z
ARTS_IMPORT /*static*/ void translate565(u8* arg1, u16* arg2, u32 arg3);
