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
    mmcityinfo:vehinfo

    0x4D39D0 | public: __thiscall mmVehInfo::mmVehInfo(void) | ??0mmVehInfo@@QAE@XZ
    0x4D39F0 | public: virtual __thiscall mmVehInfo::~mmVehInfo(void) | ??1mmVehInfo@@UAE@XZ
    0x4D3A00 | public: int __thiscall mmVehInfo::Load(char *) | ?Load@mmVehInfo@@QAEHPAD@Z
    0x4D3BE0 | public: int __thiscall mmVehInfo::HasColorVariations(void) | ?HasColorVariations@mmVehInfo@@QAEHXZ
    0x4D3C00 | public: void __thiscall mmVehInfo::Print(void) | ?Print@mmVehInfo@@QAEXXZ
    0x4D3C90 | public: virtual void * __thiscall mmVehInfo::`scalar deleting destructor'(unsigned int) | ??_GmmVehInfo@@UAEPAXI@Z
    0x4D3C90 | public: virtual void * __thiscall mmVehInfo::`vector deleting destructor'(unsigned int) | ??_EmmVehInfo@@UAEPAXI@Z
    0x61F948 | const mmVehInfo::`vftable' | ??_7mmVehInfo@@6B@
*/

class mmVehInfo
{
    // const mmVehInfo::`vftable' @ 0x61F948

public:
    // 0x4D39D0 | ??0mmVehInfo@@QAE@XZ
    mmVehInfo();

    // 0x4D3C90 | ??_EmmVehInfo@@UAEPAXI@Z
    // 0x4D39F0 | ??1mmVehInfo@@UAE@XZ
    virtual ~mmVehInfo();

    // 0x4D3BE0 | ?HasColorVariations@mmVehInfo@@QAEHXZ | unused
    i32 HasColorVariations();

    // 0x49C590 | ?IsValid@mmVehInfo@@QAEHXZ | inline
    i32 IsValid();

    // 0x4D3A00 | ?Load@mmVehInfo@@QAEHPAD@Z
    i32 Load(char* arg1);

    // 0x4D3C00 | ?Print@mmVehInfo@@QAEXXZ
    void Print();
};

check_size(mmVehInfo, 0xF8);
