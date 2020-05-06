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

define_dummy_symbol(mmcar_opponentcaraudio);

#include "opponentcaraudio.h"

mmOpponentCarAudio::mmOpponentCarAudio()
{
    unimplemented();
}

mmOpponentCarAudio::mmOpponentCarAudio(class mmCarSim* arg1)
{
    unimplemented(arg1);
}

mmOpponentCarAudio::~mmOpponentCarAudio()
{
    unimplemented(arg1);
}

void mmOpponentCarAudio::AssignSounds(
    class AudSound* arg1, class AudSound* arg2, class mmOpponentImpactAudio* arg3, class AudSound* arg4)
{
    return stub<thiscall_t<void, mmOpponentCarAudio*, class AudSound*, class AudSound*, class mmOpponentImpactAudio*,
        class AudSound*>>(0x47BF50, this, arg1, arg2, arg3, arg4);
}

void mmOpponentCarAudio::CalculateDistToPlayer2()
{
    return stub<thiscall_t<void, mmOpponentCarAudio*>>(0x47BC80, this);
}

void mmOpponentCarAudio::CalculateDoppler(f32 arg1)
{
    return stub<thiscall_t<void, mmOpponentCarAudio*, f32>>(0x47BDB0, this, arg1);
}

void mmOpponentCarAudio::CalculatePan()
{
    return stub<thiscall_t<void, mmOpponentCarAudio*>>(0x47BD60, this);
}

class MetaClass* mmOpponentCarAudio::GetClass()
{
    return stub<thiscall_t<class MetaClass*, mmOpponentCarAudio*>>(0x47C2A0, this);
}

void mmOpponentCarAudio::Init(class mmCarSim* arg1)
{
    return stub<thiscall_t<void, mmOpponentCarAudio*, class mmCarSim*>>(0x47BA30, this, arg1);
}

void mmOpponentCarAudio::LoadSucessful(class mmCarSim* arg1)
{
    return stub<thiscall_t<void, mmOpponentCarAudio*, class mmCarSim*>>(0x47BF20, this, arg1);
}

void mmOpponentCarAudio::PlayReverseBeep()
{
    return stub<thiscall_t<void, mmOpponentCarAudio*>>(0x47BB80, this);
}

void mmOpponentCarAudio::Reset()
{
    return stub<thiscall_t<void, mmOpponentCarAudio*>>(0x47BF00, this);
}

void mmOpponentCarAudio::SetMinAmpSpeed(f32 arg1)
{
    return stub<thiscall_t<void, mmOpponentCarAudio*, f32>>(0x47C0C0, this, arg1);
}

void mmOpponentCarAudio::UnAssignSounds()
{
    return stub<thiscall_t<void, mmOpponentCarAudio*>>(0x47C020, this);
}

void mmOpponentCarAudio::Update(i32 arg1, f32 arg2, f32 arg3)
{
    return stub<thiscall_t<void, mmOpponentCarAudio*, i32, f32, f32>>(0x47BBE0, this, arg1, arg2, arg3);
}

void mmOpponentCarAudio::UpdateDoppler()
{
    return stub<thiscall_t<void, mmOpponentCarAudio*>>(0x47BDE0, this);
}

void mmOpponentCarAudio::UpdateDoppler(f32 arg1)
{
    return stub<thiscall_t<void, mmOpponentCarAudio*, f32>>(0x47BDF0, this, arg1);
}

void mmOpponentCarAudio::DeclareFields()
{
    return stub<cdecl_t<void>>(0x47C0E0);
}
