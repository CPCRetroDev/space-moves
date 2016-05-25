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

#include "draw.h"

u8 shift;
u16 tilemapPos;
u8 gameOver;
u8 pause;
u16 score;
u8 lifes;
u16 distance;


const Coords patterns[8][MAX_MOVEMENTS] =

{
    {{13, 0}, {10, 0}, {7, 0}},
    {{MAX_X - 8, MAX_Y - 20}, {MIN_X, MIN_Y}, {MAX_X + 10, MIN_Y}},
    {{MIN_X, MIN_Y}, {MAX_X - 8, MAX_Y - 20}, {3, MAX_Y - 20}},
    {{MAX_X - ENEMY_TYPE_ESCAPE_W + 1, MIN_Y}, {MAX_X - ENEMY_TYPE_ESCAPE_W + 1, MIN_Y}, {MAX_X - ENEMY_TYPE_ESCAPE_W + 1, MIN_Y}},
    {{MAX_X - ENEMY_TYPE_ESCAPE_W + 1, MAX_Y - ENEMY_TYPE_ESCAPE_H}, {MAX_X - ENEMY_TYPE_ESCAPE_W + 1, MAX_Y - ENEMY_TYPE_ESCAPE_H}, {MAX_X - ENEMY_TYPE_ESCAPE_W + 1, MAX_Y - ENEMY_TYPE_ESCAPE_H}},
    {{MAX_X - ENEMY_TYPE_ESCAPE_W - ENEMY_TYPE_BIGFLAME_W + 1, 0}, {MAX_X - ENEMY_TYPE_ESCAPE_W - ENEMY_TYPE_BIGFLAME_W + 1, 0}, {MAX_X - ENEMY_TYPE_ESCAPE_W - ENEMY_TYPE_BIGFLAME_W + 1, 0}},
    {{MAX_X - ENEMY_TYPE_ESCAPE_W - ENEMY_TYPE_BIGFLAME_W + 1, 0}, {MAX_X - ENEMY_TYPE_ESCAPE_W - ENEMY_TYPE_BIGFLAME_W + 1, 0}, {MAX_X - ENEMY_TYPE_ESCAPE_W - ENEMY_TYPE_BIGFLAME_W + 1, 0}},
    {{MAX_X + 1, 0}, {MAX_X + 1, 0}, {MAX_X + 1, 0}}
    
    
};

void addEnemyBike(u8 xPos, u8 yPos, EnemyBike *enemyBikes){
    
    u8 x;
    
    for(x=0;x<MAX_ENEMY_BIKES;x++){
        
        if(enemyBikes[x].state == ENEMY_STATE_INACTIVE){
            
            
            enemyBikes[x].state        = ENEMY_STATE_ACTIVE;
            enemyBikes[x].xPos         = xPos;
            enemyBikes[x].yPos         = yPos;
            enemyBikes[x].cycles       = 0;
            
            break;
            
        }
    }
    
    
}

void addEnemy(u8 type, u8 xPos, u8 yPos, u8 pattern, u8 width, u8 height, u8 xSpeed, u8 ySpeed, u8 fixed, Enemy *enemies){
    
    u8 x;
    
    for(x=0;x<MAX_ENEMIES;x++){
        
        if(enemies[x].state == ENEMY_STATE_INACTIVE){
            
            enemies[x].type         = type;
            enemies[x].state        = ENEMY_STATE_ACTIVE;
            enemies[x].xPos         = xPos;
            enemies[x].yPos         = yPos;
            enemies[x].pattern      = pattern;
            enemies[x].width        = width;
            enemies[x].height       = height;
            enemies[x].xSpeed       = xSpeed;
            enemies[x].ySpeed       = ySpeed;
            enemies[x].fixed        = fixed;
            enemies[x].cycles       = 0;
            enemies[x].movements    = 0;
            
            if(!fixed) cpct_akp_SFXPlay(5, 15, 57, 0, 0, AY_CHANNEL_A);
                
            break;
            
        }
    }
    
    
}

