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

define_dummy_symbol(mmai_aiGoalAvoidPlayer);

#include "aiGoalAvoidPlayer.h"

aiGoalAvoidPlayer::aiGoalAvoidPlayer(class aiRailSet* arg1, class aiVehicleAmbient* arg2)
{
    unimplemented(arg1, arg2);
}

aiGoalAvoidPlayer::~aiGoalAvoidPlayer()
{
    unimplemented();
}

void aiGoalAvoidPlayer::Init()
{
    return stub<thiscall_t<void, aiGoalAvoidPlayer*>>(0x46A3B0, this);
}

void aiGoalAvoidPlayer::Reset()
{
    return stub<thiscall_t<void, aiGoalAvoidPlayer*>>(0x46A3C0, this);
}

i32 aiGoalAvoidPlayer::Context()
{
    return stub<thiscall_t<i32, aiGoalAvoidPlayer*>>(0x46A970, this);
}

i32 aiGoalAvoidPlayer::Priority()
{
    return stub<thiscall_t<i32, aiGoalAvoidPlayer*>>(0x46A990, this);
}

void aiGoalAvoidPlayer::Update()
{
    return stub<thiscall_t<void, aiGoalAvoidPlayer*>>(0x46A530, this);
}

void aiGoalAvoidPlayer::Dump()
{
    return stub<thiscall_t<void, aiGoalAvoidPlayer*>>(0x46A9A0, this);
}

void aiGoalAvoidPlayer::AvoidPlayer()
{
    return stub<thiscall_t<void, aiGoalAvoidPlayer*>>(0x46A700, this);
}
