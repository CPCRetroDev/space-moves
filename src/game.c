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

#include "game.h"

Keys keys;
u8 music;

const Enemy enemies[MAX_ENEMIES];
const Coords stars[MAX_STARS + MAX_COLOR_STARS];
const EnemyBike enemyBikes[MAX_ENEMY_BIKES];
const Coords clouds[MAX_CLOUDS] = {{MAX_X - 20, MIN_Y + 18},{MIN_X + 10, MIN_Y + 18}};


void fire(Bullet *bullets, u8 xPos, u8 yPos, u8 isLaser){
    
    u8 x;
    
    for(x=0;x<BIKE_MAX_BULLETS;x++){
        
        if(!bullets[x].active){
            
            //Fire sound
            if(!isLaser) cpct_akp_SFXPlay(1, 15, 36, 0, 0, AY_CHANNEL_A);
            else cpct_akp_SFXPlay(3, 15, 64, 0, 0, AY_CHANNEL_A);
            
            bullets[x].active = true;
            bullets[x].xPos = xPos;
            bullets[x].yPos = yPos;
            
            break;
        }
    }
    
}

void checkKeyboardGame(Bike *bike, Bullet *bullets) {
    
    u8 static fireCycles = 4;
    
    cpct_scanKeyboard_f();
    
    if(cpct_isKeyPressed(keys.abort)){
        
        gameOver = true;
        
    }
    
    if(cpct_isKeyPressed(keys.pause)){
        
        pause = !pause;
        
        waitKeyUp(keys.pause);
    }
    
    if(!pause){
        
        if(cpct_isKeyPressed(keys.left) && bike->xPos > MIN_X && bike->state < BIKE_STATE_FALL_TO_DEATH){
            
            bike->xPos--;
        
        }
        
        if(cpct_isKeyPressed(keys.right) && bike->xPos < MAX_X - BIKE_W && bike->state < BIKE_STATE_FALL_TO_DEATH){
            
            bike->xPos++;
        
        }
        
        if(cpct_isKeyPressed(keys.up) && bike->state == BIKE_STATE_ON_FLOOR){
            
            bike->state = BIKE_STATE_JUMPING_UP;
            
        }
        
        if(cpct_isKeyPressed(keys.fire) && bike->state < BIKE_STATE_FALL_TO_DEATH && bike->xPos + BIKE_W + BIKE_BULLET_W < MAX_X){
            
            if(fireCycles >= 4){
             
                fire(bullets, bike->xPos + BIKE_W, bike->yPos + 8, false);
                fireCycles = 0;
            }
        
        }
        
        fireCycles++;

    }

}


void checkKeyboardGame2(Ship *ship, Bullet *bullets) {
    
    u8 static fireCycles;
    
    cpct_scanKeyboard_f();
    
    if(cpct_isKeyPressed(keys.abort)){
        
        gameOver = true;
        
    }
    
    if(cpct_isKeyPressed(keys.pause)){
        
        pause = !pause;
        
        waitKeyUp(keys.pause);
    }
    
    if(!pause){
        
    
        if(cpct_isKeyPressed(keys.up) && ship->yPos > MIN_Y && ship->state < SHIP_STATE_EXPLOSION_A){
            
            ship->yPos-=4;
            
            if(ship->yPos < MIN_Y) ship->yPos = MIN_Y;
            
        }
        
        if(cpct_isKeyPressed(keys.down) && ship->yPos < MAX_Y - SHIP_H && ship->state < SHIP_STATE_EXPLOSION_A){
            
            ship->yPos+=4;
            
            if(ship->yPos > MAX_Y - SHIP_H) ship->yPos = MAX_Y - SHIP_H;
            
        }
        
        if(cpct_isKeyPressed(keys.left) && ship->xPos > MIN_X && ship->state < SHIP_STATE_EXPLOSION_A){
            
            ship->xPos--;
            ship->state = (ship->state == SHIP_STATE_INMUNE ? SHIP_STATE_INMUNE : SHIP_STATE_GOING_LEFT);
            
        }
        
        if(cpct_isKeyPressed(keys.right)){
            
            if(ship->state < SHIP_STATE_EXPLOSION_A){
            
                if(ship->xPos < MAX_X - SHIP_W) ship->xPos+=2;
                ship->state = (ship->state == SHIP_STATE_INMUNE ? SHIP_STATE_INMUNE : SHIP_STATE_GOING_RIGHT);
            }
        
        }
        else{
            
            if(ship->state < SHIP_STATE_EXPLOSION_A){
                
                ship->state = (ship->state == SHIP_STATE_INMUNE ? SHIP_STATE_INMUNE : SHIP_STATE_GOING_LEFT);
                if(ship->xPos > MIN_X) ship->xPos--;
                
            }
            
        }
        
        if(cpct_isKeyPressed(keys.fire) && ship->xPos + SHIP_W + LASER_W < MAX_X && ship->state < SHIP_STATE_EXPLOSION_A){
            
            if(fireCycles >= 4){
                
                fire(bullets, ship->xPos + SHIP_W - 2, ship->yPos + 10, true);
                fireCycles = 0;
            }
            
        }
        
        fireCycles++;
    
    }
}