void drawFloor(u8 move) {
    
    u8 x;
    u8* pvideo2;
    u8 tile;
    
    u8* pvideo = cpct_getScreenPtr(g_scrbuffers[1], MIN_X, BIKE_FLOOR_Y + BIKE_H);
    
    if(shift == 0 || !move){
        
        for(x=0;x<15;x++){
            
            tile = g_floorTilemap[tilemapPos + x];
            if(tile == 9) tile = 1;
            
            cpct_drawTileAligned4x8_f(g_floorTileset[tile],  pvideo + 4 * x);
            
        }
        
        for(x=0;x<15;x++){
            
            tile = g_floorTilemap[tilemapPos + x];
            if(tile == 9) tile = 1;
            
            pvideo = cpct_getScreenPtr(g_scrbuffers[1], MIN_X, BIKE_FLOOR_Y + BIKE_H + 8);
            cpct_drawTileAligned4x8_f(g_floorTileset[tile != 0 ? tile + 1 : 0],  pvideo + 4 * x);
            
        }
        
        //Fill the gap
        tile = g_floorTilemap[tilemapPos + x];
        if(tile == 9) tile = 1;
        
        drawClippedSprite(g_floorTileset[tile], MIN_X + 4 * 15, BIKE_FLOOR_Y + BIKE_H, 4, 8, false);
        drawClippedSprite(g_floorTileset[tile != 0 ? tile + 1 : 0], MIN_X + 4 * 15, BIKE_FLOOR_Y + BIKE_H + 8, 4, 8, false);
        
    }
    else{
        
        //Scroll
        pvideo2 = cpct_getScreenPtr(g_scrbuffers[0], MIN_X, BIKE_FLOOR_Y + BIKE_H);
        
        for(x=0;x<16;x++){
            
            cpct_memcpy(pvideo, pvideo2 + 2, 4 * 15 - 2);
            
            pvideo  = cpct_getScreenPtr(g_scrbuffers[1], MIN_X, BIKE_FLOOR_Y + BIKE_H + x + 1);
            pvideo2 = cpct_getScreenPtr(g_scrbuffers[0], MIN_X, BIKE_FLOOR_Y + BIKE_H + x + 1);
        }
        
        //Fill the gap
        tile = g_floorTilemap[tilemapPos + 15];
        if(tile == 9) tile = 1;
        
        //if(tile != 0){
            
            drawClippedSprite(g_floorTileset[tile], MIN_X + 4 * 15 - shift - 1, BIKE_FLOOR_Y + BIKE_H, 4, 8, false);
            drawClippedSprite(g_floorTileset[tile == 0 ? tile : tile + 1], MIN_X + 4 * 15 - shift - 1, BIKE_FLOOR_Y + BIKE_H + 8, 4, 8, false);
            
        //}
    }
    
    if(move){
        
        if(++shift == 2){
            
            shift = 0;
            tilemapPos++;
            score++;
        }
        
    }
}

void drawBike(Bike *bike, EnemyBike *enemyBikes) {
    
    u8 x;
    
    u8* pvideo = cpct_getScreenPtr(g_scrbuffers[1], bike->xPos, bike->yPos);
    
    switch (bike->state) {
            
        case BIKE_STATE_ON_FLOOR:
            
            //On a solid tile (!= 0)
            if(g_floorTilemap[tilemapPos + (bike->xPos + (BIKE_W / 2) + shift - MIN_X) / 4 - 1]){
                
                if(bike->cycles < 2){
                    cpct_drawSpriteMasked(G_bike, pvideo, BIKE_W, BIKE_H);
                }
                else if(bike->cycles < 4){
                    cpct_drawSpriteMasked(G_bike2, pvideo, BIKE_W, BIKE_H);
                }
                
                if(++bike->cycles == 4) bike->cycles = 0;
            }
            else{
                
                bike->yPos += BIKE_JUMP_SPEED;
                pvideo = cpct_getScreenPtr(g_scrbuffers[1], bike->xPos, bike->yPos);
                
                cpct_drawSpriteMasked(G_bike3, pvideo, BIKE_W, BIKE_H);
                bike->state = BIKE_STATE_FALL_TO_DEATH;
                bike->cycles = 0;
                
            }
            
            break;
            
            
        case BIKE_STATE_JUMPING_UP:
            
            cpct_drawSpriteMasked(G_bike2, pvideo, BIKE_W, BIKE_H);
            
            if(bike->yPos > BIKE_JUMP_Y) bike->yPos -= BIKE_JUMP_SPEED;
            else bike->state = BIKE_STATE_JUMPING_DOWN;
            
            break;
            
        case BIKE_STATE_JUMPING_DOWN:
            
            cpct_drawSpriteMasked(G_bike3, pvideo, BIKE_W, BIKE_H);
            
            if(bike->yPos < BIKE_FLOOR_Y) bike->yPos += BIKE_JUMP_SPEED;
            else{
                
                if(g_floorTilemap[tilemapPos + (bike->xPos + 5 + shift - MIN_X) / 4 - 1]){
                    
                    bike->state = BIKE_STATE_ON_FLOOR;
                }
                else{
                    
                    bike->yPos += BIKE_JUMP_SPEED;
                    
                    cpct_drawSpriteMasked(G_bike3, pvideo, BIKE_W, BIKE_H);
                    bike->state = BIKE_STATE_FALL_TO_DEATH;
                }
                
            }
            
            break;
            
        case BIKE_STATE_FALL_TO_DEATH:
            
            cpct_drawSpriteMasked(G_bike3, pvideo, BIKE_W, BIKE_H);
            
            bike->yPos += BIKE_JUMP_SPEED;
            
            if(bike->yPos + BIKE_H >= MAX_Y - 4){
                
                bike->yPos = MAX_Y - EXPLOSION_H - 4;
                bike->state = BIKE_STATE_EXPLOSION_A;
                bike->cycles = 0;
                
                cpct_akp_SFXPlay (2, 15, 36, 0, 0, AY_CHANNEL_A);
                
            }
            
            break;
            
        case BIKE_STATE_EXPLOSION_A:
            
            drawClippedSprite(G_explosiona, bike->xPos, bike->yPos, EXPLOSION_W, EXPLOSION_H, true);
            
            if(bike->cycles++ == 2){
                
                bike->state = BIKE_STATE_EXPLOSION_B;
                bike->cycles = 0;
            }
            
            break;
            
        case BIKE_STATE_EXPLOSION_B:
            
            drawClippedSprite(G_explosionb, bike->xPos, bike->yPos, EXPLOSION_W, EXPLOSION_H, true);
            
            if(bike->cycles++ == 2){
                
                if(--lifes == 0){
                    
                    gameOver = true;
                }
                else{
                    
                    bike->state = BIKE_STATE_INMUNE;
                    bike->cycles = 0;
                    
                }
                
            }
            
            break;
            
        case BIKE_STATE_INMUNE:
            
            if(bike->cycles++ == 2){
                
                for(x=0;x<MAX_ENEMY_BIKES;x++){
                    
                    enemyBikes[x].state = ENEMY_STATE_INACTIVE;
                }
                
                bike->state = BIKE_STATE_ON_FLOOR;
                bike->xPos  = MIN_X + 6;
                bike->yPos  = BIKE_FLOOR_Y;
                bike->cycles = 0;
                
                distance = BIKE_DISTANCE;
                
                tilemapPos = 0;
                shift = 0;
                
            }
            
            break;
            
        default:
            
            break;
    }
    
    
}

