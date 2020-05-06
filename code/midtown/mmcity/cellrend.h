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
    mmcity:cellrend

    0x498970 | public: __thiscall mmCellRenderer::mmCellRenderer(void) | ??0mmCellRenderer@@QAE@XZ
    0x4989A0 | public: __thiscall mmCellRenderer::~mmCellRenderer(void) | ??1mmCellRenderer@@QAE@XZ
    0x4989E0 | public: void __thiscall mmCellRenderer::Init(char *,int,int,int,int,int *) | ?Init@mmCellRenderer@@QAEXPADHHHHPAH@Z
    0x498F90 | public: void __thiscall mmCellRenderer::Relight(void) | ?Relight@mmCellRenderer@@QAEXXZ
    0x498FA0 | public: virtual void __thiscall mmCellRenderer::Cull(int) | ?Cull@mmCellRenderer@@UAEXH@Z
    0x61D320 | const mmCellRenderer::`vftable' | ??_7mmCellRenderer@@6B@
    0x6401C0 | float (* StaticTerrainLodTable)[2] | ?StaticTerrainLodTable@@3PAY01MA
    0x6401E0 | float ObjectMaxDist | ?ObjectMaxDist@@3MA
    0x6401E4 | int EnableSlide | ?EnableSlide@@3HA
    0x7057B8 | int CRPassBoth | ?CRPassBoth@@3HA
    0x7057BC | int CRPass1Only | ?CRPass1Only@@3HA
    0x7057C0 | int * CellTriCount | ?CellTriCount@@3PAHA
    0x7057D0 | int * CellTypeCount | ?CellTypeCount@@3PAHA
    0x7057DC | int CRPass3Only | ?CRPass3Only@@3HA
*/

struct mmCellRenderer
{
    // const mmCellRenderer::`vftable' @ 0x61D320

public:
    // 0x498970 | ??0mmCellRenderer@@QAE@XZ
    mmCellRenderer();

    // 0x4989A0 | ??1mmCellRenderer@@QAE@XZ
    ~mmCellRenderer();

    // 0x498FA0 | ?Cull@mmCellRenderer@@UAEXH@Z
    virtual void Cull(i32 arg1);

    // 0x4989E0 | ?Init@mmCellRenderer@@QAEXPADHHHHPAH@Z
    void Init(char* arg1, i32 arg2, i32 arg3, i32 arg4, i32 arg5, i32* arg6);

    // 0x498F90 | ?Relight@mmCellRenderer@@QAEXXZ
    void Relight();
};

check_size(mmCellRenderer, 0x48);

// 0x7057BC | ?CRPass1Only@@3HA
inline extern_var(0x7057BC, i32, CRPass1Only);

// 0x7057DC | ?CRPass3Only@@3HA
inline extern_var(0x7057DC, i32, CRPass3Only);

// 0x7057B8 | ?CRPassBoth@@3HA
inline extern_var(0x7057B8, i32, CRPassBoth);

// 0x7057C0 | ?CellTriCount@@3PAHA
inline extern_var(0x7057C0, i32*, CellTriCount);

// 0x7057D0 | ?CellTypeCount@@3PAHA
inline extern_var(0x7057D0, i32*, CellTypeCount);

// 0x6401E4 | ?EnableSlide@@3HA
inline extern_var(0x6401E4, i32, EnableSlide);

// 0x6401E0 | ?ObjectMaxDist@@3MA
inline extern_var(0x6401E0, f32, ObjectMaxDist);

// 0x6401C0 | ?StaticTerrainLodTable@@3PAY01MA
inline extern_var(0x6401C0, f32 (*)[2], StaticTerrainLodTable);
