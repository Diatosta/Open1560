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
    mmeffects:linespark

    0x501700 | class asSparkLut * __cdecl GetSparkLut(char *) | ?GetSparkLut@@YAPAVasSparkLut@@PAD@Z
    0x501740 | public: void __thiscall asSparkLut::Init(char *) | ?Init@asSparkLut@@QAEXPAD@Z
    0x501920 | public: void __thiscall asLineSparks::Init(int,class asSparkLut *) | ?Init@asLineSparks@@QAEXHPAVasSparkLut@@@Z
    0x501A10 | public: void __thiscall asLineSparks::AddWidgets(class Bank *) | ?AddWidgets@asLineSparks@@QAEXPAVBank@@@Z
    0x501C40 | public: void __thiscall asLineSparks::RadialBlast(int,class Vector3 &,class Vector3 &) | ?RadialBlast@asLineSparks@@QAEXHAAVVector3@@0@Z
    0x501F80 | public: void __thiscall asLineSparks::Update(void) | ?Update@asLineSparks@@QAEXXZ
    0x501FC0 | public: void __thiscall asLineSparks::Update(float) | ?Update@asLineSparks@@QAEXM@Z
    0x502190 | public: void __thiscall asLineSparks::Draw(void) | ?Draw@asLineSparks@@QAEXXZ
    0x64A0D8 | private: static unsigned int * asSparkLut::BuiltinClut | ?BuiltinClut@asSparkLut@@0PAIA
    0x719600 | class HashTable SLH | ?SLH@@3VHashTable@@A
*/

// 0x501700 | ?GetSparkLut@@YAPAVasSparkLut@@PAD@Z
class asSparkLut* GetSparkLut(char* arg1);

// 0x719600 | ?SLH@@3VHashTable@@A
inline extern_var(0x719600, class HashTable, SLH);

class asSparkLut
{
public:
    // 0x501740 | ?Init@asSparkLut@@QAEXPAD@Z
    void Init(char* arg1);

private:
    // 0x64A0D8 | ?BuiltinClut@asSparkLut@@0PAIA
    static inline extern_var(0x64A0D8, u32*, BuiltinClut);
};

check_size(asSparkLut, 0x0);

struct asLineSparks
{
public:
    // 0x501A10 | ?AddWidgets@asLineSparks@@QAEXPAVBank@@@Z
    void AddWidgets(class Bank* arg1);

    // 0x502190 | ?Draw@asLineSparks@@QAEXXZ
    void Draw();

    // 0x501920 | ?Init@asLineSparks@@QAEXHPAVasSparkLut@@@Z
    void Init(i32 arg1, class asSparkLut* arg2);

    // 0x501C40 | ?RadialBlast@asLineSparks@@QAEXHAAVVector3@@0@Z
    void RadialBlast(i32 arg1, class Vector3& arg2, class Vector3& arg3);

    // 0x501F80 | ?Update@asLineSparks@@QAEXXZ
    void Update();

    // 0x501FC0 | ?Update@asLineSparks@@QAEXM@Z
    void Update(f32 arg1);
};

check_size(asLineSparks, 0x0);
