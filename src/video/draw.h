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
#include "../defines.h"
#include "../sprites/sprites.h"
#include "../types/types.h"
#include "../text/text.h"

#ifndef _DRAW_H_
#define _DRAW_H_

extern u8 shift;
extern u16 tilemapPos;
extern u8 gameOver;
extern u8 pause;
extern u16 score;
extern u8 lifes;
extern u16 distance;

void addEnemyBike(u8 xPos, u8 yPos, EnemyBike *enemyBikes);
void addEnemy(u8 type, u8 xPos, u8 yPos, u8 pattern, u8 width, u8 height, u8 xSpeed, u8 ySpeed, u8 fixed, Enemy *enemies);
void drawFloor(u8 move);
void drawBike(Bike *bike, EnemyBike *enemyBikes);
void drawShip(Ship *ship);
void drawEnemyBikes(EnemyBike *enemyBikes, Bike *bike, Bullet *bullets);
void drawEnemyShips(Enemy *enemies, Ship *ship, Bullet *bullets);
void drawMenu();
void drawClippedSprite(u8* sprite, u8 xPos, u8 yPos, u8 width, u8 height, u8 masked);
void drawSelector(u8 color, u8 xPos, u8 yPos);
void clearGameScreenBike();
void clearGameScreen();
void drawFrame(u8 buffer);
void drawStar(u8 color1, u8 color2, u8 xPos, u8 yPos);
void drawStars(Coords *stars);
void drawBullet(u8 xPos, u8 yPos);
void drawLaser(u8 xPos, u8 yPos) ;
void drawBullets(Bullet *bullets);
void drawLasers(Bullet *bullets);
void drawClouds(Coords *clouds);

#endif