void gameOverScoreBoard(){

    clearGameScreen();
    
    drawText("0000", 59, MAX_Y + 21);
    drawNumber(distance, 4, 59, MAX_Y + 21);
    drawNumber(score, 4, 53, MAX_Y + 62);
    drawNumber(lifes, 2, 41, MAX_Y + 62);
    
}

void gameover(){
    
    gameOverScoreBoard();
    
    swapBuffers(g_scrbuffers);
    
    gameOverScoreBoard();
    
    drawFallingText("GAME OVER ", 32, MIN_Y, MIN_Y + (MAX_Y - MIN_Y) / 2);
    
    wait4Key(keys.fire);
    
    if(music) cpct_akp_musicInit(G_Menu);
    
    drawMenu();
    
}

void initGame2(Coords *stars, Bullet *bullets, Enemy *enemies){
    
    u8 x;
    
    //Extra Life
    lifes++;
    
    distance = SHIP_DISTANCE;
    
    for(x=0;x<MAX_STARS + MAX_COLOR_STARS;x++){
        
        stars[x].xPos = MIN_X + cpct_getRandomUniform_u8_f(2 * x) % (MAX_X - MIN_X);
        
        if(x<MAX_STARS){
            stars[x].yPos = MIN_Y + cpct_getRandomUniform_u8_f(0) % (MAX_Y - MIN_Y);
        }
        else{
             stars[x].yPos = MIN_Y + cpct_getRandomUniform_u8_f(0) % (MAX_Y - MIN_Y - COLOR_STAR_H);
        }
                                                                     
    }
    
    for(x=0;x<SHIP_MAX_BULLETS;x++){
        
        bullets[x].active = false;
    }
    
    for(x=0;x<MAX_ENEMIES;x++){
        
        enemies[x].state = ENEMY_STATE_INACTIVE;
        enemies[x].cycles = 0;
        enemies[x].fixed = false;
    }
    
}

