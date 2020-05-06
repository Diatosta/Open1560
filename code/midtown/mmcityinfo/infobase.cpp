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

define_dummy_symbol(mmcityinfo_infobase);

#include "infobase.h"

mmInfoBase::mmInfoBase()
{
    unimplemented();
}

mmInfoBase::~mmInfoBase()
{
    unimplemented(arg1);
}

class MetaClass* mmInfoBase::GetClass()
{
    return stub<thiscall_t<class MetaClass*, mmInfoBase*>>(0x4D15D0, this);
}

i32 mmInfoBase::Load(char* arg1)
{
    return stub<thiscall_t<i32, mmInfoBase*, char*>>(0x4D12E0, this, arg1);
}

i32 mmInfoBase::Save(char* arg1)
{
    return stub<thiscall_t<i32, mmInfoBase*, char*>>(0x4D1390, this, arg1);
}

void mmInfoBase::SetIOPath(char* arg1)
{
    return stub<thiscall_t<void, mmInfoBase*, char*>>(0x4D1440, this, arg1);
}

void mmInfoBase::DeclareFields()
{
    return stub<cdecl_t<void>>(0x4D1460);
}
