//-----------------------------LICENSE NOTICE------------------------------------
//  This file is part of Space Moves
//  Copyright (C) 2015 Toni Ramírez (@AmstradGamer)
//
//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program.  If not, see <http://www.gnu.org/licenses/>.
//------------------------------------------------------------------------------

#include "music.h" 

__at(0x0040) const u8 G_SpaceMoves[901] = {
 0x41, 0x54, 0x31, 0x30, 0x01, 0x40, 0x42, 0x0f, 0x02, 0x06, 0x15, 0x01, 0x5c, 0x00, 0x65, 0x00,
 0xb2, 0x00, 0xcb, 0x00, 0xe5, 0x00, 0x02, 0x01, 0x31, 0x01, 0x4a, 0x01, 0x00, 0x00, 0x00, 0x00,
 0x00, 0x00, 0x0d, 0x5e, 0x00, 0x01, 0x00, 0xf0, 0xff, 0xff, 0x0c, 0xf0, 0xff, 0xff, 0x18, 0xf0,
 0x01, 0x00, 0x0c, 0xf0, 0x01, 0x00, 0x18, 0xe4, 0xff, 0xff, 0x0c, 0xe8, 0xff, 0xff, 0x18, 0xe8,
 0x01, 0x00, 0x0c, 0xe8, 0x01, 0x00, 0x18, 0xdc, 0xff, 0xff, 0x0c, 0xe0, 0xff, 0xff, 0x18, 0xe0,
 0x01, 0x00, 0x0c, 0xe0, 0x01, 0x00, 0x18, 0xd4, 0xff, 0xff, 0x0c, 0xd8, 0xff, 0xff, 0x18, 0xd8,
 0x01, 0x00, 0x0c, 0xd8, 0x01, 0x00, 0x18, 0xcc, 0xff, 0xff, 0x0c, 0xd0, 0xff, 0xff, 0x18, 0x0d,
 0x5e, 0x00, 0x01, 0x00, 0x7e, 0x2f, 0x08, 0x78, 0x06, 0x74, 0x04, 0x70, 0x02, 0xe4, 0xfe, 0xff,
 0x0c, 0xa0, 0xfe, 0xff, 0xdc, 0x02, 0x00, 0x0c, 0x0d, 0x5e, 0x00, 0x01, 0x00, 0x6c, 0x0c, 0x2c,
 0xe8, 0x02, 0x00, 0x0c, 0xa4, 0x02, 0x00, 0xe0, 0xfe, 0xff, 0x0c, 0x9c, 0xfe, 0xff, 0xd8, 0x02,
 0x00, 0x0c, 0x0d, 0x5e, 0x00, 0x01, 0x00, 0x7e, 0x2e, 0x08, 0x78, 0x06, 0x74, 0x04, 0x72, 0x25,
 0x02, 0xe6, 0x25, 0xfe, 0xff, 0x0c, 0xa2, 0x26, 0xfe, 0xff, 0xde, 0x27, 0x02, 0x00, 0x0c, 0x0d,
 0x5e, 0x00, 0x01, 0x00, 0x74, 0x0c, 0x34, 0x30, 0xac, 0x01, 0x00, 0xac, 0x01, 0x00, 0x2c, 0x2c,
 0x2c, 0xac, 0xff, 0xff, 0xac, 0xff, 0xff, 0x2c, 0x2c, 0x2c, 0xac, 0x01, 0x00, 0xac, 0x02, 0x00,
 0xac, 0x01, 0x00, 0x2c, 0x2c, 0xac, 0xff, 0xff, 0xac, 0xfe, 0xff, 0xac, 0xff, 0xff, 0x0d, 0x18,
 0x01, 0x01, 0x00, 0x7e, 0x2f, 0x03, 0x78, 0x01, 0x74, 0xff, 0x70, 0xfd, 0xe4, 0xfe, 0xff, 0x0c,
 0xa0, 0xfe, 0xff, 0xdc, 0x02, 0x00, 0x0c, 0x0d, 0x5e, 0x00, 0x01, 0x00, 0x7e, 0x2e, 0x03, 0x78,
 0x01, 0x74, 0xff, 0x72, 0x25, 0xfd, 0x66, 0x25, 0x0c, 0x22, 0x26, 0x5e, 0x27, 0x0c, 0x0d, 0x5e,
 0x00, 0x20, 0x00, 0xf4, 0x00, 0xde, 0x01, 0x00, 0xbd, 0x03, 0xfd, 0x02, 0xbd, 0x03, 0x06, 0xf4,
 0x00, 0xfd, 0x02, 0xea, 0x02, 0xdf, 0x01, 0x02, 0xf9, 0xfd, 0x02, 0x13, 0x02, 0xdf, 0x01, 0x00,
 0xfd, 0x02, 0x13, 0x02, 0xdf, 0x01, 0x0a, 0x00, 0x00, 0xfd, 0x02, 0x13, 0x02, 0x55, 0x02, 0x00,
 0xfd, 0x02, 0x77, 0x03, 0x55, 0x02, 0x0e, 0x05, 0x05, 0x05, 0xdf, 0x01, 0x90, 0x02, 0x55, 0x02,
 0x00, 0xdf, 0x01, 0x31, 0x03, 0x55, 0x02, 0x0e, 0x00, 0x00, 0x00, 0xfd, 0x02, 0x13, 0x02, 0x55,
 0x02, 0x00, 0xfd, 0x02, 0x77, 0x03, 0x55, 0x02, 0x0e, 0x05, 0x05, 0x05, 0xdf, 0x01, 0x90, 0x02,
 0x55, 0x02, 0x00, 0xdf, 0x01, 0x31, 0x03, 0x55, 0x02, 0x0e, 0x00, 0x00, 0x00, 0xfd, 0x02, 0x13,
 0x02, 0xd2, 0x02, 0x08, 0x05, 0xfd, 0x02, 0x13, 0x02, 0xdf, 0x01, 0x01, 0x86, 0x01, 0x00, 0x92,
 0xe5, 0x00, 0x00, 0x01, 0x42, 0x00, 0x53, 0x42, 0x00, 0x59, 0x42, 0x00, 0x53, 0x53, 0x42, 0x00,
 0x42, 0x00, 0x53, 0x42, 0x00, 0x61, 0x42, 0x00, 0x53, 0x42, 0x00, 0x53, 0x42, 0x00, 0x53, 0x42,
 0x00, 0x63, 0x42, 0x00, 0x53, 0x53, 0x42, 0x00, 0x42, 0x00, 0x53, 0x42, 0x00, 0x67, 0x42, 0x00,
 0x53, 0x42, 0x00, 0x84, 0xe1, 0x00, 0x00, 0x02, 0x84, 0x60, 0x03, 0x5d, 0x45, 0x84, 0x60, 0x04,
 0x84, 0x60, 0x03, 0x5d, 0x45, 0x84, 0x60, 0x02, 0x84, 0x60, 0x03, 0x5d, 0x45, 0x84, 0x60, 0x04,
 0x84, 0x60, 0x03, 0x5d, 0x45, 0x84, 0x60, 0x02, 0x84, 0x60, 0x03, 0x5d, 0x45, 0x84, 0x60, 0x04,
 0x84, 0x60, 0x03, 0x5d, 0x45, 0x84, 0x60, 0x02, 0x84, 0x60, 0x03, 0x5d, 0x45, 0x84, 0x60, 0x04,
 0x84, 0x60, 0x03, 0x5d, 0x45, 0xb4, 0xe1, 0x00, 0x00, 0x05, 0x06, 0xb4, 0x45, 0x06, 0xb4, 0x4b,
 0x02, 0xb4, 0x41, 0x02, 0x79, 0x02, 0x75, 0x02, 0x7b, 0x02, 0x42, 0x80, 0x05, 0x00, 0x42, 0x80,
 0x10, 0x00, 0xb4, 0xc0, 0x00, 0x00, 0x02, 0x7f, 0x02, 0x42, 0x80, 0x05, 0x00, 0x42, 0x80, 0x10,
 0x00, 0xb4, 0xc0, 0x00, 0x00, 0x02, 0x83, 0x02, 0x42, 0x80, 0x05, 0x00, 0x42, 0x80, 0x10, 0x00,
 0x84, 0xe0, 0x00, 0x00, 0x06, 0x84, 0x60, 0x03, 0x5d, 0x45, 0x84, 0x60, 0x07, 0x84, 0x60, 0x03,
 0x5d, 0x45, 0x84, 0x60, 0x06, 0x84, 0x60, 0x03, 0x5d, 0x45, 0x84, 0x60, 0x07, 0x84, 0x60, 0x03,
 0x5d, 0x45, 0x84, 0x60, 0x06, 0x84, 0x60, 0x03, 0x5d, 0x45, 0x84, 0x60, 0x07, 0x84, 0x60, 0x03,
 0x5d, 0x45, 0x84, 0x60, 0x06, 0x84, 0x60, 0x03, 0x5d, 0x45, 0x84, 0x60, 0x07, 0x84, 0x60, 0x03,
 0x5d, 0x45, 0xcc, 0xe1, 0x00, 0x00, 0x05, 0x06, 0x42, 0x05, 0x06, 0x42, 0x0b, 0x06, 0x42, 0x11,
 0x06, 0x42, 0x15, 0x06, 0x42, 0x19, 0x06, 0x42, 0x1d, 0x00, 0x42, 0x80, 0x00, 0x00, 0x2e, 0x84,
 0x69, 0x04, 0x02, 0x84, 0x47, 0x02, 0x84, 0x45, 0x84, 0x43, 0x84, 0x41, 0x45, 0x92, 0xe5, 0x00,
 0x00, 0x01, 0x42, 0x00, 0x53, 0x42, 0x00, 0x53, 0x42, 0x00, 0x4f, 0x53, 0x42, 0x00, 0x42, 0x00,
 0x53, 0x42, 0x00, 0x53, 0x42, 0x00, 0x4f, 0x42, 0x00, 0x53, 0x42, 0x00, 0x53, 0x42, 0x00, 0x53,
 0x42, 0x00, 0x4f, 0x53, 0x42, 0x00, 0x42, 0x00, 0x53, 0x42, 0x00, 0x53, 0x42, 0x00, 0x4f, 0x42,
 0x00, 0x84, 0xe1, 0x00, 0x00, 0x06, 0x84, 0x60, 0x03, 0x5d, 0x45, 0x84, 0x60, 0x07, 0x84, 0x60,
 0x03, 0x5d, 0x45, 0x84, 0x60, 0x06, 0x84, 0x60, 0x03, 0x5d, 0x45, 0x84, 0x60, 0x07, 0x84, 0x60,
 0x03, 0x5d, 0x45, 0x84, 0x60, 0x06, 0x84, 0x60, 0x03, 0x5d, 0x45, 0x84, 0x60, 0x07, 0x84, 0x60,
 0x03, 0x5d, 0x45, 0x84, 0x60, 0x06, 0x84, 0x60, 0x03, 0x5d, 0x45, 0x84, 0x60, 0x07, 0x84, 0x60,
 0x03, 0x84, 0x60, 0x07, 0x84, 0x60, 0x03, 0x84, 0xe0, 0x00, 0x00, 0x02, 0x84, 0x60, 0x03, 0x5d,
 0x45, 0x84, 0x60, 0x04, 0x84, 0x60, 0x03, 0x5d, 0x45, 0x84, 0x60, 0x02, 0x84, 0x60, 0x03, 0x5d,
 0x45, 0x84, 0x60, 0x04, 0x84, 0x60, 0x03, 0x5d, 0x45, 0x84, 0x60, 0x02, 0x84, 0x60, 0x03, 0x5d,
 0x45, 0x84, 0x60, 0x04, 0x84, 0x60, 0x03, 0x5d, 0x45, 0x84, 0x60, 0x02, 0x84, 0x60, 0x03, 0x5d,
 0x45, 0x84, 0x60, 0x04, 0x84, 0x60, 0x03, 0x84, 0x60, 0x04, 0x84, 0x60, 0x03, 0x42, 0x60, 0x00,
 0x42, 0x80, 0x00, 0x00, 0x00
};

