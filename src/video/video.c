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


#include "video.h"

u8* const g_scrbuffers[2] = {SCR_VMEM, SCR_BUFF};

void setUpVideo(){
    
    //Disable firmware
    cpct_disableFirmware();
    
    cpct_fw2hw(G_graphics_palette, 16);
    cpct_setPalette  (G_graphics_palette, 16);
    cpct_setBorder(G_graphics_palette[0]);
    cpct_setVideoMode(0);
    
}


void clearVideo(u8 xPos, u8 yPos, u8 width, u8 height){
    
    u8* pvideo = cpct_getScreenPtr(g_scrbuffers[1], xPos, yPos);
    cpct_drawSolidBox(pvideo, 0, width, height);
    
}

void swapBuffers(u8** scrbuffers) {
    
    u8* aux; // Auxiliary pointer for making the change
    
    cpct_setVideoMemoryPage( (u16)(scrbuffers[1]) >> 10 );
    
    aux = scrbuffers[0];
    scrbuffers[0] = scrbuffers[1];
    scrbuffers[1] = aux;
}