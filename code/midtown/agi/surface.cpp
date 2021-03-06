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

define_dummy_symbol(agi_surface);

#include "surface.h"

#include "agi/rgba.h"
#include "agiworld/texsheet.h"
#include "cmodel.h"
#include "texdef.h"

#include <emmintrin.h>

// 0x55AAE0 | ?RescaleJpeg@@YAXIIPAEAAUjpeg_decompress_struct@@@Z
ARTS_IMPORT /*static*/ void RescaleJpeg(u32 arg1, u32 arg2, u8* arg3, struct jpeg_decompress_struct& arg4);

// 0x55B7E0 | ?copyrow4444_to_555@@YAXPAX0II@Z
ARTS_IMPORT /*static*/ void copyrow4444_to_555(void* arg1, void* arg2, u32 arg3, u32 arg4);

// 0x55B8E0 | ?copyrow4444_to_5551@@YAXPAX0II@Z
ARTS_IMPORT /*static*/ void copyrow4444_to_5551(void* arg1, void* arg2, u32 arg3, u32 arg4);

// 0x55B860 | ?copyrow4444_to_565@@YAXPAX0II@Z
ARTS_IMPORT /*static*/ void copyrow4444_to_565(void* arg1, void* arg2, u32 arg3, u32 arg4);

// 0x55B6C0 | ?copyrow4444_to_8888@@YAXPAX0II@Z
static void copyrow4444_to_8888(void* dst, void* src, u32 len, u32 step)
{
    u32* ARTS_RESTRICT dst32 = static_cast<u32*>(dst);
    u16* ARTS_RESTRICT src16 = static_cast<u16*>(src);

    if (step == 0x10000 && len >= 8)
    {
        const __m128i mask_lo = _mm_set1_epi32(0x0F0F0F0F);
        const __m128i mask_hi = _mm_slli_epi32(mask_lo, 4);

        do
        {
            len -= 8;

            __m128i dst_lo = _mm_loadu_si128((const __m128i*) (src16));
            src16 += 8;

            __m128i dst_hi = dst_lo;

            dst_lo = _mm_and_si128(dst_lo, mask_lo);
            dst_hi = _mm_and_si128(dst_hi, mask_hi);

            dst_lo = _mm_or_si128(dst_lo, _mm_slli_epi16(dst_lo, 4));
            dst_hi = _mm_or_si128(dst_hi, _mm_srli_epi16(dst_hi, 4));

            _mm_storeu_si128((__m128i*) (dst32 + 0), _mm_unpacklo_epi8(dst_lo, dst_hi));
            _mm_storeu_si128((__m128i*) (dst32 + 4), _mm_unpackhi_epi8(dst_lo, dst_hi));

            dst32 += 8;
        } while (len >= 8);
    }

    for (u32 src_off = 0; len; --len)
    {
        u32 v = src16[src_off >> 16];
        src_off += step;
        v = (v & 0x000F) | ((v & 0x00F0) << 4) | ((v & 0x0F00) << 8) | ((v & 0xF000) << 12);
        *dst32++ = v | (v << 4);
    }
}

static void copyrow4444_to_888amul(void* dst, void* src, u32 len, u32 step)
{
    u32* ARTS_RESTRICT dst32 = static_cast<u32*>(dst);
    u16* ARTS_RESTRICT src16 = static_cast<u16*>(src);

    for (u32 src_off = 0; len; --len)
    {
        u32 v = src16[src_off >> 16];
        src_off += step;

        // rgb = (rgb * a) * (255 / 225)
        // (255 / 225) == (17 / 15)
        // (x * 17) / 15 == (x * 17 * 0x889) >> 15
        u32 amul = (v >> 12) * 0x9119;
        u32 r = ((v & 0x00F) * amul) >> 15;
        u32 g = ((v & 0x0F0) * amul) >> 11;
        u32 b = ((v & 0xF00) * amul) >> 7;
        *dst32++ = r | (g & 0xFF00) | (b & 0xFF0000);
    }
}

// 0x55B750 | ?copyrow4444_to_8888rev@@YAXPAX0II@Z
ARTS_IMPORT /*static*/ void copyrow4444_to_8888rev(void* arg1, void* arg2, u32 arg3, u32 arg4);

// 0x55B510 | ?copyrow565_to_555@@YAXPAX0II@Z
ARTS_IMPORT /*static*/ void copyrow565_to_555(void* arg1, void* arg2, u32 arg3, u32 arg4);

// 0x55B560 | ?copyrow565_to_5551@@YAXPAX0II@Z
ARTS_IMPORT /*static*/ void copyrow565_to_5551(void* arg1, void* arg2, u32 arg3, u32 arg4);

