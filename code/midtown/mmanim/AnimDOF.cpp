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

define_dummy_symbol(mmanim_AnimDOF);

#include "AnimDOF.h"

mmDrawbridgeInstance::~mmDrawbridgeInstance()
{
    unimplemented(arg1);
}

void __fastcall mmDrawbridgeInstance::Draw(i32 arg1)
{
    return stub<fastcall_t<void, mmDrawbridgeInstance*, i32>>(0x4C4460, this, arg1);
}

i32 mmDrawbridgeInstance::InitBridge(char* arg1, char* arg2, i32 arg3, class Matrix34* arg4, class Vector3* arg5)
{
    return stub<thiscall_t<i32, mmDrawbridgeInstance*, char*, char*, i32, class Matrix34*, class Vector3*>>(
        0x4C4510, this, arg1, arg2, arg3, arg4, arg5);
}

mmAnimDOF::mmAnimDOF()
{
    unimplemented();
}

mmAnimDOF::~mmAnimDOF()
{
    unimplemented();
}

class MetaClass* mmAnimDOF::GetClass()
{
    return stub<thiscall_t<class MetaClass*, mmAnimDOF*>>(0x4C4D80, this);
}

i32 mmAnimDOF::Init(
    class mmAnimTrigger* arg1, char* arg2, class Vector3& arg3, class Vector3& arg4, i32 arg5, i32* arg6)
{
    return stub<thiscall_t<i32, mmAnimDOF*, class mmAnimTrigger*, char*, class Vector3&, class Vector3&, i32, i32*>>(
        0x4C4580, this, arg1, arg2, arg3, arg4, arg5, arg6);
}

void mmAnimDOF::Reset()
{
    return stub<thiscall_t<void, mmAnimDOF*>>(0x4C4900, this);
}

void mmAnimDOF::SetState(i32 arg1)
{
    return stub<thiscall_t<void, mmAnimDOF*, i32>>(0x4C4BB0, this, arg1);
}

void mmAnimDOF::SetSwitch(i32 arg1)
{
    return stub<thiscall_t<void, mmAnimDOF*, i32>>(0x4C4B60, this, arg1);
}

void mmAnimDOF::Update()
{
    return stub<thiscall_t<void, mmAnimDOF*>>(0x4C4940, this);
}

void mmAnimDOF::DeclareFields()
{
    return stub<cdecl_t<void>>(0x4C4BF0);
}

mmDofBangerInstance::~mmDofBangerInstance()
{
    unimplemented(arg1);
}

void __fastcall mmDofBangerInstance::FromMatrix(class Matrix34 const& arg1)
{
    return stub<fastcall_t<void, mmDofBangerInstance*, class Matrix34 const&>>(0x4C4E50, this, arg1);
}

class Vector3& __fastcall mmDofBangerInstance::GetPos()
{
    return stub<fastcall_t<class Vector3&, mmDofBangerInstance*>>(0x4C4E90, this);
}

i32 mmDofBangerInstance::Init(char* arg1, char* arg2, i32 arg3, class Matrix34* arg4, class Vector3* arg5)
{
    return stub<thiscall_t<i32, mmDofBangerInstance*, char*, char*, i32, class Matrix34*, class Vector3*>>(
        0x4CB7E0, this, arg1, arg2, arg3, arg4, arg5);
}

u32 mmDofBangerInstance::SizeOf()
{
    return stub<thiscall_t<u32, mmDofBangerInstance*>>(0x4CB7D0, this);
}

class Matrix34& __fastcall mmDofBangerInstance::ToMatrix(class Matrix34& arg1)
{
    return stub<fastcall_t<class Matrix34&, mmDofBangerInstance*, class Matrix34&>>(0x4C4E60, this, arg1);
}
