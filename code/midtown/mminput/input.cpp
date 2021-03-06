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

define_dummy_symbol(mminput_input);

#include "input.h"

#include "eventq7/eventq.h"
#include "eventq7/key_codes.h"

i32 mmInput::GamepadConnected()
{
    return 0;
}

i32 mmInput::JoystickConnected()
{
    return 0;
}

i32 mmInput::WheelConnected()
{
    return 0;
}

b32 mmInput::GetNextKeyboardEvent(eqEvent* event)
{
    if (NumKeyboardInputs == 0)
        return false;

    event->Key = {{nullptr, eqEventType::Keyboard}, EQ_KMOD_DOWN, KeyboardPresses[--NumKeyboardInputs], 0, 0};

    return true;
}