void drawShip(Ship *ship) {
    
    u8* pvideo;
    
    
    switch (ship->state) {
            
        case SHIP_STATE_GOING_RIGHT:
            
            pvideo = cpct_getScreenPtr(g_scrbuffers[1], ship->xPos, ship->yPos);
            
            cpct_drawSpriteMasked(G_ship, pvideo, SHIP_W, SHIP_H);
            
            pvideo = cpct_getScreenPtr(g_scrbuffers[1], ship->xPos - FLAME_W, ship->yPos + SHIP_H / 2 - 4);
            
            if(ship->cycles < 4){
                
                drawClippedSprite(G_flame, ship->xPos - FLAME_W, ship->yPos + SHIP_H / 2 - 4, FLAME_W, FLAME_H, true);
                
            }
            else if(ship->cycles < 8){
                
                drawClippedSprite(G_flame2, ship->xPos - FLAME_W, ship->yPos + SHIP_H / 2 - 4, FLAME_W, FLAME_H, true);
                
            }
            
            ship->cycles++;
            
            if(ship->cycles == 8) ship->cycles = 0;
            
            break;
            
        case SHIP_STATE_GOING_LEFT:
            
            pvideo = cpct_getScreenPtr(g_scrbuffers[1], ship->xPos, ship->yPos);
            
            cpct_drawSpriteMasked(G_ship, pvideo, SHIP_W, SHIP_H);
            
            break;
            
        case SHIP_STATE_EXPLOSION_A:
            
            drawClippedSprite(G_explosiona, ship->xPos, ship->yPos, EXPLOSION_W, EXPLOSION_H, true);
            
            if(ship->cycles++ == 2){
                
                ship->state = SHIP_STATE_EXPLOSION_B;
                ship->cycles = 0;
            }
            
            break;
            
        case SHIP_STATE_EXPLOSION_B:
            
            drawClippedSprite(G_explosionb, ship->xPos, ship->yPos, EXPLOSION_W, EXPLOSION_H, true);
            
            if(ship->cycles++ == 2){
                
                if(--lifes == 0){
                    
                    gameOver = true;
                }
                else{
                    
                    ship->state = SHIP_STATE_INMUNE;
                    ship->xPos = MIN_X;
                    ship->yPos = (MAX_Y - MIN_Y) / 2 - 4;
                    ship->cycles = 0;
                }
                
            }
            
            break;
            
        case SHIP_STATE_INMUNE:
            
            pvideo = cpct_getScreenPtr(g_scrbuffers[1], ship->xPos, ship->yPos);
            
            if(ship->cycles++ % 4 == 0){
                
                cpct_drawSpriteMasked(G_ship, pvideo, SHIP_W, SHIP_H);
                
            }
            
            if(ship->cycles == 16){
                
                ship->state = SHIP_STATE_GOING_LEFT;
                ship->cycles = 0;
                
            }
            
            break;
            
        default:
            
            break;
    }
    
    
}

