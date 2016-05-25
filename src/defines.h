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

#ifndef _DEFINES_H_
#define _DEFINES_H_

// Pointer to the video buffer and back buffer
#define SCR_VMEM (u8*)0xC000
#define SCR_BUFF (u8*)0x8000

//Screen Sizes

#define MIN_X  9
#define MIN_Y  5
#define MAX_X  MIN_X + (FRAME_WIDTH - 2) * FONT_W + 1
#define MAX_Y  MIN_Y + (FRAME_HEIGHT/2 - 1) * FONT_H - 1


//Sprites Size
#define FONT_H 8
#define FONT_W 2

//Clouds

#define CLOUD_H 13
#define CLOUD_W 11
#define MAX_CLOUDS 2


//SHIP
#define SHIP_H 18
#define SHIP_W 11

#define BIG_SHIP_H 35
#define BIG_SHIP_W 22

#define LASER_H 8
#define LASER_W 10

#define SHIP_MAX_BULLETS  2
#define SHIP_BULLET_SPEED 4

#define FLAME_H 7
#define FLAME_W 4

#define SHIP_STATE_GOING_RIGHT     0
#define SHIP_STATE_GOING_LEFT      1
#define SHIP_STATE_INMUNE          2
#define SHIP_STATE_EXPLOSION_A     3
#define SHIP_STATE_EXPLOSION_B     4

//METAL
#define METAL_H 16
#define METAL_W  6

//BIKE
#define BIKE_H 31
#define BIKE_W 10

#define ENEMY_BIKE_H 28
#define ENEMY_BIKE_W 10

#define MAX_ENEMY_BIKES 3

#define BIKE_FLOOR_Y MIN_Y + (MAX_Y - MIN_Y) / 2 + 1
#define BIKE_JUMP_Y BIKE_FLOOR_Y - 20

#define ENEMY_BIKE_FLOOR_Y BIKE_FLOOR_Y + 2

#define BIKE_STATE_ON_FLOOR      0
#define BIKE_STATE_JUMPING_UP    1
#define BIKE_STATE_JUMPING_DOWN  2
#define BIKE_STATE_FALL_TO_DEATH 3
#define BIKE_STATE_EXPLOSION_A   4
#define BIKE_STATE_EXPLOSION_B   5
#define BIKE_STATE_INMUNE        6

#define BIKE_JUMP_SPEED          6

#define BIKE_MAX_BULLETS         2
#define BIKE_BULLET_SPEED        4
#define BIKE_BULLET_H            5
#define BIKE_BULLET_W            2


//FALLING TEXT
#define FALLING_TEXT_SPEED  4
#define FALLING_TEXT_MAX_BOUNCES 8
#define FALLING_TEXT_MAX_LENGHT  11

//STARS
#define MAX_STARS 8
#define MAX_COLOR_STARS 3

#define COLOR_STAR_W 2
#define COLOR_STAR_H 7

//ENEMY SHIPS

#define ENEMY_TYPE_1 1
#define ENEMY_TYPE_1_H 15
#define ENEMY_TYPE_1_W  9

#define ENEMY_TYPE_2 2
#define ENEMY_TYPE_2_H 15
#define ENEMY_TYPE_2_W  6

#define ENEMY_TYPE_3 3
#define ENEMY_TYPE_3_H 14
#define ENEMY_TYPE_3_W  6

#define ENEMY_TYPE_4 4
#define ENEMY_TYPE_4_H 14
#define ENEMY_TYPE_4_W  6

#define ENEMY_TYPE_METEORO 6
#define ENEMY_TYPE_METEORO_H 14
#define ENEMY_TYPE_METEORO_W  5

#define ENEMY_TYPE_ESCAPE   10
#define ENEMY_TYPE_ESCAPE_H 27
#define ENEMY_TYPE_ESCAPE_W 6

#define ENEMY_TYPE_BIGFLAME   11
#define ENEMY_TYPE_BIGFLAME_H 25
#define ENEMY_TYPE_BIGFLAME_W 9

#define ENEMY_TYPE_BULLET 12

#define MOON_W 13
#define MOON_H 47

#define MAX_ENEMIES 10

#define ENEMY_STATE_INACTIVE     0
#define ENEMY_STATE_ACTIVE       1
#define ENEMY_STATE_EXPLOSION_A  2
#define ENEMY_STATE_EXPLOSION_B  3

//EXPLOSION

#define EXPLOSION_H 18
#define EXPLOSION_W  6

#define true  1
#define false 0

//DISTANCES

#define BIKE_DISTANCE 1800
#define SHIP_DISTANCE  950

#define MAX_MOVEMENTS 3

//MOUTAINS

#define MOUNTAIN1_H 50
#define MOUNTAIN1_W 17
#define MOUNTAIN2_H 34
#define MOUNTAIN2_W 18




#endif