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

#include "mutex.h"

#include "core/minwin.h"

Mutex::~Mutex()
{
    close();
}

void Mutex::init()
{
    if (handle_ == nullptr)
        handle_ = CreateMutexA(NULL, FALSE, NULL);
}

void Mutex::close()
{
    if (handle_)
    {
        CloseHandle(handle_);
        handle_ = nullptr;
    }
}

void Mutex::lock()
{
    WaitForSingleObject(handle_, INFINITE);
}

void Mutex::unlock()
{
    ReleaseMutex(handle_);
}