void addEnemyByDistance(Enemy *enemies){
    
    //Events depend on distance
    
    // <- BLUE, MIDDLE
    
    if(distance == SHIP_DISTANCE - 20 || distance == SHIP_DISTANCE - 120 || distance == SHIP_DISTANCE - 500 || distance == SHIP_DISTANCE - 785){
        
        addEnemy(ENEMY_TYPE_4, MAX_X, MIN_Y + (MAX_Y - MIN_Y) / 2 - 4, 0, ENEMY_TYPE_4_W, ENEMY_TYPE_4_H, 3, 0, false, enemies);
        
    }
    
    // <- BLUE, TOP
    
    if(distance == SHIP_DISTANCE - 25 || distance == SHIP_DISTANCE - 125 || distance == SHIP_DISTANCE - 505 || distance == SHIP_DISTANCE - 790){
        
        addEnemy(ENEMY_TYPE_4, MAX_X, MIN_Y + 5, 0, ENEMY_TYPE_4_W, ENEMY_TYPE_4_H, 3, 0, false, enemies);
        
    }
    
    
    // <- BLUE, BOTTOM
    
    if(distance == SHIP_DISTANCE - 25 || distance == SHIP_DISTANCE - 125 || distance == SHIP_DISTANCE - 505 || distance == SHIP_DISTANCE - 790){
        
        addEnemy(ENEMY_TYPE_4, MAX_X, MAX_Y - ENEMY_TYPE_4_H - 5, 0, ENEMY_TYPE_4_W, ENEMY_TYPE_4_H, 3, 0, false, enemies);
        
    }
    
    
    // Z <- UP BOTTOM
    
    if(distance == SHIP_DISTANCE - 50  || distance == SHIP_DISTANCE - 53  || distance == SHIP_DISTANCE - 56  ||
       distance == SHIP_DISTANCE - 150 || distance == SHIP_DISTANCE - 153 || distance == SHIP_DISTANCE - 156 ||
       distance == SHIP_DISTANCE - 600 || distance == SHIP_DISTANCE - 603 || distance == SHIP_DISTANCE - 606 ||
       distance == SHIP_DISTANCE - 865 || distance == SHIP_DISTANCE - 868 || distance == SHIP_DISTANCE - 871
       
       ){
        
        
        addEnemy(ENEMY_TYPE_1, MAX_X + 20, MIN_Y, 2, ENEMY_TYPE_1_W, ENEMY_TYPE_1_H, 5, 6, false, enemies);
        
    }
    
    
    
    
    // <- RED, MIDDLE
    
    if(distance == SHIP_DISTANCE - 230 || distance == SHIP_DISTANCE - 460 || distance == SHIP_DISTANCE - 680 || distance == SHIP_DISTANCE - 815){
        
        addEnemy(ENEMY_TYPE_2, MAX_X, MIN_Y + (MAX_Y - MIN_Y) / 2 - 4, 0, ENEMY_TYPE_2_W, ENEMY_TYPE_2_H, 2, 0, false, enemies);
        
    }
    
    // <- RED, TOP
    
    if(distance == SHIP_DISTANCE - 235 || distance == SHIP_DISTANCE - 465 || distance == SHIP_DISTANCE - 685 || distance == SHIP_DISTANCE - 820){
        
        addEnemy(ENEMY_TYPE_2, MAX_X, MIN_Y + 5, 0, ENEMY_TYPE_2_W, ENEMY_TYPE_2_H, 2, 0, false, enemies);
        
    }
    
    // <- RED, BOTTOM
    
    if(distance == SHIP_DISTANCE - 235 || distance == SHIP_DISTANCE - 465 || distance == SHIP_DISTANCE - 685 || distance == SHIP_DISTANCE - 820){
        
        addEnemy(ENEMY_TYPE_2, MAX_X, MAX_Y - ENEMY_TYPE_2_H - 5, 0, ENEMY_TYPE_2_W, ENEMY_TYPE_2_H, 2, 0, false, enemies);
        
    }
    
    
    
    
    // Z -> BOTTOM UP
    
    if(distance == SHIP_DISTANCE - 280 || distance == SHIP_DISTANCE - 283 || distance == SHIP_DISTANCE - 286 ||
       distance == SHIP_DISTANCE - 400 || distance == SHIP_DISTANCE - 403 || distance == SHIP_DISTANCE - 406 ||
       distance == SHIP_DISTANCE - 720 || distance == SHIP_DISTANCE - 723 || distance == SHIP_DISTANCE - 726 ||
       distance == SHIP_DISTANCE - 865 || distance == SHIP_DISTANCE - 868 || distance == SHIP_DISTANCE - 871
       
       ){
        
        
        addEnemy(ENEMY_TYPE_1, 3, MAX_Y - 20, 1, ENEMY_TYPE_1_W, ENEMY_TYPE_1_H, 5, 6, false, enemies);
        
    }
    
    
    // -> RED
    if(distance == SHIP_DISTANCE - 340){
        
        addEnemy(ENEMY_TYPE_3, MIN_X - ENEMY_TYPE_3_W, MIN_Y + 20, 7, ENEMY_TYPE_3_W, ENEMY_TYPE_3_H, 3, 0, false, enemies);
        addEnemy(ENEMY_TYPE_3, MIN_X - ENEMY_TYPE_3_W, MAX_Y - 30, 7, ENEMY_TYPE_3_W, ENEMY_TYPE_3_H, 3, 0, false, enemies);
        
    }
    
    
    
    
    //METEORITOS
    
    if(distance == SHIP_DISTANCE - 530 || distance == SHIP_DISTANCE - 540 || distance == SHIP_DISTANCE - 550 || distance == SHIP_DISTANCE - 560 || distance == SHIP_DISTANCE - 570){
        
        
        addEnemy(ENEMY_TYPE_METEORO, MAX_X + 10, MIN_Y + 20, 0, ENEMY_TYPE_METEORO_W, ENEMY_TYPE_METEORO_H, 4, 4, false, enemies);
        
    }
    
    if(distance == SHIP_DISTANCE - 535 || distance == SHIP_DISTANCE - 545 || distance == SHIP_DISTANCE - 555 || distance == SHIP_DISTANCE - 565 || distance == SHIP_DISTANCE - 575){
        
        
        addEnemy(ENEMY_TYPE_METEORO, MAX_X + 10, MIN_Y + 40, 0, ENEMY_TYPE_METEORO_W, ENEMY_TYPE_METEORO_H, 4, 4, false, enemies);
        
    }
    
    if(distance == SHIP_DISTANCE - 530 || distance == SHIP_DISTANCE - 540 || distance == SHIP_DISTANCE - 550 || distance == SHIP_DISTANCE - 560 || distance == SHIP_DISTANCE - 570){
        
        
        addEnemy(ENEMY_TYPE_METEORO, MAX_X + 10, MIN_Y + 60, 0, ENEMY_TYPE_METEORO_W, ENEMY_TYPE_METEORO_H, 4, 4, false, enemies);
        
    }
    
    if(distance == SHIP_DISTANCE - 535 || distance == SHIP_DISTANCE - 545 || distance == SHIP_DISTANCE - 555 || distance == SHIP_DISTANCE - 565 || distance == SHIP_DISTANCE - 575){
        
        
        addEnemy(ENEMY_TYPE_METEORO, MAX_X + 10, MIN_Y + 80, 0, ENEMY_TYPE_METEORO_W, ENEMY_TYPE_METEORO_H, 4, 4, false, enemies);
        
    }
    

}

