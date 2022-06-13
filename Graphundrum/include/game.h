/*
    Graphundrum
    Copyright (C) 2015-2016 Demonic Benefactor <demonic@tutanota.de>

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with this program; if not, write to the Free Software Foundation, Inc.,
    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*/
#ifndef __game__
#define __game__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input.h"

#include <SDL2/SDL.h>
#ifdef rpi
#include <SDL2/SDL_opengles2.h>
#else
#include <GL/glew.h>
#include <SDL2/SDL_opengl.h>
#endif

int Graph_gameRunning;
const GLubyte* glversion;

int Graph_init();
void Graph_update(inputEvents *Events);
void Graph_cleanup();
int Graph_mouseEvents(int mouseButton);

SDL_Window *window;
SDL_Renderer *renderer;
SDL_GLContext mainContext;

#endif

