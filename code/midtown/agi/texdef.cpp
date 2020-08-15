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

define_dummy_symbol(agi_texdef);

#include "texdef.h"

#include "data7/cache.h"
#include "data7/ipc.h"
#include "error.h"
#include "pipeline.h"
#include "rsys.h"
#include "stream/fsystem.h"
#include "stream/stream.h"
#include "texlib.h"

struct lutQentry
{
    agiTexLut** Lut;
    char Name[4];
};

static i32 lutQhead = 0;
static i32 lutQtail = 0;

void agiTexParameters::Load(Stream* file)
{
    file->Read(Name, sizeof(Name));
    file->Get(&Flags, 1);
    file->Get(&LOD, 1);
    file->Get(&MaxLOD, 1);

    u8 byte23;
    file->Get(&byte23, 1);
}

void agiTexParameters::Save(Stream* file)
{
    file->Write(Name, sizeof(Name));
    file->Put(Flags);
    file->Put(LOD);
    file->Put(MaxLOD);
    file->Put(0_u8);
}

b32 agiTexDef::IsAvailable()
{
    return page_state_ == 2;
}

b32 agiTexDef::Lock(struct agiTexLock& /*arg1*/)
{
    return false;
}

void agiTexDef::Unlock(struct agiTexLock& /*arg1*/)
{}

void agiTexDef::Request()
{}

void agiTexDef::CheckSurface()
{
    if (Surface->Flags & AGISD_CKSRCBLT)
        Tex.Flags |= agiTexParameters::Chromakey;
    else
        Tex.Flags &= ~agiTexParameters::Chromakey;
}

void agiTexDef::DoPageIn()
{
    // NOTE: 64-bit incompatible
    pager_.Read(Surface, 0x4, sizeof(*Surface));

    i32 mip_pack = PackShift & 0xF;

    Surface->MipMapCount -= mip_pack;
    Surface->Width >>= mip_pack;
    Surface->Height >>= mip_pack;
    Surface->Pitch >>= mip_pack;

    if (agiCurState.GetSoftwareRendering())
    {
        i32 index = (lutQtail + 1) % std::size(lutQ);

        if (index == lutQhead)
        {
            page_state_ = 0;

            return;
        }

        lutQ[index].Lut = &Surface->lpLut;
        std::memcpy(lutQ[index].Name, Surface->szLut, 4);
        Surface->lpLut = nullptr;
        lutQtail = index;
    }

    u32 surface_offset = 0x80;
    u32 surface_size = pager_.Size - 0x80;

    // Go through the mip levels in reverse, adding the correct offset (sd->Width and sd->Height are already scaled by down MipReduction).
    for (u32 current_surface_size = Surface->Height * Surface->Pitch; mip_pack; --mip_pack)
    {
        current_surface_size *= 4;
        surface_offset += current_surface_size;
        surface_size -= current_surface_size;
    }

    if (!TEXCACHE.BeginObject(&cache_handle_, PageOutCallback, this, surface_size))
    {
        page_state_ = 0;

        return;
    }

    Surface->Surface = TEXCACHE.Allocate(cache_handle_, surface_size);
    pager_.Read(Surface->Surface, surface_offset, surface_size);

    TexBytesPaged += surface_size;
    ++TexsPaged;

    page_state_ = 2;

    TEXCACHE.EndObject(cache_handle_);
}

char* agiTexDef::GetName()
{
    static char buffer[64]; // FIXME: Static buffer
    arts_sprintf(buffer, "Texture '%s' %d/%d", Tex.Name, Tex.LOD, Tex.MaxLOD);
    return buffer;
}

i32 agiTexDef::Init(agiTexParameters const& params)
{
    if (DevelopmentMode || !(EnablePaging & ARTS_PAGE_TEXTURES) || (params.Flags & agiTexParameters::KeepLoaded))
    {
        EndGfx();
        Tex = params;
        Reload();

        return SafeBeginGfx();
    }
    else
    {
        Tex = params;

        return 0;
    }
}

i32 agiTexDef::Init(class agiTexParameters const& params, agiSurfaceDesc* surface)
{
    EndGfx();

    Tex = params;
    Tex.Flags |= agiTexParameters::KeepLoaded;

    Surface = surface;

    CheckSurface();

    return BeginGfx();
}

b32 agiTexDef::IsTexture()
{
    return true;
}

