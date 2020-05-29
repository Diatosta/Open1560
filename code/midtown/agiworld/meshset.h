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
    agiworld:meshset

    0x5147D0 | public: __thiscall agiMeshSet::agiMeshSet(void) | ??0agiMeshSet@@QAE@XZ
    0x5147F0 | public: __thiscall agiMeshSet::~agiMeshSet(void) | ??1agiMeshSet@@QAE@XZ
    0x514880 | public: void __thiscall agiMeshSet::Offset(class Vector3) | ?Offset@agiMeshSet@@QAEXVVector3@@@Z
    0x5148D0 | public: void __thiscall agiMeshSet::ComputePlaneEquations(void) | ?ComputePlaneEquations@agiMeshSet@@QAEXXZ
    0x514AF0 | private: static void __cdecl agiMeshSet::PageInCallback(void *) | ?PageInCallback@agiMeshSet@@CAXPAX@Z
    0x514B00 | public: void __thiscall agiMeshSet::PageIn(void) | ?PageIn@agiMeshSet@@QAEXXZ
    0x514B20 | public: int __thiscall agiMeshSet::LockIfResident(void) | ?LockIfResident@agiMeshSet@@QAEHXZ
    0x514B50 | public: void __thiscall agiMeshSet::Unlock(void) | ?Unlock@agiMeshSet@@QAEXXZ
    0x514B70 | public: void __thiscall agiMeshSet::UnlockAndFree(void) | ?UnlockAndFree@agiMeshSet@@QAEXXZ
    0x514B90 | public: void __thiscall agiMeshSet::MakeResident(void) | ?MakeResident@agiMeshSet@@QAEXXZ
    0x514BC0 | public: int __thiscall agiMeshSet::IsFullyResident(int) | ?IsFullyResident@agiMeshSet@@QAEHH@Z
*/

class agiMeshSet
{
public:
    // 0x5147D0 | ??0agiMeshSet@@QAE@XZ
    agiMeshSet();

    // 0x5147F0 | ??1agiMeshSet@@QAE@XZ
    ~agiMeshSet();

    // 0x502BD0 | ?BinaryLoad@agiMeshSet@@QAEXPAVStream@@@Z | inline
    void BinaryLoad(class Stream* arg1);

    // 0x516B30 | ?BinarySave@agiMeshSet@@QAEXPAVStream@@@Z | inline
    void BinarySave(class Stream* arg1);

    // 0x5148D0 | ?ComputePlaneEquations@agiMeshSet@@QAEXXZ
    void ComputePlaneEquations();

    // 0x506ED0 | ?Draw@agiMeshSet@@QAEHI@Z | inline
    i32 Draw(u32 arg1);

    // 0x506FD0 | ?DrawColor@agiMeshSet@@QAEHII@Z | inline
    i32 DrawColor(u32 arg1, u32 arg2);

    // 0x507040 | ?DrawLit@agiMeshSet@@QAEHP6AXPAEPAI1PAV1@@ZI1@Z | inline
    i32 DrawLit(void (*arg1)(u8*, u32*, u32*, class agiMeshSet*), u32 arg2, u32* arg3);

    // 0x507120 | ?DrawLitEnv@agiMeshSet@@QAEXP6AXPAEPAI1PAV1@@ZPAVagiTexDef@@AAVMatrix34@@I@Z | inline
    void DrawLitEnv(
        void (*arg1)(u8*, u32*, u32*, class agiMeshSet*), class agiTexDef* arg2, class Matrix34& arg3, u32 arg4);

    // 0x507250 | ?DrawLitSph@agiMeshSet@@QAEXP6AXPAEPAI1PAV1@@ZPAVagiTexDef@@I@Z | inline
    void DrawLitSph(void (*arg1)(u8*, u32*, u32*, class agiMeshSet*), class agiTexDef* arg2, u32 arg3);

    // 0x50EBC0 | ?DrawNormals@agiMeshSet@@QAEXAAVVector3@@@Z | inline
    void DrawNormals(class Vector3& arg1);

    // 0x506F40 | ?DrawShadow@agiMeshSet@@QAEXIABVVector4@@ABVVector3@@@Z | inline
    void DrawShadow(u32 arg1, class Vector4 const& arg2, class Vector3 const& arg3);