void drawEnemyBikes(EnemyBike *enemyBikes, Bike *bike, Bullet *bullets){
    
    
    u8 x, y;
    
    for(x=0;x<MAX_ENEMY_BIKES;x++){
        
        switch (enemyBikes[x].state) {
                
            case ENEMY_STATE_ACTIVE:
                
                if(enemyBikes[x].cycles < 2){
                    drawClippedSprite(G_bike_enemy, enemyBikes[x].xPos, enemyBikes[x].yPos, ENEMY_BIKE_W, ENEMY_BIKE_H, false);
                }
                else if(enemyBikes[x].cycles < 4){
                    drawClippedSprite(G_bike_enemy2, enemyBikes[x].xPos, enemyBikes[x].yPos, ENEMY_BIKE_W, ENEMY_BIKE_H, false);
                }
                
                if(++enemyBikes[x].cycles == 4) enemyBikes[x].cycles = 0;
                
                enemyBikes[x].xPos -= 3;
                
                if(enemyBikes[x].xPos <= 3) enemyBikes[x].state = ENEMY_STATE_INACTIVE;
                
                //Check collisions
                
                //Against player (without cannon)
                
                if(bike->state < BIKE_STATE_EXPLOSION_A && enemyBikes[x].xPos >= bike->xPos && enemyBikes[x].xPos <= bike->xPos + BIKE_W - 2){
                    
                    enemyBikes[x].state = ENEMY_STATE_EXPLOSION_A;
                    enemyBikes[x].cycles = 0;
                    
                    bike->state = BIKE_STATE_EXPLOSION_A;
                    bike->cycles = 0;
                    
                    
                }
                
                //Against bullets
                
                for(y=0;y<BIKE_MAX_BULLETS;y++){
                    
                    if(bullets[y].active){
                        
                        if(bullets[y].yPos + BIKE_BULLET_H >= enemyBikes[x].yPos && bullets[y].yPos <= enemyBikes[x].yPos + ENEMY_BIKE_H &&
                           
                           bullets[y].xPos + BIKE_BULLET_W >= enemyBikes[x].xPos && bullets[y].xPos <= enemyBikes[x].xPos + ENEMY_BIKE_W){
                            
                            bullets[y].active = false;
                            
                            enemyBikes[x].state = ENEMY_STATE_EXPLOSION_A;
                            enemyBikes[x].cycles = 0;
                            
                            score += 100;
                            
                        }
                        
                    }
                }
                
                break;
                
            case ENEMY_STATE_EXPLOSION_A:
                
                //Explosion sound
                cpct_akp_SFXPlay (2, 15, 36, 0, 0, AY_CHANNEL_A);
                
                drawClippedSprite(G_explosiona, enemyBikes[x].xPos, enemyBikes[x].yPos, EXPLOSION_W, EXPLOSION_H, true);
                
                if(enemyBikes[x].cycles++ == 2){
                    
                    enemyBikes[x].state = ENEMY_STATE_EXPLOSION_B;
                    enemyBikes[x].cycles = 0;
                }
                
                break;
                
            case ENEMY_STATE_EXPLOSION_B:
                
                drawClippedSprite(G_explosionb, enemyBikes[x].xPos, enemyBikes[x].yPos, EXPLOSION_W, EXPLOSION_H, true);
                
                if(enemyBikes[x].cycles++ == 2){
                    
                    enemyBikes[x].state = ENEMY_STATE_INACTIVE;
                    
                }
                
                break;
                
            default:
                
                break;
        }
        
    }
    
}

