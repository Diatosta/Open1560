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

define_dummy_symbol(stream_stream);

#include "stream.h"

#include "fsystem.h"

#include "core/endian.h"

Stream::Stream(void* buffer, i32 buffer_size, class FileSystem* file_system)
    : buffer_(static_cast<u8*>(buffer))
    , buffer_capacity_(buffer_size)
    , file_system_(file_system)
    , little_endian_(true)
{
    export_hook(0x55E8B0);

    if (buffer_ == nullptr && buffer_capacity_ != 0)
    {
        buffer_ = new u8[buffer_capacity_];
        flags_ |= 0x1;
    }

    swap_endian_ = little_endian_;

    initialized_ = true;
}

Stream::~Stream()
{
    export_hook(0x55E940);

    // FIXME: If the file actually requires flushing, this will result in purecalls
    Flush();

    if (file_system_)
        file_system_->NotifyDelete();

    if (flags_ & 0x1)
        delete[] buffer_;

    buffer_ = nullptr;
    initialized_ = false;
}

void* Stream::GetMapping()
{
    return nullptr;
}

// TODO: Use usize/void*
u32 Stream::GetPagerHandle()
{
    return 0;
}

b32 Stream::GetPagingInfo(u32&, u32&, u32&)
{
    return false;
}

void Stream::Debug()
{}

void Stream::Error(const char* msg)
{
    char buffer[128];
    GetError(buffer, std::size(buffer));
    Errorf("%s: %s", msg, buffer);
}

i32 Stream::Flush()
{
    i32 count = 0;

    if (buffer_read_)
    {
        if (buffer_head_ != buffer_read_)
            count = RawSeek(position_ + buffer_head_);
    }
    else if (buffer_head_)
    {
        count = RawWrite(buffer_, buffer_head_);
    }

    position_ += buffer_head_;
    buffer_read_ = 0;
    buffer_head_ = 0;

    if (count == -1)
        Error("Stream::Flush()");

    return count;
}

i32 Stream::Get(u16* values, i32 count)
{
    export_hook(0x55F190);

    count = Read(values, count * sizeof(*values)) / sizeof(*values);

    if (swap_endian_)
        SwapShorts(values, count);

    return count;
}

i32 Stream::Get(u32* values, i32 count)
{
    export_hook(0x55F1D0);

    count = Read(values, count * sizeof(*values)) / sizeof(*values);

    if (swap_endian_)
        SwapLongs(values, count);

    return count;
}

i32 Stream::GetString(char* buffer, i32 buffer_len)
{
    export_hook(0x55EEF0);

    u32 len = GetLong();

    if (len <= static_cast<u32>(buffer_len)) // TODO: Should this be "<" to ensure a null terminator?
        return Get(reinterpret_cast<u8*>(buffer), len);

    // TODO: Check result of Get()
    Get(reinterpret_cast<u8*>(buffer), buffer_len - 1);
    buffer[buffer_len - 1] = '\0';

    len -= buffer_len - 1;

    // TODO: Use seek?
    for (; len; --len)
        GetCh();

    return buffer_len;
}

i32 Stream::Printf(char const* format, ...)
{
    export_hook(0x55EDF0);

    std::va_list va;
    va_start(va, format);
    i32 result = Vprintf(format, va);
    va_end(va);
    return result;
}

i32 Stream::Put(f32 arg1)
{
    return stub<thiscall_t<i32, Stream*, f32>>(0x55F020, this, arg1);
}

i32 Stream::Put(u16 arg1)
{
    return stub<thiscall_t<i32, Stream*, u16>>(0x55EFA0, this, arg1);
}

i32 Stream::Put(u32 arg1)
{
    return stub<thiscall_t<i32, Stream*, u32>>(0x55EFD0, this, arg1);
}

i32 Stream::Put(u8 arg1)
{
    return stub<thiscall_t<i32, Stream*, u8>>(0x55EF80, this, arg1);
}

