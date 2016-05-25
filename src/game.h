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

#include <cpctelera.h>
#include "defines.h"
#include "types/types.h"
#include "sprites/sprites.h"
#include "sprites/font.h"
#include "sprites/numbers.h"
#include "sprites/tilemap.h"
#include "sound/music.h"
#include "utils/itoa.h"
#include "utils/keyboard.h"
#include "text/text.h"
#include "video/video.h"
#include "video/draw.h"


#ifndef _GAME_H_
#define _GAME_H_

void init();
void spaceMoves();

#endif