void drawEnemyShips(Enemy *enemies, Ship *ship, Bullet *bullets){
    
    u8 x, y, destinationxPos, destinationyPos;
    
    
    
    for(x=0;x<MAX_ENEMIES;x++){
        
        switch (enemies[x].state) {
                
            case ENEMY_STATE_ACTIVE:
                
                //Draw it
                switch (enemies[x].type) {
                        
                    case ENEMY_TYPE_1:
                        
                        drawClippedSprite(G_enemy_ship1, enemies[x].xPos, enemies[x].yPos, enemies[x].width, enemies[x].height, true);
                        break;
                        
                    case ENEMY_TYPE_2:
                        
                        drawClippedSprite(G_enemy_ship2, enemies[x].xPos, enemies[x].yPos, enemies[x].width, enemies[x].height, false);
                        
                        //FIRE
                        if(++enemies[x].cycles == 4){
                            
                            //Fire Sound
                            cpct_akp_SFXPlay (1, 15, 36, 0, 0, AY_CHANNEL_A);
                            addEnemy(ENEMY_TYPE_BULLET, enemies[x].xPos, enemies[x].yPos + ENEMY_TYPE_2_H / 2, 0, BIKE_BULLET_W, BIKE_BULLET_H, 5, 0, false, enemies);
                            
                        }
                        
                        break;
                        
                    case ENEMY_TYPE_3:
                        
                        drawClippedSprite(G_enemy_ship3, enemies[x].xPos, enemies[x].yPos, enemies[x].width, enemies[x].height, false);
                        
                        //FIRE
                        if(++enemies[x].cycles == 4){
                            
                            //Fire Sound
                            cpct_akp_SFXPlay (1, 15, 36, 0, 0, AY_CHANNEL_A);
                            addEnemy(ENEMY_TYPE_BULLET, enemies[x].xPos + ENEMY_TYPE_3_W, enemies[x].yPos + ENEMY_TYPE_2_H / 2, 7, BIKE_BULLET_W, BIKE_BULLET_H, 5, 0, false, enemies);
                            
                        }
                        
                        break;
                        
                    case ENEMY_TYPE_4:
                        
                        drawClippedSprite(G_enemy_ship4, enemies[x].xPos, enemies[x].yPos, enemies[x].width, enemies[x].height, false);
                        break;
                        
                    case ENEMY_TYPE_METEORO:
                        
                        drawClippedSprite(G_meteoro, enemies[x].xPos, enemies[x].yPos, enemies[x].width, enemies[x].height, false);
                        break;
                        
                    case ENEMY_TYPE_BULLET:
                        
                        drawClippedSprite(G_bullet, enemies[x].xPos, enemies[x].yPos, enemies[x].width, enemies[x].height, false);
                        break;
                        
                    case ENEMY_TYPE_ESCAPE:
                        
                        drawClippedSprite(G_escape, enemies[x].xPos, enemies[x].yPos, enemies[x].width, enemies[x].height, false);
                        break;
                        
                    case ENEMY_TYPE_BIGFLAME:
                        
                        if(enemies[x].cycles < 2){
                            drawClippedSprite(G_bigFlame, enemies[x].xPos, enemies[x].yPos, enemies[x].width, enemies[x].height, false);
                        }
                        else{
                            drawClippedSprite(G_bigFlame2, enemies[x].xPos, enemies[x].yPos, enemies[x].width, enemies[x].height, false);
                        }
                        if(++enemies[x].cycles == 4) enemies[x].cycles = 0;
                        
                        break;
                        
                    default:
                        break;
                }
                
                //Move it
                if(enemies[x].movements == MAX_MOVEMENTS){
                    
                    if(!enemies[x].fixed) enemies[x].state = ENEMY_STATE_INACTIVE;
                }
                else{
                    
                    //0 means (constant) enemy coordinate
                    
                    destinationxPos = patterns[enemies[x].pattern][enemies[x].movements].xPos != 0 ? patterns[enemies[x].pattern][enemies[x].movements].xPos : enemies[x].xPos;
                    destinationyPos = patterns[enemies[x].pattern][enemies[x].movements].yPos != 0 ? patterns[enemies[x].pattern][enemies[x].movements].yPos : enemies[x].yPos;
                    
                    if(destinationxPos > enemies[x].xPos){
                        
                        enemies[x].xPos += enemies[x].xSpeed;
                        
                        if(enemies[x].xPos > destinationxPos) enemies[x].xPos = destinationxPos;
                        
                    }
                    if(destinationxPos < enemies[x].xPos){
                        
                        enemies[x].xPos -= enemies[x].xSpeed;
                        
                        if(enemies[x].xPos < destinationxPos) enemies[x].xPos = destinationxPos;
                        
                    }
                    if(patterns[enemies[x].pattern][enemies[x].movements].yPos > enemies[x].yPos){
                        
                        enemies[x].yPos += enemies[x].ySpeed;
                        
                        if(enemies[x].yPos > destinationyPos) enemies[x].yPos = destinationyPos;
                        
                    }
                    if(patterns[enemies[x].pattern][enemies[x].movements].yPos < enemies[x].yPos){
                        
                        enemies[x].yPos -= enemies[x].ySpeed;
                        
                        if(enemies[x].yPos < destinationyPos) enemies[x].yPos = destinationyPos;;
                        
                    }
                    
                    //Check if we are at destination to go to next one
                    
                    if(enemies[x].xPos == destinationxPos && enemies[x].yPos == destinationyPos){
                        
                        enemies[x].movements++;
                        
                    }
                }
                
                //Check collision againts SHIP
                
                if(ship->state < SHIP_STATE_INMUNE && (
                                                       
                                                       (enemies[x].xPos >= ship->xPos && enemies[x].xPos <= ship->xPos + SHIP_W   &&
                                                        enemies[x].yPos >= ship->yPos && enemies[x].yPos <= ship->yPos + SHIP_H ) ||
                                                       
                                                       (enemies[x].xPos + enemies[x].width >= ship->xPos && enemies[x].xPos + enemies[x].width <= ship->xPos + SHIP_W   &&
                                                        enemies[x].yPos >= ship->yPos && enemies[x].yPos <= ship->yPos + SHIP_H ) ||
                                                       
                                                       (enemies[x].xPos >= ship->xPos && enemies[x].xPos <= ship->xPos + SHIP_W   &&
                                                        enemies[x].yPos + enemies[x].height >= ship->yPos && enemies[x].yPos + enemies[x].height <= ship->yPos + SHIP_H ) ||
                                                       
                                                       (enemies[x].xPos + enemies[x].width >= ship->xPos && enemies[x].xPos + enemies[x].width <= ship->xPos + SHIP_W   &&
                                                        enemies[x].yPos + enemies[x].height >= ship->yPos && enemies[x].yPos + enemies[x].height <= ship->yPos + SHIP_H)  ||
                                                       
                                                       (ship->xPos + SHIP_W >= enemies[x].xPos && ship->xPos + SHIP_W <= enemies[x].xPos + enemies[x].width &&
                                                        ship->yPos >= enemies[x].yPos && ship->yPos + SHIP_H <= enemies[x].yPos + enemies[x].height))
                   
                   ){
                    
                    if(enemies[x].fixed){
                        
                        //Explosion sound
                        cpct_akp_SFXPlay (4, 15, 47, 0, 0, AY_CHANNEL_A);
                        
                    }
                    else{
                        
                        enemies[x].state = ENEMY_STATE_EXPLOSION_A;
                        enemies[x].cycles = 0;
                        
                    }
                    
                    ship->state = SHIP_STATE_EXPLOSION_A;
                    ship->cycles = 0;
                    
                }
                
                //Check laser impact
                //Fixed enemeies can not be killed, nor bullets
                
                if(!enemies[x].fixed && enemies[x].type != ENEMY_TYPE_BULLET){
                    
                    for(y=0;y<SHIP_MAX_BULLETS;y++){
                        
                        if(bullets[y].active){
                            
                            if((bullets[y].yPos >= enemies[x].yPos && bullets[y].yPos <= enemies[x].yPos + enemies[x].height ||
                                bullets[y].yPos + LASER_H >= enemies[x].yPos && bullets[y].yPos + LASER_H <= enemies[x].yPos + enemies[x].height) &&
                               enemies[x].xPos >= bullets[y].xPos && enemies[x].xPos <= bullets[y].xPos + LASER_W){
                                
                                bullets[y].active = false;
                                
                                enemies[x].state = ENEMY_STATE_EXPLOSION_A;
                                enemies[x].cycles = 0;
                                
                                score += 100;
                                
                            }
                            
                        }
                    }
                }
                
                
                break;
                
                
            case ENEMY_STATE_EXPLOSION_A:
                
                //Explosion sound
                cpct_akp_SFXPlay (4, 15, 47, 0, 0, AY_CHANNEL_A);
                
                if(enemies[x].yPos + EXPLOSION_H > MAX_Y) enemies[x].yPos = MAX_Y - EXPLOSION_H;
                
                drawClippedSprite(G_explosiona, enemies[x].xPos, enemies[x].yPos, EXPLOSION_W, EXPLOSION_H, true);
                
                if(enemies[x].cycles++ == 2){
                    
                    enemies[x].state = ENEMY_STATE_EXPLOSION_B;
                    enemies[x].cycles = 0;
                }
                
                break;
                
            case ENEMY_STATE_EXPLOSION_B:
                
                drawClippedSprite(G_explosionb, enemies[x].xPos, enemies[x].yPos, EXPLOSION_W, EXPLOSION_H, true);
                
                if(enemies[x].cycles++ == 2){
                    
                    enemies[x].state = ENEMY_STATE_INACTIVE;
                    
                }
                
                break;
                
            default:
                break;
        }
        
    }
}