__at(0x03C5) const u8 G_Menu[590] = {
    0x41, 0x54, 0x31, 0x30, 0x01, 0x40, 0x42, 0x0f, 0x02, 0x06, 0x6a, 0x00, 0xd7, 0x03, 0xe0, 0x03,
    0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0d, 0xd9, 0x03, 0x01, 0x00, 0x7a, 0x21, 0xf4,
    0x74, 0x0c, 0x30, 0x2c, 0x28, 0x24, 0x24, 0x24, 0xa4, 0xfe, 0xff, 0x24, 0xa4, 0x02, 0x00, 0x24,
    0xa4, 0xfe, 0xff, 0x24, 0xa4, 0x02, 0x00, 0x24, 0x0d, 0xed, 0x03, 0x03, 0x00, 0x78, 0x18, 0x7c,
    0x0c, 0x38, 0x78, 0xf4, 0x70, 0x18, 0x74, 0x0c, 0x30, 0x70, 0xf4, 0x68, 0x18, 0x6c, 0x0c, 0x28,
    0x68, 0xf4, 0x60, 0x18, 0x64, 0x0c, 0x20, 0x60, 0xf4, 0x58, 0x18, 0x5c, 0x0c, 0x18, 0x58, 0xf4,
    0x50, 0x18, 0x54, 0x0c, 0x10, 0x50, 0xf4, 0x48, 0x18, 0x4c, 0x0c, 0x08, 0x48, 0xf4, 0x42, 0x20,
    0x18, 0x44, 0x0c, 0x0d, 0xd9, 0x03, 0x18, 0x00, 0x00, 0x00, 0x32, 0x05, 0x00, 0xa6, 0x05, 0x33,
    0x05, 0x3b, 0x05, 0x00, 0xa6, 0x05, 0x33, 0x05, 0x3b, 0x05, 0x00, 0xa6, 0x05, 0xf4, 0x05, 0x3b,
    0x05, 0x00, 0xa6, 0x05, 0xd5, 0x05, 0x3b, 0x05, 0x0e, 0x00, 0x00, 0x00, 0xa6, 0x05, 0x6a, 0x05,
    0x3b, 0x05, 0x00, 0xa6, 0x05, 0x79, 0x05, 0x3b, 0x05, 0x0a, 0xfc, 0xfc, 0xa6, 0x05, 0x88, 0x05,
    0x3b, 0x05, 0x0a, 0xf9, 0xf9, 0xa6, 0x05, 0x97, 0x05, 0x3b, 0x05, 0x0a, 0x00, 0x00, 0xa6, 0x05,
    0x6a, 0x05, 0x3b, 0x05, 0x00, 0xa6, 0x05, 0x79, 0x05, 0x3b, 0x05, 0x0a, 0xfc, 0xfc, 0xa6, 0x05,
    0x88, 0x05, 0x3b, 0x05, 0x0a, 0xf9, 0xf9, 0xa6, 0x05, 0x97, 0x05, 0x3b, 0x05, 0x0e, 0x00, 0x04,
    0x00, 0xa6, 0x05, 0x88, 0x05, 0x3b, 0x05, 0x04, 0x00, 0xa6, 0x05, 0x33, 0x05, 0x3b, 0x05, 0x0a,
    0xfc, 0xfc, 0xa6, 0x05, 0xf4, 0x05, 0x3b, 0x05, 0x0a, 0xf9, 0xf9, 0xa6, 0x05, 0xd5, 0x05, 0x3b,
    0x05, 0x0e, 0x02, 0x02, 0x02, 0xa6, 0x05, 0x6a, 0x05, 0x3b, 0x05, 0x00, 0xa6, 0x05, 0x79, 0x05,
    0x3b, 0x05, 0x0a, 0xfe, 0xfe, 0xa6, 0x05, 0x88, 0x05, 0x3b, 0x05, 0x0a, 0xfb, 0xfb, 0xa6, 0x05,
    0x97, 0x05, 0x3b, 0x05, 0x0a, 0x02, 0x02, 0xa6, 0x05, 0x6a, 0x05, 0x3b, 0x05, 0x00, 0xa6, 0x05,
    0x79, 0x05, 0x3b, 0x05, 0x0a, 0xfe, 0xfe, 0xa6, 0x05, 0x88, 0x05, 0x3b, 0x05, 0x0a, 0xfb, 0xfb,
    0xa6, 0x05, 0x97, 0x05, 0x3b, 0x05, 0x0e, 0x02, 0x06, 0x02, 0xa6, 0x05, 0x88, 0x05, 0x3b, 0x05,
    0x04, 0x02, 0xa6, 0x05, 0x33, 0x05, 0x3b, 0x05, 0x0a, 0xfb, 0xfb, 0xa6, 0x05, 0xf4, 0x05, 0x3b,
    0x05, 0x0a, 0xfe, 0xfe, 0xa6, 0x05, 0xd5, 0x05, 0x3b, 0x05, 0x01, 0x5d, 0x04, 0x00, 0x42, 0x60,
    0x00, 0x42, 0x80, 0x00, 0x00, 0x00, 0x92, 0xe1, 0x00, 0x00, 0x01, 0x02, 0x42, 0x07, 0x92, 0x45,
    0x92, 0x43, 0x92, 0x41, 0x92, 0x40, 0x02, 0x42, 0x07, 0x92, 0x45, 0x92, 0x43, 0x92, 0x41, 0x92,
    0x40, 0x02, 0x42, 0x07, 0x92, 0x45, 0x92, 0x43, 0x92, 0x41, 0x92, 0x40, 0x02, 0x42, 0x07, 0x92,
    0x45, 0x92, 0x43, 0x92, 0x41, 0xaa, 0xe1, 0x00, 0x00, 0x02, 0x0a, 0xaa, 0x47, 0x0a, 0xaa, 0x4d,
    0x0a, 0xa0, 0x41, 0x00, 0xb4, 0xe1, 0x00, 0x00, 0x02, 0x0a, 0xb4, 0x47, 0x0a, 0xb4, 0x4d, 0x0a,
    0xaa, 0x41, 0x00, 0xa2, 0xe1, 0x00, 0x00, 0x02, 0x0a, 0xa2, 0x47, 0x0a, 0xa2, 0x4d, 0x0a, 0xa2,
    0x53, 0x00, 0xb8, 0xe1, 0x00, 0x00, 0x02, 0x0a, 0xb8, 0x47, 0x0a, 0xb8, 0x4d, 0x0a, 0xae, 0x41,
    0x00, 0x62, 0xe1, 0x00, 0x00, 0x01, 0x02, 0x42, 0x07, 0x62, 0x45, 0x62, 0x43, 0x62, 0x41, 0x62,
    0x40, 0x02, 0x42, 0x07, 0x62, 0x45, 0x62, 0x43, 0x62, 0x41, 0x62, 0x40, 0x02, 0x42, 0x07, 0x62,
    0x45, 0x62, 0x43, 0x62, 0x41, 0x62, 0x40, 0x02, 0x42, 0x07, 0x62, 0x45, 0x62, 0x43, 0x62, 0x41,
    0xaa, 0xeb, 0x00, 0x00, 0x02, 0x79, 0x83, 0x7b, 0x75, 0x79, 0xaa, 0x49, 0x79, 0x83, 0x7b, 0x75,
    0x79, 0xaa, 0x47, 0x79, 0x83, 0x7b, 0x75, 0x79, 0xaa, 0x45, 0x79, 0x83, 0x7b, 0x75, 0x79, 0xaa,
    0xf3, 0x00, 0x00, 0x02, 0x79, 0x83, 0x7b, 0x75, 0x79, 0xaa, 0x51, 0x79, 0x83, 0x7b, 0x75, 0x79,
    0xaa, 0x4f, 0x79, 0x83, 0x7b, 0x75, 0x79, 0xaa, 0x4d, 0x79, 0x83, 0x7b, 0x75, 0x79
};

