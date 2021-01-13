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

define_dummy_symbol(agiworld_packnorm);

#include "packnorm.h"

#include "vector7/vector3.h"

// clang-format off
Vector3 UnpackNormal[198] {
    { 0.0000f,  0.0000f,  1.0000f }, { 1.0000f,  0.0000f,  0.0000f }, { 0.0000f,  1.0000f,  0.0000f }, {-1.0000f,  0.0000f,  0.0000f }, { 0.0000f, -1.0000f,  0.0000f }, { 0.0000f,  0.0000f, -1.0000f },
    { 0.2225f,  0.0000f,  0.9749f }, { 0.4339f,  0.0000f,  0.9010f }, { 0.6235f,  0.0000f,  0.7818f }, { 0.7818f,  0.0000f,  0.6235f }, { 0.9010f,  0.0000f,  0.4339f }, { 0.9749f,  0.0000f,  0.2225f },
    { 0.0000f,  0.2225f,  0.9749f }, { 0.0000f,  0.4339f,  0.9010f }, { 0.0000f,  0.6235f,  0.7818f }, { 0.0000f,  0.7818f,  0.6235f }, { 0.0000f,  0.9010f,  0.4339f }, { 0.0000f,  0.9749f,  0.2225f },
    {-0.2225f,  0.0000f,  0.9749f }, {-0.4339f,  0.0000f,  0.9010f }, {-0.6235f,  0.0000f,  0.7818f }, {-0.7818f,  0.0000f,  0.6235f }, {-0.9010f,  0.0000f,  0.4339f }, {-0.9749f,  0.0000f,  0.2225f },
    { 0.0000f, -0.2225f,  0.9749f }, { 0.0000f, -0.4339f,  0.9010f }, { 0.0000f, -0.6235f,  0.7818f }, { 0.0000f, -0.7818f,  0.6235f }, { 0.0000f, -0.9010f,  0.4339f }, { 0.0000f, -0.9749f,  0.2225f },
    { 0.2225f,  0.0000f, -0.9749f }, { 0.4339f,  0.0000f, -0.9010f }, { 0.6235f,  0.0000f, -0.7818f }, { 0.7818f,  0.0000f, -0.6235f }, { 0.9010f,  0.0000f, -0.4339f }, { 0.9749f,  0.0000f, -0.2225f },
    { 0.0000f,  0.2225f, -0.9749f }, { 0.0000f,  0.4339f, -0.9010f }, { 0.0000f,  0.6235f, -0.7818f }, { 0.0000f,  0.7818f, -0.6235f }, { 0.0000f,  0.9010f, -0.4339f }, { 0.0000f,  0.9749f, -0.2225f },
    {-0.2225f,  0.0000f, -0.9749f }, {-0.4339f,  0.0000f, -0.9010f }, {-0.6235f,  0.0000f, -0.7818f }, {-0.7818f,  0.0000f, -0.6235f }, {-0.9010f,  0.0000f, -0.4339f }, {-0.9749f,  0.0000f, -0.2225f },
    { 0.0000f, -0.2225f, -0.9749f }, { 0.0000f, -0.4339f, -0.9010f }, { 0.0000f, -0.6235f, -0.7818f }, { 0.0000f, -0.7818f, -0.6235f }, { 0.0000f, -0.9010f, -0.4339f }, { 0.0000f, -0.9749f, -0.2225f },
    { 0.9749f,  0.2225f,  0.0000f }, { 0.9010f,  0.4339f,  0.0000f }, { 0.7818f,  0.6235f,  0.0000f }, { 0.6235f,  0.7818f,  0.0000f }, { 0.4339f,  0.9010f,  0.0000f }, { 0.2225f,  0.9749f,  0.0000f },
    {-0.2225f,  0.9749f,  0.0000f }, {-0.4339f,  0.9010f,  0.0000f }, {-0.6235f,  0.7818f,  0.0000f }, {-0.7818f,  0.6235f,  0.0000f }, {-0.9010f,  0.4339f,  0.0000f }, {-0.9749f,  0.2225f,  0.0000f },
    {-0.9749f, -0.2225f,  0.0000f }, {-0.9010f, -0.4339f,  0.0000f }, {-0.7818f, -0.6235f,  0.0000f }, {-0.6235f, -0.7818f,  0.0000f }, {-0.4339f, -0.9010f,  0.0000f }, {-0.2225f, -0.9749f,  0.0000f },
    { 0.2225f, -0.9749f,  0.0000f }, { 0.4339f, -0.9010f,  0.0000f }, { 0.6235f, -0.7818f,  0.0000f }, { 0.7818f, -0.6235f,  0.0000f }, { 0.9010f, -0.4339f,  0.0000f }, { 0.9749f, -0.2225f,  0.0000f },
    { 0.2279f,  0.2279f,  0.9466f }, { 0.4505f,  0.2361f,  0.8610f }, { 0.2361f,  0.4505f,  0.8610f }, { 0.6533f,  0.2450f,  0.7164f }, { 0.4691f,  0.4691f,  0.7482f }, { 0.2450f,  0.6533f,  0.7164f },
    { 0.8197f,  0.2502f,  0.5153f }, { 0.6762f,  0.4815f,  0.5575f }, { 0.4815f,  0.6762f,  0.5575f }, { 0.2502f,  0.8197f,  0.5153f }, { 0.9316f,  0.2448f,  0.2685f }, { 0.8288f,  0.4740f,  0.2974f },
    { 0.6729f,  0.6729f,  0.3072f }, { 0.4740f,  0.8288f,  0.2974f }, { 0.2448f,  0.9316f,  0.2685f }, {-0.2279f,  0.2279f,  0.9466f }, {-0.2361f,  0.4505f,  0.8610f }, {-0.4505f,  0.2361f,  0.8610f },
    {-0.2450f,  0.6533f,  0.7164f }, {-0.4691f,  0.4691f,  0.7482f }, {-0.6533f,  0.2450f,  0.7164f }, {-0.2502f,  0.8197f,  0.5153f }, {-0.4815f,  0.6762f,  0.5575f }, {-0.6762f,  0.4815f,  0.5575f },
    {-0.8197f,  0.2502f,  0.5153f }, {-0.2448f,  0.9316f,  0.2685f }, {-0.4740f,  0.8288f,  0.2974f }, {-0.6729f,  0.6729f,  0.3072f }, {-0.8288f,  0.4740f,  0.2974f }, {-0.9316f,  0.2448f,  0.2685f },
    {-0.2279f, -0.2279f,  0.9466f }, {-0.4505f, -0.2361f,  0.8610f }, {-0.2361f, -0.4505f,  0.8610f }, {-0.6533f, -0.2450f,  0.7164f }, {-0.4691f, -0.4691f,  0.7482f }, {-0.2450f, -0.6533f,  0.7164f },
    {-0.8197f, -0.2502f,  0.5153f }, {-0.6762f, -0.4815f,  0.5575f }, {-0.4815f, -0.6762f,  0.5575f }, {-0.2502f, -0.8197f,  0.5153f }, {-0.9316f, -0.2448f,  0.2685f }, {-0.8288f, -0.4740f,  0.2974f },
    {-0.6729f, -0.6729f,  0.3072f }, {-0.4740f, -0.8288f,  0.2974f }, {-0.2448f, -0.9316f,  0.2685f }, { 0.2279f, -0.2279f,  0.9466f }, { 0.2361f, -0.4505f,  0.8610f }, { 0.4505f, -0.2361f,  0.8610f },
    { 0.2450f, -0.6533f,  0.7164f }, { 0.4691f, -0.4691f,  0.7482f }, { 0.6533f, -0.2450f,  0.7164f }, { 0.2502f, -0.8197f,  0.5153f }, { 0.4815f, -0.6762f,  0.5575f }, { 0.6762f, -0.4815f,  0.5575f },
    { 0.8197f, -0.2502f,  0.5153f }, { 0.2448f, -0.9316f,  0.2685f }, { 0.4740f, -0.8288f,  0.2974f }, { 0.6729f, -0.6729f,  0.3072f }, { 0.8288f, -0.4740f,  0.2974f }, { 0.9316f, -0.2448f,  0.2685f },
    { 0.2279f,  0.2279f, -0.9466f }, { 0.2361f,  0.4505f, -0.8610f }, { 0.4505f,  0.2361f, -0.8610f }, { 0.2450f,  0.6533f, -0.7164f }, { 0.4691f,  0.4691f, -0.7482f }, { 0.6533f,  0.2450f, -0.7164f },
    { 0.2502f,  0.8197f, -0.5153f }, { 0.4815f,  0.6762f, -0.5575f }, { 0.6762f,  0.4815f, -0.5575f }, { 0.8197f,  0.2502f, -0.5153f }, { 0.2448f,  0.9316f, -0.2685f }, { 0.4740f,  0.8288f, -0.2974f },
    { 0.6729f,  0.6729f, -0.3072f }, { 0.8288f,  0.4740f, -0.2974f }, { 0.9316f,  0.2448f, -0.2685f }, {-0.2279f,  0.2279f, -0.9466f }, {-0.4505f,  0.2361f, -0.8610f }, {-0.2361f,  0.4505f, -0.8610f },
    {-0.6533f,  0.2450f, -0.7164f }, {-0.4691f,  0.4691f, -0.7482f }, {-0.2450f,  0.6533f, -0.7164f }, {-0.8197f,  0.2502f, -0.5153f }, {-0.6762f,  0.4815f, -0.5575f }, {-0.4815f,  0.6762f, -0.5575f },
    {-0.2502f,  0.8197f, -0.5153f }, {-0.9316f,  0.2448f, -0.2685f }, {-0.8288f,  0.4740f, -0.2974f }, {-0.6729f,  0.6729f, -0.3072f }, {-0.4740f,  0.8288f, -0.2974f }, {-0.2448f,  0.9316f, -0.2685f },
    {-0.2279f, -0.2279f, -0.9466f }, {-0.2361f, -0.4505f, -0.8610f }, {-0.4505f, -0.2361f, -0.8610f }, {-0.2450f, -0.6533f, -0.7164f }, {-0.4691f, -0.4691f, -0.7482f }, {-0.6533f, -0.2450f, -0.7164f },
    {-0.2502f, -0.8197f, -0.5153f }, {-0.4815f, -0.6762f, -0.5575f }, {-0.6762f, -0.4815f, -0.5575f }, {-0.8197f, -0.2502f, -0.5153f }, {-0.2448f, -0.9316f, -0.2685f }, {-0.4740f, -0.8288f, -0.2974f },
    {-0.6729f, -0.6729f, -0.3072f }, {-0.8288f, -0.4740f, -0.2974f }, {-0.9316f, -0.2448f, -0.2685f }, { 0.2279f, -0.2279f, -0.9466f }, { 0.4505f, -0.2361f, -0.8610f }, { 0.2361f, -0.4505f, -0.8610f },
    { 0.6533f, -0.2450f, -0.7164f }, { 0.4691f, -0.4691f, -0.7482f }, { 0.2450f, -0.6533f, -0.7164f }, { 0.8197f, -0.2502f, -0.5153f }, { 0.6762f, -0.4815f, -0.5575f }, { 0.4815f, -0.6762f, -0.5575f },
    { 0.2502f, -0.8197f, -0.5153f }, { 0.9316f, -0.2448f, -0.2685f }, { 0.8288f, -0.4740f, -0.2974f }, { 0.6729f, -0.6729f, -0.3072f }, { 0.4740f, -0.8288f, -0.2974f }, { 0.2448f, -0.9316f, -0.2685f },
};
// clang-format on