void drawMenuText(){
    
    cpct_memset_f64(g_scrbuffers[1], 0x00, 0x4000);
    
    drawText("SPACE MOVES", 28, 0);
    
    drawText("TECLADO", 34, 35);
    drawText("JOYSTICK", 34, 55);
    drawText("MUSICA", 34, 75);
    drawText("JUGAR", 34, 95);
    
    drawNumber(1, 1, 30, 35);
    drawNumber(2, 1, 30, 55);
    drawNumber(3, 1, 30, 75);
    drawNumber(4, 1, 30, 95);
    
    
    drawText("PROGRAMA TONI RAMIREZ", 18, 150);
    drawText(" MUSICA Y FX MCKLAIN", 18, 170);
    drawText(" @AMSTRADGAMER  2015", 18, 190);
    
}

void drawMenu(){
    
    drawMenuText();
    swapBuffers(g_scrbuffers);
    drawMenuText();
    
}

//Function to draw sprites with horizontal clipping
//Los sprites que desaparezcan por la izquiera deben tener como maximo MIN_X bytes de ancho
//O bien como mucho desplazarse hasta X = 0

void drawClippedSprite(u8* sprite, u8 xPos, u8 yPos, u8 width, u8 height, u8 masked){
    
    u8 h;
    u8* pvideo;
    
    //In this case we don't have to clip
    if(xPos >= MIN_X && xPos + width <= MAX_X){
        
        pvideo = cpct_getScreenPtr(g_scrbuffers[1], xPos, yPos);
        if(masked)  cpct_drawSpriteMasked(sprite, pvideo, width, height);
        else        cpct_drawSprite(sprite, pvideo, width, height);
        
    }
    else if(xPos <= MAX_X && xPos + width > MAX_X){ //Right clip
        
        for(h=0;h<height;h++){
            
            //Jump * 2 bytes if we have mask information
            pvideo = cpct_getScreenPtr(g_scrbuffers[1], xPos, yPos + h);
            
            //pvideo = SCR_BUFF + (((yPos + h) / 8) * 80) + (((yPos + h) % 8) * 2048) + xPos/2;
            
            if(masked) cpct_drawSpriteMasked(sprite + (h * 2 * width), pvideo, MAX_X - xPos + 1, 1);
            else cpct_drawSprite(sprite + (h * width), pvideo, MAX_X - xPos + 1, 1);
            
        }
        
    }
    else if(xPos < MIN_X && xPos + width >= MIN_X){ //Left clip
        
        for(h=0;h<height;h++){
            
            //Jump * 2 bytes if we have mask information
            pvideo = cpct_getScreenPtr(g_scrbuffers[1], MIN_X, yPos + h);
            
            //pvideo = SCR_BUFF + (((yPos + h) / 8) * 80) + (((yPos + h) % 8) * 2048) + xPos/2;
            
            if(masked) cpct_drawSpriteMasked(sprite + 2 * (MIN_X - xPos) + (h * 2 * width), pvideo, width - (MIN_X - xPos), 1);
            else cpct_drawSprite(sprite + (MIN_X - xPos) + (h * width), pvideo, width - (MIN_X - xPos), 1);
            
        }
        
        
    }
    
}