    // 0x50DB10 | ?EnvMap@agiMeshSet@@QAEXAAVMatrix34@@PAVagiTexDef@@I@Z | inline
    void EnvMap(class Matrix34& arg1, class agiTexDef* arg2, u32 arg3);

    // 0x50D0E0 | ?FirstPass@agiMeshSet@@QAEXPAIPAVVector2@@I@Z | inline
    void FirstPass(u32* arg1, class Vector2* arg2, u32 arg3);

    // 0x509FE0 | ?FirstPass_HW_UV_CPV_DYNTEX@agiMeshSet@@QAEXPAIPAVVector2@@I@Z | inline
    void FirstPass_HW_UV_CPV_DYNTEX(u32* arg1, class Vector2* arg2, u32 arg3);

    // 0x50A780 | ?FirstPass_HW_UV_CPV_noDYNTEX@agiMeshSet@@QAEXPAIPAVVector2@@I@Z | inline
    void FirstPass_HW_UV_CPV_noDYNTEX(u32* arg1, class Vector2* arg2, u32 arg3);

    // 0x50AF10 | ?FirstPass_HW_UV_noCPV_DYNTEX@agiMeshSet@@QAEXPAIPAVVector2@@I@Z | inline
    void FirstPass_HW_UV_noCPV_DYNTEX(u32* arg1, class Vector2* arg2, u32 arg3);

    // 0x50B4E0 | ?FirstPass_HW_UV_noCPV_noDYNTEX@agiMeshSet@@QAEXPAIPAVVector2@@I@Z | inline
    void FirstPass_HW_UV_noCPV_noDYNTEX(u32* arg1, class Vector2* arg2, u32 arg3);

    // 0x50BA90 | ?FirstPass_HW_noUV_CPV_DYNTEX@agiMeshSet@@QAEXPAIPAVVector2@@I@Z | inline
    void FirstPass_HW_noUV_CPV_DYNTEX(u32* arg1, class Vector2* arg2, u32 arg3);

    // 0x50C130 | ?FirstPass_HW_noUV_CPV_noDYNTEX@agiMeshSet@@QAEXPAIPAVVector2@@I@Z | inline
    void FirstPass_HW_noUV_CPV_noDYNTEX(u32* arg1, class Vector2* arg2, u32 arg3);

    // 0x50C7A0 | ?FirstPass_HW_noUV_noCPV_DYNTEX@agiMeshSet@@QAEXPAIPAVVector2@@I@Z | inline
    void FirstPass_HW_noUV_noCPV_DYNTEX(u32* arg1, class Vector2* arg2, u32 arg3);

    // 0x50CC50 | ?FirstPass_HW_noUV_noCPV_noDYNTEX@agiMeshSet@@QAEXPAIPAVVector2@@I@Z | inline
    void FirstPass_HW_noUV_noCPV_noDYNTEX(u32* arg1, class Vector2* arg2, u32 arg3);

    // 0x507D30 | ?FirstPass_SW_UV_CPV_DYNTEX@agiMeshSet@@QAEXPAIPAVVector2@@I@Z | inline
    void FirstPass_SW_UV_CPV_DYNTEX(u32* arg1, class Vector2* arg2, u32 arg3);

    // 0x508330 | ?FirstPass_SW_UV_CPV_noDYNTEX@agiMeshSet@@QAEXPAIPAVVector2@@I@Z | inline
    void FirstPass_SW_UV_CPV_noDYNTEX(u32* arg1, class Vector2* arg2, u32 arg3);

    // 0x508910 | ?FirstPass_SW_UV_noCPV_DYNTEX@agiMeshSet@@QAEXPAIPAVVector2@@I@Z | inline
    void FirstPass_SW_UV_noCPV_DYNTEX(u32* arg1, class Vector2* arg2, u32 arg3);

    // 0x508D30 | ?FirstPass_SW_UV_noCPV_noDYNTEX@agiMeshSet@@QAEXPAIPAVVector2@@I@Z | inline
    void FirstPass_SW_UV_noCPV_noDYNTEX(u32* arg1, class Vector2* arg2, u32 arg3);

    // 0x509130 | ?FirstPass_SW_noUV_CPV_DYNTEX@agiMeshSet@@QAEXPAIPAVVector2@@I@Z | inline
    void FirstPass_SW_noUV_CPV_DYNTEX(u32* arg1, class Vector2* arg2, u32 arg3);