extern __at(0x0613) const u8 G_FX[389] = {
    0x41, 0x54, 0x31, 0x30, 0x01, 0x40, 0x42, 0x0f, 0x02, 0xff, 0x63, 0x01, 0x2b, 0x06, 0x34, 0x06,
    0x5d, 0x06, 0xa1, 0x06, 0xd4, 0x06, 0x14, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0d, 0x2d,
    0x06, 0x01, 0x00, 0x3a, 0x2b, 0x72, 0x38, 0x04, 0x76, 0x3d, 0x06, 0x76, 0x39, 0x08, 0x72, 0x2a,
    0x0a, 0x32, 0x0a, 0x32, 0x09, 0x2e, 0x0c, 0x2e, 0x0c, 0x26, 0x0c, 0x22, 0x0f, 0x1e, 0x11, 0x1a,
    0x13, 0x16, 0x17, 0x12, 0x19, 0x0e, 0x1c, 0x0d, 0x2d, 0x06, 0x02, 0x00, 0x7e, 0x3f, 0xfa, 0x7e,
    0x3f, 0xfa, 0x7a, 0x3f, 0xf9, 0x7a, 0x3f, 0xf9, 0x76, 0x3f, 0xf8, 0x72, 0x3e, 0xf8, 0x72, 0x3d,
    0xf7, 0x6e, 0x3e, 0xf7, 0x6e, 0x3f, 0xf6, 0x6a, 0x3f, 0xf6, 0x6a, 0x3e, 0xf5, 0x66, 0x3d, 0xf5,
    0x62, 0x3e, 0xf4, 0x5e, 0x3e, 0xf4, 0x5a, 0x3e, 0xf4, 0x56, 0x3d, 0xf4, 0x52, 0x3d, 0xf4, 0x4e,
    0x3d, 0xf4, 0x4a, 0x3e, 0xf4, 0x46, 0x3f, 0xf4, 0x46, 0x3f, 0xf4, 0x0d, 0x2d, 0x06, 0x01, 0x00,
    0x7a, 0x23, 0xf2, 0x7a, 0x23, 0x21, 0x76, 0x22, 0x1b, 0x72, 0x22, 0x09, 0x2e, 0x22, 0xaa, 0x21,
    0x03, 0x00, 0xa6, 0x21, 0x06, 0x00, 0xa0, 0x09, 0x00, 0x9c, 0x0c, 0x00, 0x98, 0x0f, 0x00, 0x94,
    0x12, 0x00, 0x90, 0x15, 0x00, 0x8c, 0x18, 0x00, 0x88, 0x1b, 0x00, 0x84, 0x1f, 0x00, 0x0d, 0x2d,
    0x06, 0x02, 0x00, 0x3e, 0x3d, 0x7a, 0x3a, 0xff, 0x7a, 0x3c, 0xfe, 0x76, 0x3d, 0xfd, 0x72, 0x3c,
    0xfc, 0x6e, 0x3a, 0xfb, 0x6a, 0x37, 0xfa, 0x6a, 0x35, 0xf9, 0x6a, 0x34, 0xf8, 0x6a, 0x33, 0xf7,
    0x62, 0x33, 0xf6, 0x62, 0x33, 0xf5, 0x62, 0x33, 0xf4, 0x5a, 0x33, 0xf3, 0x56, 0x35, 0xf2, 0x52,
    0x36, 0xf1, 0x52, 0x36, 0xf0, 0x4e, 0x37, 0xef, 0x4e, 0x37, 0xee, 0x4a, 0x36, 0xed, 0x0d, 0x2d,
    0x06, 0x01, 0x00, 0x74, 0x08, 0xf8, 0xff, 0xff, 0x03, 0xfc, 0xfe, 0xff, 0x07, 0xfc, 0xfd, 0xff,
    0x01, 0xb8, 0xfc, 0xff, 0xf8, 0xfb, 0xff, 0x08, 0xf4, 0xfa, 0xff, 0x03, 0xf4, 0xf9, 0xff, 0x07,
    0xf0, 0xf8, 0xff, 0x01, 0xb0, 0xf7, 0xff, 0xec, 0xf6, 0xff, 0x08, 0xec, 0xf5, 0xff, 0x03, 0xe8,
    0xf4, 0xff, 0x07, 0xe8, 0xf3, 0xff, 0x01, 0xa4, 0xf2, 0xff, 0xe4, 0xf1, 0xff, 0x08, 0xe0, 0xf0,
    0xff, 0x03, 0xe0, 0xef, 0xff, 0x07, 0xdc, 0xee, 0xff, 0x01, 0x9c, 0xed, 0xff, 0xd8, 0xec, 0xff,
    0x08, 0xd8, 0xeb, 0xff, 0x03, 0xd4, 0xea, 0xff, 0x07, 0xd4, 0xe9, 0xff, 0x01, 0x90, 0xe8, 0xff,
    0xcc, 0xe7, 0xff, 0x08, 0xc8, 0xe6, 0xff, 0x03, 0xc4, 0xe5, 0xff, 0x07, 0x0d, 0x2d, 0x06, 0x40,
    0x00, 0x00, 0x00, 0x92, 0x07, 0x00, 0x93, 0x07, 0x93, 0x07, 0x93, 0x07, 0x01, 0x88, 0x07, 0x00,
    0x42, 0x80, 0x00, 0x00, 0x00
};

