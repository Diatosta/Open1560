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

define_dummy_symbol(mmai_aiPoliceForce);

#include "aiPoliceForce.h"

aiPoliceForce::aiPoliceForce()
{
    unimplemented();
}

aiPoliceForce::~aiPoliceForce()
{
    unimplemented();
}

i32 aiPoliceForce::Find(class mmCar* arg1, class mmCar* arg2)
{
    return stub<thiscall_t<i32, aiPoliceForce*, class mmCar*, class mmCar*>>(0x44E860, this, arg1, arg2);
}

i32 aiPoliceForce::RegisterPerp(class mmCar* arg1, class mmCar* arg2)
{
    return stub<thiscall_t<i32, aiPoliceForce*, class mmCar*, class mmCar*>>(0x44E8D0, this, arg1, arg2);
}

void aiPoliceForce::Reset()
{
    return stub<thiscall_t<void, aiPoliceForce*>>(0x44E810, this);
}

i32 aiPoliceForce::State(class mmCar* arg1, class mmCar* arg2, f32 arg3)
{
    return stub<thiscall_t<i32, aiPoliceForce*, class mmCar*, class mmCar*, f32>>(0x44EA60, this, arg1, arg2, arg3);
}

i32 aiPoliceForce::UnRegisterCop(class mmCar* arg1, class mmCar* arg2)
{
    return stub<thiscall_t<i32, aiPoliceForce*, class mmCar*, class mmCar*>>(0x44E970, this, arg1, arg2);
}

void aiPoliceForce::Update()
{
    return stub<thiscall_t<void, aiPoliceForce*>>(0x44E850, this);
}
