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

define_dummy_symbol(midtown);

#include "midtown.h"

void Application(i32 arg1, char** arg2)
{
    return stub<cdecl_t<void, i32, char**>>(0x4030C0, arg1, arg2);
}

void ApplicationHelper(i32 arg1, char** arg2)
{
    return stub<cdecl_t<void, i32, char**>>(0x401830, arg1, arg2);
}

class agiPipeline* CreatePipeline(i32 arg1, char** arg2)
{
    return stub<cdecl_t<class agiPipeline*, i32, char**>>(0x4010B0, arg1, arg2);
}

i32 GameFilter(struct _EXCEPTION_POINTERS* arg1)
{
    return stub<cdecl_t<i32, struct _EXCEPTION_POINTERS*>>(0x4014B0, arg1);
}

void GameLoop(class mmInterface* arg1, class mmGameManager* arg2, char* arg3)
{
    return stub<cdecl_t<void, class mmInterface*, class mmGameManager*, char*>>(0x4015A0, arg1, arg2, arg3);
}

i32 GenerateLoadScreenName()
{
    return stub<cdecl_t<i32>>(0x4012D0);
}

void InitAudioManager()
{
    return stub<cdecl_t<void>>(0x402F40);
}