void drawSelector(u8 color, u8 xPos, u8 yPos){
    
    u8* pvideo = cpct_getScreenPtr(g_scrbuffers[1], xPos, yPos + 3);
    cpct_drawSolidBox(pvideo, cpct_px2byteM0(color, 0), 1, 2);
    
}


void clearGameScreenBike(){
    
    u8* pvideo = cpct_getScreenPtr(g_scrbuffers[1], MIN_X, MIN_Y + 18);
    
    cpct_drawSolidBox(pvideo, 0, MAX_X - MIN_X + 1, BIKE_FLOOR_Y + BIKE_H - (MIN_Y + 18));
    
}

void clearGameScreen(){
    
    u8* pvideo = cpct_getScreenPtr(g_scrbuffers[1], MIN_X, MIN_Y);
    
    cpct_drawSolidBox(pvideo, 0, MAX_X - MIN_X + 1, MAX_Y - MIN_Y);
    
}

void drawFrame(u8 buffer) {
    
    u8 *pvideo;
    u8 x;
    
    cpct_memset_f64(g_scrbuffers[buffer], 0x00, 0x4000);
    
    pvideo = cpct_getScreenPtr(g_scrbuffers[buffer], 8, 0);
    
    //UPLEFTCORNER
    cpct_drawTileAligned2x4_f(G_frame_1,  pvideo);
    
    //UPPER BAR
    for(x=1;x<(FRAME_WIDTH * 2) - 1;x++){
        
        cpct_drawTileAligned2x4_f(G_frame_5,  pvideo + x);
        
    }
    
    //UPRIGHTCORNER
    cpct_drawTileAligned2x4_f(G_frame_2,  pvideo + (FRAME_WIDTH * 2) - 2);
    
    
    //LEFT & RIGHT BARS
    for(x=4;x<(FRAME_HEIGHT * 4) - 4;x += 4){
        
        pvideo = cpct_getScreenPtr(g_scrbuffers[buffer], 8, x);
        cpct_drawTileAligned2x4_f(G_frame_6,  pvideo);
        cpct_drawTileAligned2x4_f(G_frame_7,  pvideo + (FRAME_WIDTH * 2) - 2);
        
    }
    
    pvideo = cpct_getScreenPtr(g_scrbuffers[buffer], 8, FRAME_HEIGHT * 4 - 4);
    
    //DOWNLEFTCORNER
    cpct_drawTileAligned2x4_f(G_frame_3,  pvideo);
    
    
    //LOWER BAR
    for(x=1;x<(FRAME_WIDTH * 2) - 1;x++){
        
        cpct_drawTileAligned2x4_f(G_frame_5,  pvideo + x);
        
    }
    
    //DOWNRIGHTCORNER
    cpct_drawTileAligned2x4_f(G_frame_4,  pvideo + (FRAME_WIDTH * 2) - 2);
    
    //SCOREBOARD SPRITES
    pvideo = cpct_getScreenPtr(g_scrbuffers[buffer], MIN_X + 17, MAX_Y + 10);
    cpct_drawSprite(G_face1, pvideo, 20, 66);
    
    pvideo = cpct_getScreenPtr(g_scrbuffers[buffer], MIN_X + 17 + 20, MAX_Y + 10 + 66 - 19);
    cpct_drawSprite(G_face2, pvideo, 1, 19);
    
    pvideo = cpct_getScreenPtr(g_scrbuffers[buffer], MIN_X + 17 + 21, MAX_Y + 10 + 66 - 19);
    cpct_drawSprite(G_face2, pvideo, 1, 19);
    
    pvideo = cpct_getScreenPtr(g_scrbuffers[buffer], MIN_X + 17 + 22, MAX_Y + 10 + 66 - 19);
    cpct_drawSprite(G_face2, pvideo, 1, 19);
    
    pvideo = cpct_getScreenPtr(g_scrbuffers[buffer], MIN_X + 17 + 23, MAX_Y + 10 + 66 - 19);
    cpct_drawSprite(G_face2, pvideo, 1, 19);
    
    pvideo = cpct_getScreenPtr(g_scrbuffers[buffer], MIN_X + 17 + 24, MAX_Y + 10 + 66 - 19);
    cpct_drawSprite(G_face3, pvideo, 13, 19);
    
    pvideo = cpct_getScreenPtr(g_scrbuffers[buffer], MAX_X - 15, MAX_Y + 16);
    cpct_drawSprite(G_face2, pvideo, 1, 19);
    
    pvideo = cpct_getScreenPtr(g_scrbuffers[buffer], MAX_X - 16, MAX_Y + 16);
    cpct_drawSprite(G_face2, pvideo, 1, 19);
    
    pvideo = cpct_getScreenPtr(g_scrbuffers[buffer], MAX_X - 17, MAX_Y + 16);
    cpct_drawSprite(G_face2, pvideo, 1, 19);
    
    pvideo = cpct_getScreenPtr(g_scrbuffers[buffer], MAX_X - 1, MAX_Y + 16);
    cpct_drawSprite(G_face4, pvideo, 1, 19);
    
    pvideo = cpct_getScreenPtr(g_scrbuffers[buffer], MAX_X, MAX_Y + 16);
    cpct_drawSprite(G_face4, pvideo, 1, 19);
    
    pvideo = cpct_getScreenPtr(g_scrbuffers[buffer], MAX_X - 14, MAX_Y + 16);
    cpct_drawSprite(G_face3, pvideo, 13, 19);
    
    pvideo = cpct_getScreenPtr(g_scrbuffers[buffer], MIN_X - 1, MAX_Y + 26);
    cpct_drawSprite(G_moon, pvideo, MOON_W, MOON_H);
    
}

