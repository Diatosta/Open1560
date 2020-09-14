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

define_dummy_symbol(mmaudio_cd);

#include "cd.h"

#include "pcwindis/pcwindis.h"

CDMan::~CDMan()
{
    if (is_opened_)
    {
        mciSendCommandA(device_id_, MCI_STOP, MCI_WAIT, NULL);
        mciSendCommandA(device_id_, MCI_CLOSE, MCI_WAIT, NULL);
    }

    UnregisterMap("CD Player");
}

i16 CDMan::GetNumTracks()
{
    MCI_STATUS_PARMS status_params {};
    status_params.dwItem = MCI_STATUS_NUMBER_OF_TRACKS;

    if (mciSendCommandA(device_id_, MCI_STATUS, MCI_STATUS_ITEM, (DWORD_PTR) &status_params))
    {
        Errorf("Error getting number of tracks");
        mciSendCommandA(device_id_, MCI_CLOSE, MCI_WAIT, 0);
        return -1;
    }

    return static_cast<i16>(status_params.dwReturn);
}

MCIERROR CDMan::GetPosition(u8* track, u8* minute, u8* second, u8* frame)
{
    if (!is_opened_)
        return false;

    MCI_STATUS_PARMS status_params {};
    status_params.dwItem = MCI_STATUS_POSITION;

    if (mciSendCommandA(device_id_, MCI_STATUS, MCI_STATUS_ITEM, (DWORD_PTR) &status_params))
        return false;

    *track = MCI_TMSF_TRACK(status_params.dwReturn);
    *minute = MCI_TMSF_MINUTE(status_params.dwReturn);
    *second = MCI_TMSF_SECOND(status_params.dwReturn);
    *frame = MCI_TMSF_FRAME(status_params.dwReturn);

    return true;
}

MCIERROR CDMan::Init([[maybe_unused]] b16 close)
{
    if (is_opened_)
    {
        mciSendCommandA(device_id_, MCI_STOP, MCI_WAIT, NULL);
        mciSendCommandA(device_id_, MCI_CLOSE, MCI_WAIT, NULL);

        is_opened_ = false;
    }

    device_id_ = 0;

    current_track_ = 0;
    current_minute_ = 0;
    current_second_ = 0;
    current_frame_ = 0;

    {
        open_params_.lpstrDeviceType = (LPCSTR) MCI_DEVTYPE_CD_AUDIO;

        if (MCIERROR result = mciSendCommandA(0, MCI_OPEN, MCI_OPEN_TYPE | MCI_OPEN_TYPE_ID, (DWORD_PTR) &open_params_))
            return result;

        device_id_ = open_params_.wDeviceID;
    }

    {
        MCI_STATUS_PARMS status_params {};
        status_params.dwItem = MCI_STATUS_NUMBER_OF_TRACKS;

        if (MCIERROR result = mciSendCommandA(device_id_, MCI_STATUS, MCI_STATUS_ITEM, (DWORD_PTR) &status_params))
            return result;

        track_count_ = static_cast<u16>(status_params.dwReturn);
    }

    {
        MCI_SET_PARMS set_params {};
        set_params.dwTimeFormat = MCI_FORMAT_TMSF;

        if (MCIERROR result = mciSendCommandA(device_id_, MCI_SET, MCI_SET_TIME_FORMAT, (DWORD_PTR) &set_params))
            return result;
    }

    is_opened_ = true;

    return ERROR_SUCCESS;
}

MCIERROR CDMan::PlayTrack(u8 track, u8 restart)
{
    return PlayTrack(track, 0, 0, 0, restart);
}

MCIERROR CDMan::PlayTrack(u8 track, u8 minute, u8 second, u8 frame, u8 restart)
{
    if (track == current_track_ && !restart)
        return 0;

    if (!is_opened_)
        return 0;

    if (is_playing_)
    {
        if (mciSendCommandA(device_id_, MCI_STOP, 0, NULL))
            return 1;

        is_playing_ = false;
    }

    MCI_PLAY_PARMS play_params {};

    play_params.dwCallback = MAKELONG(window_, 0);
    play_params.dwFrom = MCI_MAKE_TMSF(track, minute, second, frame);
    DWORD play_flags = MCI_NOTIFY | MCI_FROM;

    if (track != track_count_)
    {
        play_params.dwTo = MCI_MAKE_TMSF(track + 1, 0, 0, 0);
        play_flags |= MCI_TO;
    }

    if (mciSendCommandA(device_id_, MCI_PLAY, play_flags, (DWORD_PTR) &play_params))
    {
        mciSendCommandA(device_id_, MCI_CLOSE, 0, NULL);
        is_playing_ = false;
        return 0;
    }

    is_playing_ = true;
    return 1;
}

MCIERROR CDMan::ResumePlay()
{
    return PlayTrack(current_track_, current_minute_, current_second_, current_frame_, true);
}

MCIERROR CDMan::SeekTrack(u8 track)
{
    if (!is_opened_)
        return false;

    current_track_ = track;

    MCI_SEEK_PARMS seek_params {};
    seek_params.dwTo = MCI_MAKE_TMSF(track + 1, 0, 0, 0);
    seek_params.dwCallback = MAKELONG(window_, 0);

    MCIERROR result = mciSendCommandA(device_id_, MCI_SEEK, MCI_NOTIFY | MCI_TO, (DWORD_PTR) &seek_params);

    if (result)
        mciSendCommandA(device_id_, MCI_CLOSE, MCI_WAIT, NULL);

    return result;
}

MCIERROR CDMan::Stop()
{
    GetPosition(&current_track_, &current_minute_, &current_second_, &current_frame_);
    is_playing_ = false;

    MCI_GENERIC_PARMS stop_params {};
    stop_params.dwCallback = MAKELONG(window_, 0);

    return mciSendCommandA(device_id_, MCI_STOP, MCI_NOTIFY, (DWORD_PTR) &stop_params);
}

LRESULT CDMan::WindowProc([[maybe_unused]] HWND hwnd, UINT uMsg, WPARAM wParam, [[maybe_unused]] LPARAM lParam)
{
    if (uMsg == MM_MCINOTIFY && wParam == MCI_NOTIFY_SUCCESSFUL)
    {
        is_playing_ = false;

        if (play_mode_ == 0)
        {
            PlayTrack(current_track_, true);
        }
        else if (play_mode_ == 1)
        {
            if (++current_track_ > track_count_)
                current_track_ = 1;

            PlayTrack(current_track_, true);
        }
    }

    return 0;
}
