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

define_dummy_symbol(mmui_pu_control);

#include "pu_control.h"

PUControl::PUControl(i32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5)
{
    unimplemented(arg1, arg2, arg3, arg4, arg5);
}

PUControl::~PUControl()
{
    unimplemented(arg1);
}

void PUControl::CancelAction()
{
    return stub<thiscall_t<void, PUControl*>>(0x4AA2D0, this);
}

void PUControl::ControlSelect()
{
    return stub<thiscall_t<void, PUControl*>>(0x4AA380, this);
}

void PUControl::PreSetup()
{
    return stub<thiscall_t<void, PUControl*>>(0x4AA2B0, this);
}

void PUControl::SetRWStates()
{
    return stub<thiscall_t<void, PUControl*>>(0x4AA2F0, this);
}

void PUControl::SetSensitivityCB()
{
    return stub<thiscall_t<void, PUControl*>>(0x4AA3B0, this);
}