void drawStar(u8 color1, u8 color2, u8 xPos, u8 yPos){
    
    u8* pvideo = cpct_getScreenPtr(g_scrbuffers[1], xPos, yPos);
    cpct_drawSolidBox(pvideo, cpct_px2byteM0(color1, color2), 1, 1);
    
}


void drawStars(Coords *stars) {
    
    u8 x;
    u8* pvideo;
    
    static u8 starsCycles = 1;
    
    for(x=0;x<MAX_STARS + MAX_COLOR_STARS;x++){
        
        if(x < MAX_STARS){
            
            if(starsCycles == 2){
                
                drawStar(1, 0, stars[x].xPos, stars[x].yPos);
                stars[x].xPos--;
                
                if(stars[x].xPos < MIN_X){
                    
                    stars[x].xPos = MAX_X;
                }
                
            }
            else{
                
                drawStar(0, 1, stars[x].xPos, stars[x].yPos);
                
            }
        }
        else{
            
            pvideo = cpct_getScreenPtr(g_scrbuffers[1],  stars[x].xPos, stars[x].yPos);
            
            cpct_drawSprite(G_bluestar, pvideo, COLOR_STAR_W, COLOR_STAR_H);
            
            stars[x].xPos--;
            
            if(stars[x].xPos < MIN_X){
                
                stars[x].xPos = MAX_X - COLOR_STAR_W;
                stars[x].yPos = MIN_Y + cpct_getRandomUniform_u8_f(stars[x].yPos) % (MAX_Y - COLOR_STAR_H - MIN_Y);
                
            }
            
        }
        
    }
    
    
    if(starsCycles++ == 2) starsCycles = 1;
    
}

void drawBullet(u8 xPos, u8 yPos){
    
    u8* pvideo = cpct_getScreenPtr(g_scrbuffers[1], xPos, yPos);
    cpct_drawSprite(G_bullet, pvideo, BIKE_BULLET_W, BIKE_BULLET_H);
    
}

void drawLaser(u8 xPos, u8 yPos){
    
    drawClippedSprite(G_laser, xPos, yPos, LASER_W, LASER_H, true);
    
}

void drawBullets(Bullet *bullets) {
    
    u8 x;
    
    for(x=0;x<BIKE_MAX_BULLETS;x++){
        
        if(bullets[x].active){
            
            drawBullet(bullets[x].xPos, bullets[x].yPos);
            
            bullets[x].xPos += BIKE_BULLET_SPEED;
            
            if(bullets[x].xPos + BIKE_BULLET_W > MAX_X) bullets[x].active = false;
            
        }
    }
    
    
}

void drawLasers(Bullet *bullets) {
    
    u8 x;
    
    for(x=0;x<SHIP_MAX_BULLETS;x++){
        
        if(bullets[x].active){
            
            drawLaser(bullets[x].xPos, bullets[x].yPos);
            
            bullets[x].xPos += SHIP_BULLET_SPEED;
            
            if(bullets[x].xPos > MAX_X) bullets[x].active = false;
            
        }
    }
    
}

void drawClouds(Coords *clouds) {
    
    u8 x;
    
    u8* pvideo = cpct_getScreenPtr(g_scrbuffers[1], MAX_X - 6, MIN_Y + 8);
    cpct_drawSprite(G_redstar, pvideo, COLOR_STAR_W, COLOR_STAR_H);
    
    pvideo = cpct_getScreenPtr(g_scrbuffers[1], MIN_X + 7, MIN_Y + 10);
    cpct_drawSprite(G_mountain1, pvideo, MOUNTAIN1_W, MOUNTAIN1_H);
    
    pvideo = cpct_getScreenPtr(g_scrbuffers[1], MAX_X - MOUNTAIN2_W - 4, MIN_Y + 24);
    cpct_drawSprite(G_mountain2, pvideo, MOUNTAIN2_W, MOUNTAIN2_H);
    
    
    for(x=0;x<MAX_CLOUDS;x++){
        
        drawClippedSprite(G_cloud, clouds[x].xPos, clouds[x].yPos, CLOUD_W, CLOUD_H, true);
        
        if(--clouds[x].xPos <= 0){
            
            clouds[x].xPos = MAX_X;
        }
        
    }
    
}