void game2(){
    
    u8 *pvideo;
    
    Ship ship = {MIN_X, MIN_Y + (MAX_Y - MIN_Y) / 2 - 4, SHIP_STATE_GOING_LEFT, 0};
    Bullet bullets[SHIP_MAX_BULLETS];
    
    u8 end = false;
    
    initGame2(stars, bullets, enemies);
    
    while(1){
 
        if(!pause){
            
            if(distance > 0){
                if(distance-- % 2 == 0) score++;
            }

        
            clearGameScreen();
            drawStars(stars);

            drawEnemyShips(enemies, &ship, bullets);
            drawShip(&ship);
            
            //SPACE STATION ENTRANCE
            if(distance == 0){
                
                pvideo = cpct_getScreenPtr(g_scrbuffers[1], MAX_X, MIN_Y + ENEMY_TYPE_ESCAPE_H + 4);
                cpct_drawSolidBox(pvideo, cpct_px2byteM0(5, 5), 1, 42);
                
                if(ship.xPos + SHIP_W >= MAX_X) end = true;
                
            }
            
            if(distance == 25){
                
                
                addEnemy(ENEMY_TYPE_ESCAPE, MAX_X + 10 + ENEMY_TYPE_BIGFLAME_W, MIN_Y, 3, ENEMY_TYPE_ESCAPE_W,  ENEMY_TYPE_ESCAPE_H, 1, 0, true, enemies);
                addEnemy(ENEMY_TYPE_ESCAPE, MAX_X + 10 + ENEMY_TYPE_BIGFLAME_W, MAX_Y - ENEMY_TYPE_ESCAPE_H, 4, ENEMY_TYPE_ESCAPE_W, ENEMY_TYPE_ESCAPE_H, 1, 0, true, enemies);
                
                addEnemy(ENEMY_TYPE_BIGFLAME, MAX_X + 10, MIN_Y + 1, 5, ENEMY_TYPE_BIGFLAME_W, ENEMY_TYPE_BIGFLAME_H, 1, 0, true, enemies);
                addEnemy(ENEMY_TYPE_BIGFLAME, MAX_X + 10, MAX_Y - ENEMY_TYPE_ESCAPE_H + 1, 6, ENEMY_TYPE_BIGFLAME_W, ENEMY_TYPE_BIGFLAME_H, 1, 0, true, enemies);
                
            }
            
             
            drawLasers(bullets);
            
            drawText("0000", 59, MAX_Y + 21);
            drawNumber(distance * 2, 4, 59, MAX_Y + 21);
            drawNumber(score, 4, 53, MAX_Y + 62);
            drawNumber(lifes, 2, 41, MAX_Y + 62);
            
            cpct_waitVSYNC();
            swapBuffers(g_scrbuffers);
            
            checkKeyboardGame2(&ship, bullets);
            
            if(gameOver == true){
                
                distance *= 2;
                
                gameover();
                
                return;
                
            }
            
            addEnemyByDistance(enemies);
            
            if(end){
                
                 gameOverScoreBoard();
                
                 swapBuffers(g_scrbuffers);
    
                 gameOverScoreBoard();
                
                 drawText("HAS ENTRADO EN LA ESTACION", MIN_X + 4, MIN_Y + (MAX_Y - MIN_Y) / 2 - 2 * FONT_H);
                 drawText("CLAVE 102115", MIN_X + 18, MIN_Y + (MAX_Y - MIN_Y) / 2 + FONT_H);
                 
                 swapBuffers(g_scrbuffers);
                 
                 wait4Key(keys.fire);
                 
                 gameover();
                 
                 return;
                 
            }
        }
        else{
            
            checkKeyboardGame2(&ship, bullets);
        }
        
    }
}