    // 0x5095E0 | ?FirstPass_SW_noUV_CPV_noDYNTEX@agiMeshSet@@QAEXPAIPAVVector2@@I@Z | inline
    void FirstPass_SW_noUV_CPV_noDYNTEX(u32* arg1, class Vector2* arg2, u32 arg3);

    // 0x509A70 | ?FirstPass_SW_noUV_noCPV_DYNTEX@agiMeshSet@@QAEXPAIPAVVector2@@I@Z | inline
    void FirstPass_SW_noUV_noCPV_DYNTEX(u32* arg1, class Vector2* arg2, u32 arg3);

    // 0x509D30 | ?FirstPass_SW_noUV_noCPV_noDYNTEX@agiMeshSet@@QAEXPAIPAVVector2@@I@Z | inline
    void FirstPass_SW_noUV_noCPV_noDYNTEX(u32* arg1, class Vector2* arg2, u32 arg3);

    // 0x507320 | ?Geometry@agiMeshSet@@QAEHIPAVVector3@@PAVVector4@@@Z | inline
    i32 Geometry(u32 arg1, class Vector3* arg2, class Vector4* arg3);

    // 0x514BC0 | ?IsFullyResident@agiMeshSet@@QAEHH@Z
    i32 IsFullyResident(i32 arg1);

    // 0x514B20 | ?LockIfResident@agiMeshSet@@QAEHXZ
    i32 LockIfResident();

    // 0x514B90 | ?MakeResident@agiMeshSet@@QAEXXZ
    void MakeResident();

    // 0x50D170 | ?MultiTexEnvMap@agiMeshSet@@QAEXPAIIPAVagiTexDef@@AAVMatrix34@@@Z | inline
    void MultiTexEnvMap(u32* arg1, u32 arg2, class agiTexDef* arg3, class Matrix34& arg4);

    // 0x514880 | ?Offset@agiMeshSet@@QAEXVVector3@@@Z
    void Offset(class Vector3 arg1);

    // 0x514B00 | ?PageIn@agiMeshSet@@QAEXXZ
    void PageIn();

    // 0x507920 | ?ShadowGeometry@agiMeshSet@@QAEHIPAVVector3@@ABVVector4@@ABV2@@Z | inline
    i32 ShadowGeometry(u32 arg1, class Vector3* arg2, class Vector4 const& arg3, class Vector3 const& arg4);

    // 0x50E1D0 | ?SphereMap@agiMeshSet@@QAEXPAVagiTexDef@@I@Z | inline
    void SphereMap(class agiTexDef* arg1, u32 arg2);

    // 0x514B50 | ?Unlock@agiMeshSet@@QAEXXZ
    void Unlock();

    // 0x514B70 | ?UnlockAndFree@agiMeshSet@@QAEXXZ
    void UnlockAndFree();

    // 0x50EE70 | ?DrawCard@agiMeshSet@@SAXAAVVector3@@MIII@Z | inline
    static void DrawCard(class Vector3& arg1, f32 arg2, u32 arg3, u32 arg4, u32 arg5);

    // 0x50F9B0 | ?DrawLines@agiMeshSet@@SAXPAVVector3@@0PAIH@Z | inline
    static void DrawLines(class Vector3* arg1, class Vector3* arg2, u32* arg3, i32 arg4);

    // 0x50FE00 | ?DrawWideLines@agiMeshSet@@SAXPAVVector3@@0PAMPAIH@Z | inline
    static void DrawWideLines(class Vector3* arg1, class Vector3* arg2, f32* arg3, u32* arg4, i32 arg5);

    // 0x504C00 | ?Init@agiMeshSet@@SIXH@Z | inline
    static void __fastcall Init(i32 arg1);

    // 0x50EE30 | ?InitCards@agiMeshSet@@SAXAAUagiMeshCardInfo@@@Z | inline
    static void InitCards(struct agiMeshCardInfo& arg1);

    // 0x504A00 | ?InitLocalize@agiMeshSet@@SAXXZ | inline
    static void InitLocalize();

    // 0x504AC0 | ?Localize@agiMeshSet@@SAXAAVVector3@@0@Z | inline | unused
    static void Localize(class Vector3& arg1, class Vector3& arg2);