i32 Stream::Put(u16* arg1, i32 arg2)
{
    return stub<thiscall_t<i32, Stream*, u16*, i32>>(0x55F0A0, this, arg1, arg2);
}

i32 Stream::Put(u32* arg1, i32 arg2)
{
    return stub<thiscall_t<i32, Stream*, u32*, i32>>(0x55F100, this, arg1, arg2);
}

i32 Stream::Put(u8* arg1, i32 arg2)
{
    return stub<thiscall_t<i32, Stream*, u8*, i32>>(0x55F080, this, arg1, arg2);
}

i32 Stream::PutString(char* arg1)
{
    return stub<thiscall_t<i32, Stream*, char*>>(0x55EEB0, this, arg1);
}

i32 Stream::Read(void* arg1, i32 arg2)
{
    return stub<thiscall_t<i32, Stream*, void*, i32>>(0x55E9C0, this, arg1, arg2);
}

i32 Stream::Seek(i32 arg1)
{
    return stub<thiscall_t<i32, Stream*, i32>>(0x55EC60, this, arg1);
}

i32 Stream::Size()
{
    return stub<thiscall_t<i32, Stream*>>(0x55ECA0, this);
}

i32 Stream::Tell()
{
    return stub<thiscall_t<i32, Stream*>>(0x55EC90, this);
}

i32 Stream::Vprintf(char const* format, std::va_list va)
{
    export_hook(0x55EE40);

    char buffer[256];
    arts_vsprintf(buffer, format, va);
    return Write(buffer, std::strlen(buffer));
}

i32 Stream::Write(void* arg1, i32 arg2)
{
    return stub<thiscall_t<i32, Stream*, void*, i32>>(0x55EB00, this, arg1, arg2);
}

void Stream::RawDebug()
{}

i32 Stream::AlignSize()
{
    return 1;
}

i32 Stream::GetError(char* buf, i32 buf_len)
{
    i32 error = errno;
    strerror_s(buf, usize(buf_len), error);
    return error;
}

void Stream::SwapLongs(u32* values, i32 count)
{
    export_hook(0x55F240);

    for (i32 i = 0; i < count; ++i)
        ByteSwap(values[i]);
}

void Stream::SwapShorts(u16* values, i32 count)
{
    export_hook(0x55F210);

    for (i32 i = 0; i < count; ++i)
        ByteSwap(values[i]);
}

i32 arts_fgets(char* arg1, i32 arg2, class Stream* arg3)
{
    return stub<cdecl_t<i32, char*, i32, class Stream*>>(0x55F3E0, arg1, arg2, arg3);
}

class Stream* arts_fopen(const char* path, const char* mode)
{
    return stub<cdecl_t<class Stream*, const char*, const char*>>(0x55F2F0, path, mode);
}

void arts_fprintf(class Stream* stream, char const* format, ...)
{
    export_hook(0x55F2D0);

    std::va_list va;
    va_start(va, format);
    stream->Vprintf(format, va);
    va_end(va);
}

i32 arts_fscanf(class Stream* stream, char const* format, ...)
{
    export_hook(0x55F450);

    i32 ch = -1;

    do
    {
        ch = stream->GetCh();
    } while (ch == ' ' || ch == '\t' || ch == '\n');

    stream->UnGetCh(ch);

    char buffer[256];
    i32 length = arts_fgets(buffer, std::size(buffer), stream);

    if (!length)
        return 0;

    std::va_list va;
    va_start(va, format);

    // NOTE: This can not be vsscanf_s because it has to support the game's unsafe format strings.
    // TODO: Replace this with vsscanf_s when possible
    i32 result = vsscanf(static_cast<const char*>(buffer), format, va);
    va_end(va);

    if (!result)
        Errorf("scan of '%s' == '%s' failed", format, buffer);

    return result;
}

i32 arts_fseek(class Stream* arg1, i32 arg2, i32 arg3)
{
    return stub<cdecl_t<i32, class Stream*, i32, i32>>(0x55F330, arg1, arg2, arg3);
}