void initGame(Bullet *bullets, EnemyBike *enemyBikes){
    
    u8 x;
    
    drawFrame(0);
    drawFrame(1);
    
    tilemapPos = 0;
    shift = 0;
    lifes = 3;
    score = 0;
    gameOver = false;
    pause = false;

    distance = BIKE_DISTANCE;
    
    for(x=0;x<BIKE_MAX_BULLETS;x++){
     
        bullets[x].active = false;
        
    }
    
    for(x=0;x<MAX_ENEMY_BIKES;x++){
        
        enemyBikes[x].state = ENEMY_STATE_INACTIVE;
        enemyBikes[x].cycles = 0;
    }
    
    if(music)cpct_akp_musicInit(G_SpaceMoves);
    else cpct_akp_musicInit(G_FX);
    
}

void drawEndingShip(u8 xPos){
    
    u8 x;
    
    for(x=0;x<5;x++){
        
        drawClippedSprite(G_metal, xPos + (x * METAL_W), BIKE_FLOOR_Y + 14, METAL_W, METAL_H, false);
        
    }
    
    drawClippedSprite(G_bigShip, xPos + METAL_W - 2 , BIKE_FLOOR_Y - 20, BIG_SHIP_W, BIG_SHIP_H, true);
    
}

void game(){
    
    u8 *pvideo;
    u8 end = false;
    
    u8 endingShipxPos = MAX_X + 1;
    
    Bike bike = {MIN_X + 6, BIKE_FLOOR_Y, BIKE_STATE_ON_FLOOR, 0};
    Bullet bullets[BIKE_MAX_BULLETS];
    
    initGame(bullets, enemyBikes);
    
    while(1){
        
        if(!pause){
        
            clearGameScreenBike();
            drawClouds(clouds);
            drawFloor(true);
            drawBike(&bike, enemyBikes);
            drawBullets(bullets);
            drawEnemyBikes(enemyBikes, &bike, bullets);

            if(distance < 18){
                
                drawEndingShip(endingShipxPos-=2);
                
            }
            
            drawText("0000", 59, MAX_Y + 21);
            drawNumber(distance--, 4, 59, MAX_Y + 21);
        
            drawNumber(score, 4, 53, MAX_Y + 62);
            drawNumber(lifes, 2, 41, MAX_Y + 62);
            
            cpct_waitVSYNC();
            swapBuffers(g_scrbuffers);
            
            checkKeyboardGame(&bike, bullets);
            
            if(g_floorTilemap[tilemapPos + 15] == 9 && shift == 0){
                
                addEnemyBike(MAX_X + 1, BIKE_FLOOR_Y + 3, enemyBikes);
            }
            
           
            if(gameOver == true){
                
                gameover();
                
                return;
                
            }
            
            if(distance == 0){
                
                //ENDING ANIMATION
                
                bike.yPos = BIKE_FLOOR_Y;
                
                while(!end){
                
                    clearGameScreen();
                    drawClouds(clouds);
                    drawFloor(false);
                    
                    drawText("0000", 59, MAX_Y + 21);
                    drawNumber(score, 4, 53, MAX_Y + 62);
                    
                    pvideo = cpct_getScreenPtr(g_scrbuffers[1], bike.xPos, bike.yPos);
                    
                    if(bike.cycles < 2){
                        cpct_drawSpriteMasked(G_bike, pvideo, BIKE_W, BIKE_H);
                    }
                    else if(bike.cycles < 4){
                        cpct_drawSpriteMasked(G_bike2, pvideo, BIKE_W, BIKE_H);
                    }
                    
                    if(++bike.cycles == 4) bike.cycles = 0;
                    
                    drawEndingShip(endingShipxPos);
                    
                    cpct_waitVSYNC();
                    swapBuffers(g_scrbuffers);
                    
                    if(bike.xPos < MAX_X -  2 * BIKE_W) bike.xPos++;
                    else end = true;
                
                }
            }
            
            if(end){
                
                clearGameScreen();

                drawText("PREPARATE PARA LA FASE 2", MIN_X + 6, MIN_Y + 50);
                
                swapBuffers(g_scrbuffers);
                wait4Key(keys.fire);
                
                game2();
                
                return;
                
            }
        }
        else{
            
            checkKeyboardGame(&bike, bullets);
        }
        
    }
}