    // 0x504B70 | ?LocalizeDirection@agiMeshSet@@SAXAAVVector3@@0@Z | inline
    static void LocalizeDirection(class Vector3& arg1, class Vector3& arg2);

    // 0x5050C0 | ?SetFog@agiMeshSet@@SAXMH@Z | inline
    static void SetFog(f32 arg1, i32 arg2);

    // 0x64A730 | ?DefaultQuad@agiMeshSet@@2PAUagiMeshCardVertex@@A | inline
    static inline extern_var(0x64A730, struct agiMeshCardVertex*, DefaultQuad);

    // 0x64A6E0 | ?DepthOffset@agiMeshSet@@2MA | inline
    static inline extern_var(0x64A6E0, f32, DepthOffset);

    // 0x64A6DC | ?DepthScale@agiMeshSet@@2MA | inline
    static inline extern_var(0x64A6DC, f32, DepthScale);

    // 0x720ED8 | ?EyePlaneCount@agiMeshSet@@2HA | inline
    static inline extern_var(0x720ED8, i32, EyePlaneCount);

    // 0x73D398 | ?EyePlanes@agiMeshSet@@2PAVVector4@@A | inline
    static inline extern_var(0x73D398, class Vector4*, EyePlanes);

    // 0x725130 | ?EyePlanesHit@agiMeshSet@@2HA | inline
    static inline extern_var(0x725130, i32, EyePlanesHit);

    // 0x71DE50 | ?EyePos@agiMeshSet@@2VVector3@@A | inline
    static inline extern_var(0x71DE50, class Vector3, EyePos);

    // 0x72D154 | ?FlipX@agiMeshSet@@2HA | inline
    static inline extern_var(0x72D154, i32, FlipX);

    // 0x72D158 | ?FogValue@agiMeshSet@@2MA | inline
    static inline extern_var(0x72D158, f32, FogValue);

    // 0x720EB8 | ?HitEyePlanes@agiMeshSet@@2PAVVector4@@A | inline
    static inline extern_var(0x720EB8, class Vector4*, HitEyePlanes);

    // 0x7210E4 | ?MirrorMode@agiMeshSet@@2HA | inline
    static inline extern_var(0x7210E4, i32, MirrorMode);

    // 0x719E50 | ?codes@agiMeshSet@@2PAEA | inline
    static inline extern_var(0x719E50, u8*, codes);

protected:
    // 0x505E40 | ?ClipTri@agiMeshSet@@IAEXHHHH@Z | inline
    void ClipTri(i32 arg1, i32 arg2, i32 arg3, i32 arg4);

    // 0x504730 | ?InitMtx@agiMeshSet@@KIXAAVagiViewParameters@@H@Z | inline
    static void __fastcall InitMtx(class agiViewParameters& arg1, i32 arg2);

    // 0x504EB0 | ?InitViewport@agiMeshSet@@KIXAAVagiViewParameters@@@Z | inline
    static void __fastcall InitViewport(class agiViewParameters& arg1);

    // 0x504C80 | ?ShadowInit@agiMeshSet@@KIXABVVector4@@ABVVector3@@@Z | inline
    static void __fastcall ShadowInit(class Vector4 const& arg1, class Vector3 const& arg2);

    // 0x505360 | ?ShadowTransform@agiMeshSet@@KIXPAVVector4@@PAVVector3@@H@Z | inline
    static void __fastcall ShadowTransform(class Vector4* arg1, class Vector3* arg2, i32 arg3);

    // 0x505A30 | ?ShadowTransformOutcode@agiMeshSet@@KIIPAEPAVVector4@@PAVVector3@@H@Z | inline
    static u32 __fastcall ShadowTransformOutcode(u8* arg1, class Vector4* arg2, class Vector3* arg3, i32 arg4);

    // 0x516620 | ?ToScreen@agiMeshSet@@KIXPAEPAVVector4@@H@Z | inline
    static void __fastcall ToScreen(u8* arg1, class Vector4* arg2, i32 arg3);

    // 0x5050F0 | ?Transform@agiMeshSet@@KIXPAVVector4@@PAVVector3@@H@Z | inline
    static void __fastcall Transform(class Vector4* arg1, class Vector3* arg2, i32 arg3);

