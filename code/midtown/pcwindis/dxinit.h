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

#pragma once

/*
    pcwindis:dxinit

    0x573B80 | void __cdecl dxiWindowCreate(char *) | ?dxiWindowCreate@@YAXPAD@Z
    0x573C60 | int __cdecl dxiChangeDisplaySettings(int,int,int) | ?dxiChangeDisplaySettings@@YAHHHH@Z
    0x573CC0 | void __cdecl dxiDirectDrawCreate(void) | ?dxiDirectDrawCreate@@YAXXZ
    0x573D80 | void __cdecl dxiSetDisplayMode(void) | ?dxiSetDisplayMode@@YAXXZ
    0x573EC0 | void __cdecl dxiDirectDrawSurfaceCreate(void) | ?dxiDirectDrawSurfaceCreate@@YAXXZ
    0x574190 | void __cdecl dxiDirectDrawSurfaceDestroy(void) | ?dxiDirectDrawSurfaceDestroy@@YAXXZ
    0x574200 | void __cdecl dxiDirectInputCreate(void) | ?dxiDirectInputCreate@@YAXXZ
    0x574240 | void __cdecl dxiShutdown(void) | ?dxiShutdown@@YAXXZ
    0x5742C0 | void * __cdecl dxiMemoryAllocate(struct IDirectDrawSurface4 * *,unsigned int) | ?dxiMemoryAllocate@@YAPAXPAPAUIDirectDrawSurface4@@I@Z
    0x5744E0 | void __cdecl dxiMemoryFree(struct IDirectDrawSurface4 *) | ?dxiMemoryFree@@YAXPAUIDirectDrawSurface4@@@Z
    0x574550 | void __cdecl dxiInit(char *,int,char * *) | ?dxiInit@@YAXPADHPAPAD@Z
    0x574690 | void __cdecl dxiScreenShot(char *) | ?dxiScreenShot@@YAXPAD@Z
    0x5748D0 | void __cdecl translate565(unsigned char *,unsigned short *,unsigned int) | ?translate565@@YAXPAEPAGI@Z
    0x574940 | void __cdecl translate555(unsigned char *,unsigned short *,unsigned int) | ?translate555@@YAXPAEPAGI@Z
    0x660F10 | int dxiWidth | ?dxiWidth@@3HA
    0x660F14 | int dxiHeight | ?dxiHeight@@3HA
    0x660F18 | int dxiDepth | ?dxiDepth@@3HA
    0x660F1C | int dxiFlags | ?dxiFlags@@3HA
    0x909650 | int dxiIcon | ?dxiIcon@@3HA
    0x909658 | struct IDirectDrawSurface4 * lpdsBack2 | ?lpdsBack2@@3PAUIDirectDrawSurface4@@A
    0x90965C | struct IDirectInputA * lpDI | ?lpDI@@3PAUIDirectInputA@@A
    0x909660 | struct IDirectDraw4 * lpDD4 | ?lpDD4@@3PAUIDirectDraw4@@A
    0x909664 | struct IDirectDrawSurface4 * lpdsFront | ?lpdsFront@@3PAUIDirectDrawSurface4@@A
    0x909668 | struct HWND__ * hwndMain | ?hwndMain@@3PAUHWND__@@A
    0x909670 | struct IDirectDrawSurface4 * lpdsBack | ?lpdsBack@@3PAUIDirectDrawSurface4@@A
    0x909674 | struct IDirectDrawClipper * lpClip | ?lpClip@@3PAUIDirectDrawClipper@@A
    0x909678 | struct IDirectDrawSurface4 * lpdsRend | ?lpdsRend@@3PAUIDirectDrawSurface4@@A
*/

// 0x573C60 | ?dxiChangeDisplaySettings@@YAHHHH@Z
ARTS_EXPORT i32 dxiChangeDisplaySettings(i32 width, i32 height, i32 bpp);

// 0x573CC0 | ?dxiDirectDrawCreate@@YAXXZ
ARTS_EXPORT void dxiDirectDrawCreate();

// 0x573EC0 | ?dxiDirectDrawSurfaceCreate@@YAXXZ
ARTS_IMPORT void dxiDirectDrawSurfaceCreate();

