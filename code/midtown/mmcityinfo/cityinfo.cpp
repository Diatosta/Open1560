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

define_dummy_symbol(mmcityinfo_cityinfo);

#include "cityinfo.h"

mmCityInfo::mmCityInfo()
{
    unimplemented();
}

mmCityInfo::~mmCityInfo()
{
    unimplemented(arg1);
}

i32 mmCityInfo::Load(char* arg1)
{
    return stub<thiscall_t<i32, mmCityInfo*, char*>>(0x4D3650, this, arg1);
}
