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


#include "keyboard.h"

//Función proporcionada por ronaldo para redefinición de teclas
cpct_keyID esperaUnaTecla() {
    // Recorreremos el vector de teclas desde el final hacia el principio,
    // para poder hacer que el bucle acabe en 0 (así el compilador podrá optimizarlo)
    u8 i = 10, *keys = cpct_keyboardStatusBuffer + 9;
    u16 keypressed;
    
    // Esperamos hasta que se pulse una tecla
    do { cpct_scanKeyboard(); } while ( ! cpct_isAnyKeyPressed() );
    
    // Detectamos cuál tecla ha sido pulsada
    do {
        // Si en este grupo de 8 teclas hay una pulsada, alguno de los bits estará a 0
        // En caso contrario, todos estarán a 1, y un XOR con 0xFF dará 0 (false) como resultado
        keypressed = *keys ^ 0xFF;
        if (keypressed)
            return (keypressed << 8) + (i - 1);  // Formato cpct_keyID: 8 primeros bits = máscara de tecla, 8 siguientes fila del teclado (0-9)
        keys--;
    } while(--i);
    
}

void waitKeyUp(cpct_keyID key) {
    
    while(cpct_isKeyPressed(key)){
        cpct_scanKeyboard_f();
    }
}

void wait4Key(cpct_keyID key) {
    do
        cpct_scanKeyboard_f();
    while( ! cpct_isKeyPressed(key) );
    do
        cpct_scanKeyboard_f();
    while( cpct_isKeyPressed(key) );
}

cpct_keyID redefineKey(u8 *text){
    
    cpct_keyID key;
    
    u8* pvideo = cpct_getScreenPtr(g_scrbuffers[1], 39 - 10 * FONT_W, 120);
    cpct_drawSolidBox(pvideo, 0, 15 * FONT_W, FONT_H);
    
    drawText(text, 39 - (strlen(text) / 2) * FONT_W, 120);
    
    drawSelector(7, 33, 35);
    drawSelector(0, 33, 55);
    
    swapBuffers(g_scrbuffers);
    key = esperaUnaTecla();
    waitKeyUp(key);
    
    return key;
    
}