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
    mmeffects:mmnumber

    0x4FE660 | public: __thiscall mmNumberFont::mmNumberFont(void) | ??0mmNumberFont@@QAE@XZ
    0x4FE730 | public: __thiscall mmNumberFont::~mmNumberFont(void) | ??1mmNumberFont@@QAE@XZ
    0x4FE780 | public: void __thiscall mmNumberFont::LoadFont(char *,int,unsigned int) | ?LoadFont@mmNumberFont@@QAEXPADHI@Z
    0x4FE880 | public: void __thiscall mmNumberFont::LoadLocFont(char *,struct LocString *,int,unsigned int) | ?LoadLocFont@mmNumberFont@@QAEXPADPAULocString@@HI@Z
    0x4FEA10 | public: __thiscall mmNumber::mmNumber(void) | ??0mmNumber@@QAE@XZ
    0x4FEAA0 | public: virtual __thiscall mmNumber::~mmNumber(void) | ??1mmNumber@@UAE@XZ
    0x4FEAB0 | public: void __thiscall mmNumber::Init(class mmNumberFont *,float,float) | ?Init@mmNumber@@QAEXPAVmmNumberFont@@MM@Z
    0x4FEB20 | public: void __thiscall mmNumber::SetString(char *) | ?SetString@mmNumber@@QAEXPAD@Z
    0x4FEB50 | public: void __cdecl mmNumber::Printf(char const *,...) | ?Printf@mmNumber@@QAAXPBDZZ
    0x4FEB70 | public: virtual void __thiscall mmNumber::Update(void) | ?Update@mmNumber@@UAEXXZ
    0x4FEB90 | public: virtual void __thiscall mmNumber::Cull(void) | ?Cull@mmNumber@@UAEXXZ
    0x4FECA0 | public: virtual void __thiscall mmNumber::AddWidgets(class Bank *) | ?AddWidgets@mmNumber@@UAEXPAVBank@@@Z
    0x4FECB0 | public: static void __cdecl mmNumber::DeclareFields(void) | ?DeclareFields@mmNumber@@SAXXZ
    0x4FEE20 | public: virtual class MetaClass * __thiscall mmNumber::GetClass(void) | ?GetClass@mmNumber@@UAEPAVMetaClass@@XZ
    0x620618 | const mmNumber::`vftable' | ??_7mmNumber@@6B@
    0x649C9C | char * NUMBERSTRING | ?NUMBERSTRING@@3PADA
    0x719570 | class MetaClass mmNumberMetaClass | ?mmNumberMetaClass@@3VMetaClass@@A
*/

#include "arts7/node.h"

class mmNumber final : public asNode
{
    // const mmNumber::`vftable' @ 0x620618

public:
    // 0x4FEA10 | ??0mmNumber@@QAE@XZ
    ARTS_IMPORT mmNumber();

    // 0x4262A0 | ??_EmmNumber@@UAEPAXI@Z
    // 0x4FEAA0 | ??1mmNumber@@UAE@XZ
    ARTS_IMPORT ~mmNumber() override = default;

    // 0x4FECA0 | ?AddWidgets@mmNumber@@UAEXPAVBank@@@Z
    ARTS_EXPORT void AddWidgets(class Bank* arg1) override;

    // 0x4FEB90 | ?Cull@mmNumber@@UAEXXZ
    ARTS_IMPORT void Cull() override;

    // 0x4FEE20 | ?GetClass@mmNumber@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT class MetaClass* GetClass() override;

    // 0x4FEAB0 | ?Init@mmNumber@@QAEXPAVmmNumberFont@@MM@Z
    ARTS_IMPORT void Init(class mmNumberFont* arg1, f32 arg2, f32 arg3);

    // 0x4FEB50 | ?Printf@mmNumber@@QAAXPBDZZ
    ARTS_IMPORT void Printf(char const* arg1, ...);

    // 0x4FEB20 | ?SetString@mmNumber@@QAEXPAD@Z
    ARTS_IMPORT void SetString(char* arg1);

    // 0x4FEB70 | ?Update@mmNumber@@UAEXXZ
    ARTS_IMPORT void Update() override;

    // 0x4FECB0 | ?DeclareFields@mmNumber@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

    u8 gap20[0x60];
};

check_size(mmNumber, 0x80);

class mmNumberFont
{
public:
    // 0x4FE660 | ??0mmNumberFont@@QAE@XZ
    ARTS_IMPORT mmNumberFont();

    // 0x4FE730 | ??1mmNumberFont@@QAE@XZ
    ARTS_IMPORT ~mmNumberFont();

    // 0x4FE780 | ?LoadFont@mmNumberFont@@QAEXPADHI@Z
    ARTS_IMPORT void LoadFont(char* arg1, i32 arg2, u32 arg3);

    // 0x4FE880 | ?LoadLocFont@mmNumberFont@@QAEXPADPAULocString@@HI@Z
    ARTS_IMPORT void LoadLocFont(char* arg1, struct LocString* arg2, i32 arg3, u32 arg4);

    u8 gap0[0x24];
};

check_size(mmNumberFont, 0x24);

// 0x649C9C | ?NUMBERSTRING@@3PADA
ARTS_IMPORT extern char* NUMBERSTRING;

// 0x719570 | ?mmNumberMetaClass@@3VMetaClass@@A
// ARTS_IMPORT extern class MetaClass mmNumberMetaClass;
