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

define_dummy_symbol(stream_fsystem);

#include "fsystem.h"

FileSystem::FileSystem()
{
    unimplemented();
}

FileSystem::~FileSystem()
{
    unimplemented(arg1);
}

i32 FileSystem::ValidPath(char* arg1)
{
    return stub<thiscall_t<i32, FileSystem*, char*>>(0x - 400000_Offset, this, arg1);
}

i32 FileSystem::QueryOn(char* arg1)
{
    return stub<thiscall_t<i32, FileSystem*, char*>>(0x - 400000_Offset, this, arg1);
}

class Stream* FileSystem::OpenOn(char* arg1, i32 arg2, void* arg3, i32 arg4)
{
    return stub<thiscall_t<class Stream*, FileSystem*, char*, i32, void*, i32>>(
        0x - 400000_Offset, this, arg1, arg2, arg3, arg4);
}

class Stream* FileSystem::CreateOn(char* arg1, void* arg2, i32 arg3)
{
    return stub<thiscall_t<class Stream*, FileSystem*, char*, void*, i32>>(0x - 400000_Offset, this, arg1, arg2, arg3);
}

i32 FileSystem::PagerInfo(char* arg1, struct PagerInfo_t& arg2)
{
    return stub<thiscall_t<i32, FileSystem*, char*, struct PagerInfo_t&>>(0x55FEC0, this, arg1, arg2);
}

i32 FileSystem::ChangeDir(char* arg1)
{
    return stub<thiscall_t<i32, FileSystem*, char*>>(0x - 400000_Offset, this, arg1);
}

i32 FileSystem::GetDir(char* arg1, i32 arg2)
{
    return stub<thiscall_t<i32, FileSystem*, char*, i32>>(0x - 400000_Offset, this, arg1, arg2);
}

struct FileInfo* FileSystem::FirstEntry(char* arg1)
{
    return stub<thiscall_t<struct FileInfo*, FileSystem*, char*>>(0x - 400000_Offset, this, arg1);
}

struct FileInfo* FileSystem::NextEntry(struct FileInfo* arg1)
{
    return stub<thiscall_t<struct FileInfo*, FileSystem*, struct FileInfo*>>(0x - 400000_Offset, this, arg1);
}

void FileSystem::NotifyDelete()
{
    return stub<thiscall_t<void, FileSystem*>>(0x55F610, this);
}

i32 FileSystem::Search(char* arg1, char* arg2, char* arg3, i32 arg4, char* arg5)
{
    return stub<thiscall_t<i32, FileSystem*, char*, char*, char*, i32, char*>>(
        0x55F690, this, arg1, arg2, arg3, arg4, arg5);
}

class Stream* FileSystem::OpenAny(char* arg1, i32 arg2, void* arg3, i32 arg4)
{
    return stub<cdecl_t<class Stream*, char*, i32, void*, i32>>(0x55FE60, arg1, arg2, arg3, arg4);
}

i32 FileSystem::PagerInfoAny(char* arg1, struct PagerInfo_t& arg2)
{
    return stub<cdecl_t<i32, char*, struct PagerInfo_t&>>(0x55FED0, arg1, arg2);
}

class FileSystem* FileSystem::SearchAll(char* arg1, char* arg2, char* arg3, i32 arg4, char* arg5)
{
    return stub<cdecl_t<class FileSystem*, char*, char*, char*, i32, char*>>(0x55F620, arg1, arg2, arg3, arg4, arg5);
}

class FileSystem* FindFile(char* arg1, char* arg2, char* arg3, i32 arg4, char* arg5)
{
    return stub<cdecl_t<class FileSystem*, char*, char*, char*, i32, char*>>(0x55FD30, arg1, arg2, arg3, arg4, arg5);
}

class Stream* OpenFile(char* arg1, char* arg2, char* arg3, i32 arg4, char* arg5, char* arg6)
{
    return stub<cdecl_t<class Stream*, char*, char*, char*, i32, char*, char*>>(
        0x55FD60, arg1, arg2, arg3, arg4, arg5, arg6);
}
