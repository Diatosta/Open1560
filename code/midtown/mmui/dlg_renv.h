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

#pragma once

/*
    mmui:dlg_renv

    0x49DC80 | public: __thiscall Dialog_RaceEnvironment::Dialog_RaceEnvironment(int,float,float,float,float,char *) | ??0Dialog_RaceEnvironment@@QAE@HMMMMPAD@Z
    0x49E290 | public: virtual __thiscall Dialog_RaceEnvironment::~Dialog_RaceEnvironment(void) | ??1Dialog_RaceEnvironment@@UAE@XZ
    0x49E2A0 | public: virtual void __thiscall Dialog_RaceEnvironment::PreSetup(void) | ?PreSetup@Dialog_RaceEnvironment@@UAEXXZ
    0x49E2F0 | public: void __thiscall Dialog_RaceEnvironment::ControlPedSlider(void) | ?ControlPedSlider@Dialog_RaceEnvironment@@QAEXXZ
    0x49E310 | public: void __thiscall Dialog_RaceEnvironment::SetMultiRaceOptions(int) | ?SetMultiRaceOptions@Dialog_RaceEnvironment@@QAEXH@Z
    0x49E350 | public: void __thiscall Dialog_RaceEnvironment::DoneCallback(void) | ?DoneCallback@Dialog_RaceEnvironment@@QAEXXZ
    0x49E3A0 | public: void __thiscall Dialog_RaceEnvironment::CancelCallback(void) | ?CancelCallback@Dialog_RaceEnvironment@@QAEXXZ
    0x49E3B0 | public: virtual void * __thiscall Dialog_RaceEnvironment::`vector deleting destructor'(unsigned int) | ??_EDialog_RaceEnvironment@@UAEPAXI@Z
    0x49E3B0 | public: virtual void * __thiscall Dialog_RaceEnvironment::`scalar deleting destructor'(unsigned int) | ??_GDialog_RaceEnvironment@@UAEPAXI@Z
    0x61D5A0 | const Dialog_RaceEnvironment::`vftable' | ??_7Dialog_RaceEnvironment@@6B@
*/

#include "pu_menu.h"

class Dialog_RaceEnvironment : public PUMenuBase
{
    // const Dialog_RaceEnvironment::`vftable' @ 0x61D5A0

public:
    // 0x49DC80 | ??0Dialog_RaceEnvironment@@QAE@HMMMMPAD@Z
    Dialog_RaceEnvironment(i32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, char* arg6);

    // 0x49E3B0 | ??_GDialog_RaceEnvironment@@UAEPAXI@Z
    // 0x49E290 | ??1Dialog_RaceEnvironment@@UAE@XZ
    ~Dialog_RaceEnvironment() override;

    // 0x49E3A0 | ?CancelCallback@Dialog_RaceEnvironment@@QAEXXZ | unused
    void CancelCallback();

    // 0x49E2F0 | ?ControlPedSlider@Dialog_RaceEnvironment@@QAEXXZ
    void ControlPedSlider();

    // 0x49E350 | ?DoneCallback@Dialog_RaceEnvironment@@QAEXXZ
    void DoneCallback();

    // 0x49E2A0 | ?PreSetup@Dialog_RaceEnvironment@@UAEXXZ
    void PreSetup() override;

    // 0x49E310 | ?SetMultiRaceOptions@Dialog_RaceEnvironment@@QAEXH@Z
    void SetMultiRaceOptions(i32 arg1);
};

check_size(Dialog_RaceEnvironment, 0xF0);