// 0x574190 | ?dxiDirectDrawSurfaceDestroy@@YAXXZ
ARTS_EXPORT void dxiDirectDrawSurfaceDestroy();

// 0x574200 | ?dxiDirectInputCreate@@YAXXZ
ARTS_EXPORT void dxiDirectInputCreate();

// 0x574550 | ?dxiInit@@YAXPADHPAPAD@Z
ARTS_IMPORT void dxiInit(char* arg1, i32 arg2, char** arg3);

// 0x5742C0 | ?dxiMemoryAllocate@@YAPAXPAPAUIDirectDrawSurface4@@I@Z | unused
ARTS_IMPORT void* dxiMemoryAllocate(struct IDirectDrawSurface4** arg1, u32 arg2);

// 0x5744E0 | ?dxiMemoryFree@@YAXPAUIDirectDrawSurface4@@@Z | unused
ARTS_IMPORT void dxiMemoryFree(struct IDirectDrawSurface4* arg1);

// 0x574690 | ?dxiScreenShot@@YAXPAD@Z
#ifdef ARTS_ENABLE_OPENGL
ARTS_EXPORT
#else
ARTS_IMPORT
#endif
void dxiScreenShot(char* file_name);

// 0x573D80 | ?dxiSetDisplayMode@@YAXXZ
ARTS_EXPORT void dxiSetDisplayMode();

// 0x574240 | ?dxiShutdown@@YAXXZ
ARTS_EXPORT void dxiShutdown();

// 0x573B80 | ?dxiWindowCreate@@YAXPAD@Z
ARTS_EXPORT void dxiWindowCreate(const char* title);

// 0x660F18 | ?dxiDepth@@3HA
ARTS_IMPORT extern i32 dxiDepth;

// 0x660F1C | ?dxiFlags@@3HA
// 0x1 | FullScreen
// 0x2 | System Memory
// 0x4 | Double Buffer
// 0x8 | Triple Buffer
ARTS_IMPORT extern i32 dxiFlags;

inline bool dxiIsFullScreen()
{
    return dxiFlags & 0x1;
}

inline bool dxiUseSystemMemory()
{
    return dxiFlags & 0x2;
}

inline bool dxiDoubleBuffer()
{
    return dxiFlags & 0x4;
}

inline bool dxiTripleBuffer()
{
    return dxiFlags & 0x8;
}

// 0x660F14 | ?dxiHeight@@3HA
ARTS_IMPORT extern i32 dxiHeight;

// 0x909650 | ?dxiIcon@@3HA
ARTS_IMPORT extern i32 dxiIcon;

// 0x660F10 | ?dxiWidth@@3HA
ARTS_IMPORT extern i32 dxiWidth;

// 0x909668 | ?hwndMain@@3PAUHWND__@@A
ARTS_IMPORT extern struct HWND__* hwndMain;

// 0x909674 | ?lpClip@@3PAUIDirectDrawClipper@@A
ARTS_IMPORT extern struct IDirectDrawClipper* lpClip;

// 0x909660 | ?lpDD4@@3PAUIDirectDraw4@@A
ARTS_IMPORT extern struct IDirectDraw4* lpDD4;

// 0x90965C | ?lpDI@@3PAUIDirectInputA@@A
ARTS_IMPORT extern struct IDirectInputA* lpDI;

// 0x909670 | ?lpdsBack@@3PAUIDirectDrawSurface4@@A
ARTS_IMPORT extern struct IDirectDrawSurface4* lpdsBack;

// 0x909658 | ?lpdsBack2@@3PAUIDirectDrawSurface4@@A
ARTS_IMPORT extern struct IDirectDrawSurface4* lpdsBack2;

// 0x909664 | ?lpdsFront@@3PAUIDirectDrawSurface4@@A
ARTS_IMPORT extern struct IDirectDrawSurface4* lpdsFront;

// 0x909678 | ?lpdsRend@@3PAUIDirectDrawSurface4@@A
ARTS_IMPORT extern struct IDirectDrawSurface4* lpdsRend;