b32 agiTexDef::LockSurfaceIfResident()
{
    return (page_state_ > 1) && (cache_handle_ == 0 || TEXCACHE.Lock(&cache_handle_));
}

void agiTexDef::PageInSurface()
{
    if (pager_.Handle == 0)
    {
        const char* path = TexSearchPath;

        do
        {
            char buffer[64];

            if (Tex.LOD)
                arts_sprintf(buffer, "%s/%s.%04d.dds", path, Tex.Name, Tex.LOD);
            else
                arts_sprintf(buffer, "%s/%s.dds", path, Tex.Name);

            if (FileSystem::PagerInfoAny(buffer, pager_))
                break;

            path += std::strlen(path) + 1;
        } while (*path);

        if (pager_.Handle)
            Surface = new agiSurfaceDesc();
    }

    if (page_state_ == 0 && pager_.Handle != 0)
    {
        ++page_state_;

        PAGER.Send(PageInCallback, this);
    }
}

i32 agiTexDef::Reload()
{
    Surface = agiSurfaceDesc::Load(Tex.Name, TexSearchPath, Tex.LOD, PackShift & 0xF, 0, 0);

    CheckSurface();

    agiDisplayf("'%s' is %s texture", Tex.Name,
        (Tex.Flags & agiTexParameters::Chromakey) ? "chromakey"
                                                  : (Tex.Flags & agiTexParameters::Alpha) ? "alpha" : "opaque");

    return Surface ? AGI_ERROR_SUCCESS : AGI_ERROR_FILE_NOT_FOUND;
}

void agiTexDef::UnlockAndFreeSurface()
{
    if (cache_handle_ != 0)
        TEXCACHE.UnlockAndFree(cache_handle_);

    cache_handle_ = 0;
}

void agiTexDef::UnlockSurface()
{
    if (cache_handle_ != 0)
        TEXCACHE.Unlock(cache_handle_);
}

void agiTexDef::PageInCallback(void* param)
{
    static_cast<agiTexDef*>(param)->DoPageIn();
}

void agiTexDef::PageOutCallback(void* param, i32 delta)
{
    agiTexDef* tex = static_cast<agiTexDef*>(param);

    if (delta)
    {
        if (void* surface = tex->Surface->Surface)
            tex->Surface->Surface = static_cast<u8*>(surface) + delta;
    }
    else
    {
        tex->Surface->Surface = nullptr;
        tex->page_state_ = 0;
    }
}

agiTexDef::agiTexDef(agiPipeline* pipe)
    : agiRefreshable(pipe)
{}

agiTexDef::~agiTexDef()
{
    if (i32 index = agiTexLib.Lookup(Tex.Name))
    {
        if (Tex.LOD)
            index += Tex.LOD - 1;

        if (agiTexDef** def = agiTexLib.GetDef(index); *def)
        {
            ArAssert(*def == this, "TexLib def mismatch");
            Displayf("%s still in TexLib", GetName());
            *def = nullptr;
        }
    }

    if (Surface)
    {
        Surface->Unload();

        delete Surface;
    }
}

void ShutdownLutQueue()
{
    lutQhead = 0;
    lutQtail = 0;
}

void UpdateLutQueue()
{
    while (lutQhead != lutQtail)
    {
        i32 index = (lutQhead + 1) % std::size(lutQ);

        char buffer[32];
        arts_sprintf(buffer, "texp/nbr%s.lut", lutQ[index].Name);

        *lutQ[index].Lut = Pipe()->GetTexLut(buffer);

        if (*lutQ[index].Lut == nullptr)
            Errorf("Lut '%s' didn't load.", buffer);

        lutQhead = index;
    }
}

char* agiTexLut::GetName()
{
    static char buffer[64]; // FIXME: Static buffer
    arts_sprintf(buffer, "texlut '%s'", name_.get());
    return buffer;
}

i32 agiTexLut::Init(const char* name)
{
    EndGfx();
    name_ = name;

    if (!arts_stricmp(name, "*grey"))
    {
        for (u32 i = 0; i < std::size(palette_); ++i)
            palette_[i] = i * 0x10101;
    }
    else
    {
        Ptr<Stream> file {arts_fopen(name, "r")};

        if (file == nullptr)
            return -1;

        file->Read(palette_, sizeof(palette_));
    }

    return SafeBeginGfx();
}

agiTexLut::agiTexLut(agiPipeline* pipe)
    : agiRefreshable(pipe)
{}
