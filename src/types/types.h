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


#ifndef _TYPES_H_
#define _TYPES_H_

#include <cpctelera.h>

typedef struct FChar{
    
    u8 phase;
    u8 xPos;
    u8 yPos;
    u8 startyPos;
    u8 endyPos;
    u8 destinationyPos;
    u8 character[2];
    
} FChar;

typedef struct Keys{
    
    cpct_keyID up;
    cpct_keyID down;
    cpct_keyID left;
    cpct_keyID right;
    cpct_keyID fire;
    cpct_keyID pause;
    cpct_keyID abort;
    
} Keys;

typedef struct Bike{
    
    u8 xPos;
    u8 yPos;
    u8 state;
    u8 cycles;
    
} Bike;

typedef struct Ship{
    
    u8 xPos;
    u8 yPos;
    u8 state;
    u8 cycles;
    
} Ship;

typedef struct Enemy{
    
    u8 type;
    u8 xPos;
    u8 yPos;
    u8 xSpeed;
    u8 ySpeed;
    u8 width;
    u8 height;
    u8 state;
    u8 cycles;
    u8 pattern;
    u8 movements;
    u8 fixed;
    
} Enemy;

typedef struct EnemyBike{
    
    u8 xPos;
    u8 yPos;
    u8 state;
    u8 cycles;
    
} EnemyBike;

typedef struct Bullet{
    
    u8 xPos;
    u8 yPos;
    u8 active;
    
} Bullet;


typedef struct Coords{
    u8 xPos;
    u8 yPos;
} Coords;

#endif