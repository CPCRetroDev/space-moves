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

#include <types.h>

#define FRAME_TILESIZE  2*4
#define FRAME_WIDTH      32
#define FRAME_HEIGHT     28

#define FLOOR_TILESIZE  4*8
#define FLOOR_NUMTILES    7
#define FLOOR_WIDTH    1016
#define FLOOR_HEIGHT      1

extern const u8 G_frame_0[FRAME_TILESIZE];
extern const u8 G_frame_1[FRAME_TILESIZE];
extern const u8 G_frame_2[FRAME_TILESIZE];
extern const u8 G_frame_3[FRAME_TILESIZE];
extern const u8 G_frame_4[FRAME_TILESIZE];
extern const u8 G_frame_5[FRAME_TILESIZE];
extern const u8 G_frame_6[FRAME_TILESIZE];
extern const u8 G_frame_7[FRAME_TILESIZE];


extern const u8 G_floor_0[FLOOR_TILESIZE];
extern const u8 G_floor_1[FLOOR_TILESIZE];
extern const u8 G_floor_2[FLOOR_TILESIZE];
extern const u8 G_floor_3[FLOOR_TILESIZE];
extern const u8 G_floor_4[FLOOR_TILESIZE];
extern const u8 G_floor_5[FLOOR_TILESIZE];
extern const u8 G_floor_6[FLOOR_TILESIZE];


// Declaration of the tileset
extern u8* const g_floorTileset[FLOOR_NUMTILES];

// Declaration of the tilemap
extern const u8 g_floorTilemap[FLOOR_WIDTH * FLOOR_HEIGHT];