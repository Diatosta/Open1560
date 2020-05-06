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
    vector7:vector4

    0x56DBA0 | public: float __thiscall Vector4::Mag(void) const | ?Mag@Vector4@@QBEMXZ
    0x56DC70 | public: class Vector4 __thiscall Vector4::operator/(float) const | ??KVector4@@QBE?AV0@M@Z
    0x56DD00 | public: class Vector4 __thiscall Vector4::operator!(void) const | ??7Vector4@@QBE?AV0@XZ
    0x56DD80 | public: void __thiscall Vector4::Bilinear(float,float,class Vector4 const &,class Vector4 const &,class Vector4 const &,class Vector4 const &) | ?Bilinear@Vector4@@QAEXMMABV1@000@Z
    0x56DDD0 | public: void __thiscall Vector4::CalculatePlane(class Vector3 const &,class Vector3 const &,class Vector3 const &) | ?CalculatePlane@Vector4@@QAEXABVVector3@@00@Z
    0x56DED0 | public: void __thiscall Vector4::GetLookAt(class Vector3 const &,class Vector3 *,class Vector3 *) const | ?GetLookAt@Vector4@@QBEXABVVector3@@PAV2@1@Z
    0x56DF50 | public: void __thiscall Vector4::Lerp(float,class Vector4 const &,class Vector4 const &) | ?Lerp@Vector4@@QAEXMABV1@0@Z
    0x56E040 | public: void __thiscall Vector4Array::Init(int) | ?Init@Vector4Array@@QAEXH@Z
    0x56E0B0 | public: void __thiscall Vector4Array::Delete(void) | ?Delete@Vector4Array@@QAEXXZ
    0x56E100 | private: void __thiscall Vector4Array::NewTable(int) | ?NewTable@Vector4Array@@AAEXH@Z
    0x56E170 | public: class Vector4 & __thiscall Vector4Array::operator[](int) | ??AVector4Array@@QAEAAVVector4@@H@Z
    0x56E1F0 | public: void __thiscall Vector4Array::operator=(class Vector4Array &) | ??4Vector4Array@@QAEXAAV0@@Z
    0x56E2F0 | public: void __thiscall Vector4Array::BlockCopy(class Vector4Array &) | ?BlockCopy@Vector4Array@@QAEXAAV1@@Z
    0x56E3F0 | public: virtual void __thiscall Vector4Type::Save(class MiniParser *,void *) | ?Save@Vector4Type@@UAEXPAVMiniParser@@PAX@Z
    0x56E430 | public: virtual void __thiscall Vector4Type::Load(class MiniParser *,void *) | ?Load@Vector4Type@@UAEXPAVMiniParser@@PAX@Z
    0x56E470 | public: virtual unsigned int __thiscall Vector4Type::SizeOf(void) | ?SizeOf@Vector4Type@@UAEIXZ
    0x56E480 | public: virtual void * __thiscall Vector4Type::New(int) | ?New@Vector4Type@@UAEPAXH@Z
    0x56E4D0 | public: virtual void __thiscall Vector4Type::Delete(void *,int) | ?Delete@Vector4Type@@UAEXPAXH@Z
    0x621C38 | const Vector4Type::`vftable' | ??_7Vector4Type@@6B@
    0x9094EC | struct Vector4Type Vector4Inst | ?Vector4Inst@@3UVector4Type@@A
*/

#include "data7/metatype.h"

class Vector4
{
public:
    // 0x56DD00 | ??7Vector4@@QBE?AV0@XZ
    class Vector4 operator!();

    // 0x56DC70 | ??KVector4@@QBE?AV0@M@Z
    class Vector4 operator/(f32 arg1);

    // 0x570D70 | ??TVector4@@QBEMABV0@@Z
    f32 operator^(class Vector4 const& arg1);

    // 0x56DD80 | ?Bilinear@Vector4@@QAEXMMABV1@000@Z
    void Bilinear(f32 arg1, f32 arg2, class Vector4 const& arg3, class Vector4 const& arg4, class Vector4 const& arg5,
        class Vector4 const& arg6);

    // 0x56DDD0 | ?CalculatePlane@Vector4@@QAEXABVVector3@@00@Z
    void CalculatePlane(class Vector3 const& arg1, class Vector3 const& arg2, class Vector3 const& arg3);

    // 0x56DED0 | ?GetLookAt@Vector4@@QBEXABVVector3@@PAV2@1@Z
    void GetLookAt(class Vector3 const& arg1, class Vector3* arg2, class Vector3* arg3);

    // 0x56DF50 | ?Lerp@Vector4@@QAEXMABV1@0@Z
    void Lerp(f32 arg1, class Vector4 const& arg2, class Vector4 const& arg3);

    // 0x56DBA0 | ?Mag@Vector4@@QBEMXZ
    f32 Mag();

    // 0x570D50 | ?Set@Vector4@@QAEXMMMM@Z
    void Set(f32 arg1, f32 arg2, f32 arg3, f32 arg4);
};

check_size(Vector4, 0x0);

class Vector4Array
{
public:
    // 0x56E1F0 | ??4Vector4Array@@QAEXAAV0@@Z
    void operator=(class Vector4Array& arg1);

    // 0x56E170 | ??AVector4Array@@QAEAAVVector4@@H@Z
    class Vector4& operator[](i32 arg1);

    // 0x56E2F0 | ?BlockCopy@Vector4Array@@QAEXAAV1@@Z
    void BlockCopy(class Vector4Array& arg1);

    // 0x56E0B0 | ?Delete@Vector4Array@@QAEXXZ
    void Delete();

    // 0x56E040 | ?Init@Vector4Array@@QAEXH@Z
    void Init(i32 arg1);

private:
    // 0x56E100 | ?NewTable@Vector4Array@@AAEXH@Z
    void NewTable(i32 arg1);
};

check_size(Vector4Array, 0x0);

struct Vector4Type : MetaType
{
    // const Vector4Type::`vftable' @ 0x621C38

public:
    // 0x56E4D0 | ?Delete@Vector4Type@@UAEXPAXH@Z
    void Delete(void* arg1, i32 arg2) override;

    // 0x56E430 | ?Load@Vector4Type@@UAEXPAVMiniParser@@PAX@Z
    void Load(class MiniParser* arg1, void* arg2) override;

    // 0x56E480 | ?New@Vector4Type@@UAEPAXH@Z
    void* New(i32 arg1) override;

    // 0x56E3F0 | ?Save@Vector4Type@@UAEXPAVMiniParser@@PAX@Z
    void Save(class MiniParser* arg1, void* arg2) override;

    // 0x56E470 | ?SizeOf@Vector4Type@@UAEIXZ
    u32 SizeOf() override;
};

check_size(Vector4Type, 0x0);

// 0x9094EC | ?Vector4Inst@@3UVector4Type@@A
inline extern_var(0x9094EC, struct Vector4Type, Vector4Inst);