    // 0x5055E0 | ?TransformOutcode@agiMeshSet@@KIIPAEPAVVector4@@PAVVector3@@H@Z | inline
    static u32 __fastcall TransformOutcode(u8* arg1, class Vector4* arg2, class Vector3* arg3, i32 arg4);

    // 0x73D3BC | ?AllowEyeBackfacing@agiMeshSet@@1HA | inline
    static inline extern_var(0x73D3BC, i32, AllowEyeBackfacing);

    // 0x73D3C0 | ?HalfHeight@agiMeshSet@@1MA | inline
    static inline extern_var(0x73D3C0, f32, HalfHeight);

    // 0x72513C | ?HalfWidth@agiMeshSet@@1MA | inline
    static inline extern_var(0x72513C, f32, HalfWidth);

    // 0x72D148 | ?LocPos@agiMeshSet@@1VVector3@@A | inline
    static inline extern_var(0x72D148, class Vector3, LocPos);

    // 0x71DE60 | ?M@agiMeshSet@@1VMatrix34@@A | inline
    static inline extern_var(0x71DE60, class Matrix34, M);

    // 0x720EDC | ?MaxX@agiMeshSet@@1MA | inline
    static inline extern_var(0x720EDC, f32, MaxX);

    // 0x720E98 | ?MaxY@agiMeshSet@@1MA | inline
    static inline extern_var(0x720E98, f32, MaxY);

    // 0x73D390 | ?MinX@agiMeshSet@@1MA | inline
    static inline extern_var(0x73D390, f32, MinX);

    // 0x7210E0 | ?MinY@agiMeshSet@@1MA | inline
    static inline extern_var(0x7210E0, f32, MinY);

    // 0x719E4C | ?MtxSerial@agiMeshSet@@1IA | inline
    static inline extern_var(0x719E4C, u32, MtxSerial);

    // 0x71DE90 | ?OffsX@agiMeshSet@@1MA | inline
    static inline extern_var(0x71DE90, f32, OffsX);

    // 0x73D3B8 | ?OffsY@agiMeshSet@@1MA | inline
    static inline extern_var(0x73D3B8, f32, OffsY);

    // 0x72512C | ?ProjZW@agiMeshSet@@1MA | inline
    static inline extern_var(0x72512C, f32, ProjZW);

    // 0x72D140 | ?ProjZZ@agiMeshSet@@1MA | inline
    static inline extern_var(0x72D140, f32, ProjZZ);

    // 0x725128 | ?ViewSerial@agiMeshSet@@1IA | inline
    static inline extern_var(0x725128, u32, ViewSerial);

    // 0x72D160 | ?firstFacet@agiMeshSet@@1PAFA | inline
    static inline extern_var(0x72D160, i16*, firstFacet);

    // 0x721128 | ?fogout@agiMeshSet@@1PAEA | inline
    static inline extern_var(0x721128, u8*, fogout);

    // 0x719C48 | ?indexCounts@agiMeshSet@@1PAFA | inline
    static inline extern_var(0x719C48, i16*, indexCounts);

    // 0x725140 | ?nextFacet@agiMeshSet@@1PAFA | inline
    static inline extern_var(0x725140, i16*, nextFacet);

    // 0x73EE30 | ?out@agiMeshSet@@1PAVVector4@@A | inline
    static inline extern_var(0x73EE30, class Vector4*, out);

    // 0x720EE0 | ?vertCounts@agiMeshSet@@1PAFA | inline
    static inline extern_var(0x720EE0, i16*, vertCounts);

private:
    // 0x505E20 | ?BeginGfx@agiMeshSet@@AAEXXZ | inline | unused
    void BeginGfx();

    // 0x5032A0 | ?DoPageIn@agiMeshSet@@AAEXXZ | inline
    void DoPageIn();

    // 0x505E30 | ?EndGfx@agiMeshSet@@AAEXXZ | inline
    void EndGfx();

    // 0x514AF0 | ?PageInCallback@agiMeshSet@@CAXPAX@Z
    static void PageInCallback(void* arg1);

    // 0x503180 | ?PageOutCallback@agiMeshSet@@CAXPAXH@Z | inline
    static void PageOutCallback(void* arg1, i32 arg2);

    char _pad0[0x64];
};

check_size(agiMeshSet, 0x64);
