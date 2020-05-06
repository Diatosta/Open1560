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

define_dummy_symbol(mmphysics_joint3dof);

#include "joint3dof.h"

Joint3Dof::Joint3Dof()
{
    unimplemented();
}

Joint3Dof::~Joint3Dof()
{
    unimplemented(arg1);
}

void Joint3Dof::GetCMatrix(
    class asInertialCS const* arg1, class asInertialCS const* arg2, class Matrix34& arg3, class Vector3 const& arg4)
{
    return stub<thiscall_t<void, Joint3Dof*, class asInertialCS const*, class asInertialCS const*, class Matrix34&,
        class Vector3 const&>>(0x4DE3B0, this, arg1, arg2, arg3, arg4);
}

void Joint3Dof::GetCMatrix(class asInertialCS const* arg1, class Matrix34& arg2, class Vector3 const& arg3)
{
    return stub<thiscall_t<void, Joint3Dof*, class asInertialCS const*, class Matrix34&, class Vector3 const&>>(
        0x4DE050, this, arg1, arg2, arg3);
}

void Joint3Dof::AddWidgets(class Bank* arg1)
{
    return stub<thiscall_t<void, Joint3Dof*, class Bank*>>(0x4DE9A0, this, arg1);
}

void Joint3Dof::BreakJoint()
{
    return stub<thiscall_t<void, Joint3Dof*>>(0x4DD3A0, this);
}

void Joint3Dof::DoJointLimits(f32 arg1, class Vector3 const& arg2, f32 arg3, class Vector3 const& arg4,
    class Vector3& arg5, class Matrix34 const& arg6, class Matrix34 const& arg7, class Matrix34 const& arg8,
    class Matrix34 const& arg9, class Matrix34 const& arg10)
{
    return stub<thiscall_t<void, Joint3Dof*, f32, class Vector3 const&, f32, class Vector3 const&, class Vector3&,
        class Matrix34 const&, class Matrix34 const&, class Matrix34 const&, class Matrix34 const&,
        class Matrix34 const&>>(0x4DD990, this, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10);
}

void Joint3Dof::DoJointTorque(class Matrix34 const& arg1, class Matrix34 const& arg2, class Matrix34 const& arg3,
    class Matrix34 const& arg4, f32& arg5, f32& arg6, class Vector3& arg7, f32& arg8, f32& arg9)
{
    return stub<thiscall_t<void, Joint3Dof*, class Matrix34 const&, class Matrix34 const&, class Matrix34 const&,
        class Matrix34 const&, f32&, f32&, class Vector3&, f32&, f32&>>(
        0x4DD400, this, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9);
}

class MetaClass* Joint3Dof::GetClass()
{
    return stub<thiscall_t<class MetaClass*, Joint3Dof*>>(0x4DEB20, this);
}

void Joint3Dof::Init()
{
    return stub<thiscall_t<void, Joint3Dof*>>(0x4DBC70, this);
}

void Joint3Dof::InitJoint3Dof(
    class asInertialCS* arg1, class Vector3 const& arg2, class asInertialCS* arg3, class Vector3 const& arg4)
{
    return stub<thiscall_t<void, Joint3Dof*, class asInertialCS*, class Vector3 const&, class asInertialCS*,
        class Vector3 const&>>(0x4DBCF0, this, arg1, arg2, arg3, arg4);
}

void Joint3Dof::MoveICS()
{
    return stub<thiscall_t<void, Joint3Dof*>>(0x4DD350, this);
}

void Joint3Dof::Reset()
{
    return stub<thiscall_t<void, Joint3Dof*>>(0x4DBCE0, this);
}

void Joint3Dof::SetForceLimit(f32 arg1)
{
    return stub<thiscall_t<void, Joint3Dof*, f32>>(0x4DC040, this, arg1);
}

void Joint3Dof::SetFrictionLean(f32 arg1, f32 arg2, f32 arg3)
{
    return stub<thiscall_t<void, Joint3Dof*, f32, f32, f32>>(0x4DBE90, this, arg1, arg2, arg3);
}

void Joint3Dof::SetFrictionRoll(f32 arg1, f32 arg2, f32 arg3)
{
    return stub<thiscall_t<void, Joint3Dof*, f32, f32, f32>>(0x4DBEC0, this, arg1, arg2, arg3);
}

void Joint3Dof::SetJointForceFlag()
{
    return stub<thiscall_t<void, Joint3Dof*>>(0x4DC050, this);
}

void Joint3Dof::SetLeanLimit(f32 arg1, f32 arg2)
{
    return stub<thiscall_t<void, Joint3Dof*, f32, f32>>(0x4DBEF0, this, arg1, arg2);
}

void Joint3Dof::SetPosition(class Vector3 const& arg1)
{
    return stub<thiscall_t<void, Joint3Dof*, class Vector3 const&>>(0x4DBD70, this, arg1);
}

void Joint3Dof::SetRestOrientMat(class Matrix34 const& arg1)
{
    return stub<thiscall_t<void, Joint3Dof*, class Matrix34 const&>>(0x4DBFB0, this, arg1);
}

void Joint3Dof::SetRestOrientMat(class Matrix34 const& arg1, class Matrix34 const& arg2)
{
    return stub<thiscall_t<void, Joint3Dof*, class Matrix34 const&, class Matrix34 const&>>(0x4DBFF0, this, arg1, arg2);
}

void Joint3Dof::SetRestOrientation()
{
    return stub<thiscall_t<void, Joint3Dof*>>(0x4DBF40, this);
}

void Joint3Dof::SetRollLimit(f32 arg1, f32 arg2, f32 arg3)
{
    return stub<thiscall_t<void, Joint3Dof*, f32, f32, f32>>(0x4DBF10, this, arg1, arg2, arg3);
}

void Joint3Dof::SetRotate1(class Matrix34 const& arg1)
{
    return stub<thiscall_t<void, Joint3Dof*, class Matrix34 const&>>(0x4DBE50, this, arg1);
}

void Joint3Dof::SetRotate2(class Matrix34 const& arg1)
{
    return stub<thiscall_t<void, Joint3Dof*, class Matrix34 const&>>(0x4DBE70, this, arg1);
}

void Joint3Dof::UnbreakJoint()
{
    return stub<thiscall_t<void, Joint3Dof*>>(0x4DD3D0, this);
}

void Joint3Dof::Update()
{
    return stub<thiscall_t<void, Joint3Dof*>>(0x4DC0F0, this);
}

void Joint3Dof::DeclareFields()
{
    return stub<cdecl_t<void>>(0x4DE9B0);
}

JointedStruct::~JointedStruct()
{
    unimplemented();
}

void CrossProdMatrix(class Matrix34* arg1, class Vector3 const& arg2)
{
    return stub<cdecl_t<void, class Matrix34*, class Vector3 const&>>(0x4DECD0, arg1, arg2);
}
