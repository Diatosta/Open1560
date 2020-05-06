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

define_dummy_symbol(mmgame_wpinst);

#include "wpinst.h"

mmWaypointInstance::mmWaypointInstance(i32 arg1, f32 arg2, f32 arg3)
{
    unimplemented(arg1, arg2, arg3);
}

mmWaypointInstance::~mmWaypointInstance()
{
    unimplemented(arg1);
}

void mmWaypointInstance::AddWidgets(class Bank* arg1)
{
    return stub<thiscall_t<void, mmWaypointInstance*, class Bank*>>(0x433B90, this, arg1);
}

i32 mmWaypointInstance::ComputeLod(f32 arg1, f32 arg2)
{
    return stub<thiscall_t<i32, mmWaypointInstance*, f32, f32>>(0x4337A0, this, arg1, arg2);
}

void __fastcall mmWaypointInstance::Draw(i32 arg1)
{
    return stub<fastcall_t<void, mmWaypointInstance*, i32>>(0x4337C0, this, arg1);
}

class MetaClass* mmWaypointInstance::GetClass()
{
    return stub<thiscall_t<class MetaClass*, mmWaypointInstance*>>(0x433D20, this);
}

f32 __fastcall mmWaypointInstance::GetScale()
{
    return stub<fastcall_t<f32, mmWaypointInstance*>>(0x433790, this);
}

void mmWaypointInstance::DeclareFields()
{
    return stub<cdecl_t<void>>(0x433BA0);
}