void checkKeyboardMenu() {
    
    u8 *pvideo;
    static u8 selectedOption = 1;
    
    cpct_scanKeyboard_f();

    drawSelector(selectedOption == 2 ? 0 : 7, 33, 35);
    drawSelector(selectedOption == 2 ? 7 : 0, 33, 55);
    
    if(cpct_isKeyPressed(Key_1)){
        
        selectedOption = 1;
        
        waitKeyUp(Key_1);
        
        keys.up    = redefineKey("ARRIBA");
        keys.down  = redefineKey("ABAJO");
        keys.left  = redefineKey("IZQUIERDA");
        keys.right = redefineKey("DERECHA");
        keys.fire  = redefineKey("DISPARO");
        keys.pause = redefineKey("PAUSA");
        keys.abort = redefineKey("TERMINAR");
        
        pvideo = cpct_getScreenPtr(g_scrbuffers[1], 37 - 10 * FONT_W, 120);
        cpct_drawSolidBox(pvideo, 0, 15 * FONT_W, FONT_H);
        
        pvideo = cpct_getScreenPtr(g_scrbuffers[0], 37 - 10 * FONT_W, 120);
        cpct_drawSolidBox(pvideo, 0, 15 * FONT_W, FONT_H);
        
    }
   
    else if(cpct_isKeyPressed(Key_2)){
        
        selectedOption = 2;
        
        keys.up    = Joy0_Up;
        keys.down  = Joy0_Down;
        keys.left  = Joy0_Left;
        keys.right = Joy0_Right;
        keys.fire  = Joy0_Fire1;

    }
    
    else if(cpct_isKeyPressed(Key_3)){
        
        waitKeyUp(Key_3);
        
        if(music){
           cpct_akp_musicInit(G_FX);
        }
        else{
            cpct_akp_musicInit(G_Menu);
        }

        music = !music;
        
    }
    
    else if(cpct_isKeyPressed(Key_4)){
        
        game();
        
    }
    /*
    else if(cpct_isKeyPressed(Key_8)){
        
        lifes = 3;
        score = 0;
        gameOver = false;
        pause = false;
        
        drawFrame(0);
        drawFrame(1);
        
        cpct_akp_musicInit(G_SpaceMoves);
        
        game2();
        
    }*/
}

void myInterruptHandler() {
    
    static u8 i;
    
    if (++i > 5){
     
        cpct_akp_musicPlay();
        i=0;
        
    }
    
}

void init(){
    
    music = true;
    
    keys.up    = Key_Q;
    keys.down  = Key_A;
    keys.left  = Key_O;
    keys.right = Key_P;
    keys.fire  = Key_Space;
    keys.pause = Key_Del;
    keys.abort = Key_Esc;
    
    cpct_akp_musicInit(G_Menu);
    cpct_akp_SFXInit(G_FX);
    
    cpct_setInterruptHandler(myInterruptHandler);
    
}

void spaceMoves(){
    
    drawMenu();
    
    while (1){
        
        checkKeyboardMenu();
        cpct_waitVSYNC();
        swapBuffers(g_scrbuffers);
        
    }
}