// 0x55B5C0 | ?copyrow565_to_888@@YAXPAX0II@Z
static void copyrow565_to_888(void* dst, void* src, u32 len, u32 step)
{
    u32* ARTS_RESTRICT dst32 = static_cast<u32*>(dst);
    u16* ARTS_RESTRICT src16 = static_cast<u16*>(src);

    if (step == 0x10000 && len >= 8)
    {
        const __m128i mult_0108 = _mm_set1_epi32(0x01080108);
        const __m128i mult_2080 = _mm_set1_epi32(0x20802080);

        const __m128i mask_07E0 = _mm_set1_epi32(0x07E007E0);
        const __m128i mask_F800 = _mm_set1_epi32(0xF800F800);

        do
        {
            len -= 8;

            __m128i dst_lo = _mm_loadu_si128((const __m128i*) (src16));

            src16 += 8;

            __m128i dst_r = _mm_slli_epi16(_mm_mulhi_epu16(_mm_and_si128(dst_lo, mask_F800), mult_0108), 8);
            __m128i dst_b = _mm_mulhi_epu16(_mm_slli_epi16(dst_lo, 11), mult_0108);
            __m128i dst_g = _mm_mulhi_epu16(_mm_and_si128(dst_lo, mask_07E0), mult_2080);

            dst_lo = _mm_or_si128(dst_r, dst_b);

            _mm_storeu_si128((__m128i*) (dst32 + 0), _mm_unpacklo_epi8(dst_lo, dst_g));
            _mm_storeu_si128((__m128i*) (dst32 + 4), _mm_unpackhi_epi8(dst_lo, dst_g));

            dst32 += 8;
        } while (len >= 8);
    }

    for (u32 src_off = 0; len; --len)
    {
        u32 v = src16[src_off >> 16];
        src_off += step;
        *dst32++ =
            ((v & 0xF800) << 8) | ((v & 0x07E0) << 5) | ((v & 0xE01F) << 3) | ((v & 0x0600) >> 1) | ((v & 0x001C) >> 2);
    }
}

// 0x55B640 | ?copyrow565_to_888rev@@YAXPAX0II@Z
ARTS_IMPORT /*static*/ void copyrow565_to_888rev(void* arg1, void* arg2, u32 arg3, u32 arg4);

static void copyrow_8(void* dst, void* src, u32 len, u32 step)
{
    u8* ARTS_RESTRICT dst8 = static_cast<u8*>(dst);
    u8* ARTS_RESTRICT src8 = static_cast<u8*>(src);

    for (u32 src_off = 0; len; --len)
    {
        *dst8++ = src8[src_off >> 16];
        src_off += step;
    }
}

static void copyrow_16(void* dst, void* src, u32 len, u32 step)
{
    u16* ARTS_RESTRICT dst16 = static_cast<u16*>(dst);
    u16* ARTS_RESTRICT src16 = static_cast<u16*>(src);

    for (u32 src_off = 0; len; --len)
    {
        *dst16++ = src16[src_off >> 16];
        src_off += step;
    }
}

static void copyrow_32(void* dst, void* src, u32 len, u32 step)
{
    u32* ARTS_RESTRICT dst32 = static_cast<u32*>(dst);
    u32* ARTS_RESTRICT src32 = static_cast<u32*>(src);

    for (u32 src_off = 0; len; --len)
    {
        *dst32++ = src32[src_off >> 16];
        src_off += step;
    }
}

void agiSurfaceDesc::CopyFrom(agiSurfaceDesc* src, i32 src_lod)
{
    CopyFrom(src, src_lod, nullptr);
}

