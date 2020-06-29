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
    memory:valloc

    0x521390 | public: __thiscall asSafeHeap::asSafeHeap(void) | ??0asSafeHeap@@QAE@XZ
    0x5213A0 | public: __thiscall asSafeHeap::~asSafeHeap(void) | ??1asSafeHeap@@QAE@XZ
    0x5213B0 | public: void __thiscall asSafeHeap::Init(int,int) | ?Init@asSafeHeap@@QAEXHH@Z
    0x521420 | public: void __thiscall asSafeHeap::Restart(void) | ?Restart@asSafeHeap@@QAEXXZ
    0x521450 | public: void __thiscall asSafeHeap::Kill(void) | ?Kill@asSafeHeap@@QAEXXZ
    0x521480 | protected: void __thiscall asSafeHeap::Activate(void) | ?Activate@asSafeHeap@@IAEXXZ
    0x5214C0 | protected: void __thiscall asSafeHeap::Deactivate(void) | ?Deactivate@asSafeHeap@@IAEXXZ
    0x790730 | class asSafeHeap SAFEHEAP | ?SAFEHEAP@@3VasSafeHeap@@A
*/

class asSafeHeap
{
public:
    // 0x521390 | ??0asSafeHeap@@QAE@XZ
    ARTS_EXPORT asSafeHeap();

    // 0x5213A0 | ??1asSafeHeap@@QAE@XZ
    ARTS_EXPORT ~asSafeHeap();

    // 0x5213B0 | ?Init@asSafeHeap@@QAEXHH@Z
    ARTS_EXPORT void Init(i32 heap_size, b32 multi_heap);

    // 0x521450 | ?Kill@asSafeHeap@@QAEXXZ
    ARTS_EXPORT void Kill();

    // 0x521420 | ?Restart@asSafeHeap@@QAEXXZ
    ARTS_EXPORT void Restart();

protected:
    // 0x521480 | ?Activate@asSafeHeap@@IAEXXZ
    ARTS_EXPORT void Activate();

    // 0x5214C0 | ?Deactivate@asSafeHeap@@IAEXXZ
    ARTS_EXPORT void Deactivate();

private:
    u8* current_heap_ {nullptr};
    u8* heap_ {nullptr};
    u32 heap_index_ {0};
    u32 heap_size_ {0};
    b32 multi_heap_ {false};
};

check_size(asSafeHeap, 0x14);

// 0x790730 | ?SAFEHEAP@@3VasSafeHeap@@A
ARTS_IMPORT extern class asSafeHeap SAFEHEAP;
