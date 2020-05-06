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

define_dummy_symbol(mmcityinfo_racedata);

#include "racedata.h"

mmRaceData::mmRaceData()
{
    unimplemented();
}

mmRaceData::~mmRaceData()
{
    unimplemented();
}

f32 mmRaceData::GetAmbientDensity(i32 arg1, enum mmSkillLevel arg2)
{
    return stub<thiscall_t<f32, mmRaceData*, i32, enum mmSkillLevel>>(0x4D2100, this, arg1, arg2);
}

i32 mmRaceData::GetCarType(i32 arg1, enum mmSkillLevel arg2)
{
    return stub<thiscall_t<i32, mmRaceData*, i32, enum mmSkillLevel>>(0x4D1F80, this, arg1, arg2);
}

f32 mmRaceData::GetDifficulty(i32 arg1, enum mmSkillLevel arg2)
{
    return stub<thiscall_t<f32, mmRaceData*, i32, enum mmSkillLevel>>(0x4D2130, this, arg1, arg2);
}

i32 mmRaceData::GetNumCops(i32 arg1, enum mmSkillLevel arg2)
{
    return stub<thiscall_t<i32, mmRaceData*, i32, enum mmSkillLevel>>(0x4D2040, this, arg1, arg2);
}

i32 mmRaceData::GetNumLaps(i32 arg1, enum mmSkillLevel arg2)
{
    return stub<thiscall_t<i32, mmRaceData*, i32, enum mmSkillLevel>>(0x4D1FB0, this, arg1, arg2);
}

i32 mmRaceData::GetNumOpponents(i32 arg1, enum mmSkillLevel arg2)
{
    return stub<thiscall_t<i32, mmRaceData*, i32, enum mmSkillLevel>>(0x4D2010, this, arg1, arg2);
}

i32 mmRaceData::GetNumRaces()
{
    return stub<thiscall_t<i32, mmRaceData*>>(0x4D1F60, this);
}

f32 mmRaceData::GetPedDensity(i32 arg1, enum mmSkillLevel arg2)
{
    return stub<thiscall_t<f32, mmRaceData*, i32, enum mmSkillLevel>>(0x4D20D0, this, arg1, arg2);
}

char* mmRaceData::GetRaceName(i32 arg1)
{
    return stub<thiscall_t<char*, mmRaceData*, i32>>(0x4D1F70, this, arg1);
}

f32 mmRaceData::GetTimeLimit(i32 arg1, enum mmSkillLevel arg2)
{
    return stub<thiscall_t<f32, mmRaceData*, i32, enum mmSkillLevel>>(0x4D1FE0, this, arg1, arg2);
}

i32 mmRaceData::GetTimeOfDay(i32 arg1, enum mmSkillLevel arg2)
{
    return stub<thiscall_t<i32, mmRaceData*, i32, enum mmSkillLevel>>(0x4D2070, this, arg1, arg2);
}

i32 mmRaceData::GetWeather(i32 arg1, enum mmSkillLevel arg2)
{
    return stub<thiscall_t<i32, mmRaceData*, i32, enum mmSkillLevel>>(0x4D20A0, this, arg1, arg2);
}

i32 mmRaceData::Load(char* arg1)
{
    return stub<thiscall_t<i32, mmRaceData*, char*>>(0x4D1BE0, this, arg1);
}