void agiSurfaceDesc::CopyFrom(agiSurfaceDesc* src, i32 src_lod, agiTexParameters* params)
{
    u32 dst_width = Width;
    u32 dst_height = Height;
    i32 dst_pitch = Pitch;
    u8* dst_surface = static_cast<u8*>(Surface);

    // FIXME: Surfaces with a PackShift don't have their pitch updated. This should really be corrected in agiSurfaceDesc::Load.
    src->FixPitch();

    u32 src_width = src->Width;
    u32 src_height = src->Height;
    i32 src_pitch = src->Pitch;
    u8* src_surface = static_cast<u8*>(src->Surface);

    for (; src_lod; --src_lod)
    {
        src_surface += src_pitch * src_height;
        src_width >>= 1;
        src_height >>= 1;
        src_pitch >>= 1;
    }

    void (*copy_row)(void*, void*, u32, u32) = nullptr;

    if (!std::memcmp(&PixelFormat, &src->PixelFormat, sizeof(PixelFormat)))
    {
        if (src_width == dst_width && src_height == dst_height && src_pitch == dst_pitch)
        {
            std::memcpy(dst_surface, src_surface, dst_pitch * dst_height);

            return;
        }

        switch (GetPixelSize())
        {
            case sizeof(u8): copy_row = copyrow_8; break;
            case sizeof(u16): copy_row = copyrow_16; break;
            case sizeof(u32): copy_row = copyrow_32; break;

            default: Quitf("Invalid Pixel Format");
        }
    }
    else
    {
        switch (src->PixelFormat.RBitMask)
        {
            case 0xF800: // 565
                switch (PixelFormat.RBitMask)
                {
                    case 0xFF0000u: copy_row = copyrow565_to_888; break;
                    case 0xFFu: copy_row = copyrow565_to_888rev; break;

                    case 0x7C00u:
                        if (PixelFormat.RGBAlphaBitMask == 0x8000)
                        {
                            copy_row = copyrow565_to_5551;
                        }
                        else
                        {
                            copy_row = copyrow565_to_555;
                        }
                        break;
                }
                break;

            case 0xF00: // 4444
                // 4444_to_565, 4444_to_5551, 4444_to_555 do alpha multiplication, but 4444_to_8888 and 4444_to_8888rev do not.
                // Therefore, 4444_to_888amul was added to do the alpha multiplication when needed

                switch (PixelFormat.RBitMask)
                {
                    case 0xFF0000u:
                        copy_row = (params && (params->Props & agiTexProp::AlphaGlow) &&
                                       !(params->Flags & agiTexParameters::Alpha))
                            ? copyrow4444_to_888amul
                            : copyrow4444_to_8888;
                        break;
                    case 0xFFu: copy_row = copyrow4444_to_8888rev; break;

                    case 0xF800u: copy_row = copyrow4444_to_565; break;
                    case 0x7C00u:
                        if (PixelFormat.RGBAlphaBitMask == 0x8000)
                        {
                            copy_row = copyrow4444_to_5551;
                        }
                        else
                        {
                            copy_row = copyrow4444_to_555;
                        }
                        break;
                }
                break;
        }
    }

    if (!copy_row)
    {
        Quitf("Tell Dave to implement (%x,%x,%x,%x)-->(%x,%x,%x,%x) copyrow function.", src->PixelFormat.RBitMask,
            src->PixelFormat.GBitMask, src->PixelFormat.BBitMask, src->PixelFormat.RGBAlphaBitMask,
            PixelFormat.RBitMask, PixelFormat.GBitMask, PixelFormat.BBitMask, PixelFormat.RGBAlphaBitMask);
    }

    u32 src_x_step = (src_width << 16) / dst_width;
    u32 src_y_step = (src_height << 16) / dst_height;

    for (u32 dst_y = 0, src_y = 0; dst_y < dst_height; ++dst_y, src_y += src_y_step)
    {
        copy_row(dst_surface + (dst_pitch * dst_y), src_surface + (src_pitch * (src_y >> 16)), dst_width, src_x_step);
    }
}

void agiSurfaceDesc::Unload()
{
    if (Surface)
    {
        delete[] static_cast<u8*>(Surface);
        Surface = nullptr;
    }
}

void agiSurfaceDesc::Init(i32 width, i32 height)
{
    Flags = AGISD_WIDTH | AGISD_HEIGHT | AGISD_PITCH;
    Width = width;
    Height = height;
    Pitch = width * GetPixelSize();
    Surface = nullptr;
    MipMapCount = 0;
    SCaps.Caps = 0;

    Load();
}

[[nodiscard]] Owner<agiSurfaceDesc> agiSurfaceDesc::Init(i32 width, i32 height, const agiSurfaceDesc& desc)
{
    Ptr<agiSurfaceDesc> result = MakeUnique<agiSurfaceDesc>(desc);
    result->Init(width, height);
    return AsOwner(result);
}

void agiSurfaceDesc::Load()
{
    if (Surface == nullptr)
        Surface = new u8[Pitch * Height] {};
}

void agiSurfaceDesc::Clear()
{
    std::memset(Surface, 0, Pitch * Height);
}

void agiSurfaceDesc::Clear(i32 x, i32 y, i32 width, i32 height)
{
    if (x + width > static_cast<i32>(Width) || y + height > static_cast<i32>(Height))
        return;

    i32 pixel_size = GetPixelSize();

    for (; height; ++y, --height)
        std::memset(static_cast<u8*>(Surface) + (y * Pitch) + (x * pixel_size), 0, width * pixel_size);
}

void agiSurfaceDesc::Fill(i32 x, i32 y, i32 width, i32 height, u32 color)
{
    if (x + width > static_cast<i32>(Width) || y + height > static_cast<i32>(Height))
        return;

    Rc<agiColorModel> cmodel = AsRc(agiColorModel::FindMatch(this));

    color = cmodel->GetColor(agiRgba::FromARGB(color));

    u32 byte_count = cmodel->PixelSize;

    for (; height; ++y, --height)
    {
        void* row = static_cast<u8*>(Surface) + (y * Pitch) + (x * byte_count);

        switch (byte_count)
        {
            case 2:
                for (i32 i = 0; i < width; ++i)
                    static_cast<u16*>(row)[i] = static_cast<u16>(color);
                break;

            case 4:
                for (i32 i = 0; i < width; ++i)
                    static_cast<u32*>(row)[i] = color;
                break;
        }
    }
}

void agiSurfaceDesc::FixPitch()
{
    i32 pitch = Width * GetPixelSize();

    if (!(Flags & AGISD_PITCH) || (pitch > Pitch) || (pitch * 2 <= Pitch))
    {
        Pitch = pitch;
        Flags |= AGISD_PITCH;
    }
}
