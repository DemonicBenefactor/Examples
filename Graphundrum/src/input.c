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
#include <SDL2/SDL.h>
#include "input.h"
#include "game.h"


void Graph_handleInput(inputEvents *Events)
{
	SDL_Event event;
	if (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
			case SDL_QUIT:
				Graph_gameRunning = 0;
				break;
			
			case SDL_MOUSEBUTTONDOWN:
				switch (event.button.button)
				{
					case SDL_BUTTON_LEFT:
						Events->mouseLeft = 1;
						break;
					case SDL_BUTTON_MIDDLE:
						Events->mouseMiddle = 1;
						break;
					case SDL_BUTTON_RIGHT:
						Events->mouseRight = 1;
						break;
				}
				break;
			case SDL_MOUSEBUTTONUP:
				switch (event.button.button)
				{
					case SDL_BUTTON_LEFT:
						Events->mouseLeft = 0;
						break;
					case SDL_BUTTON_MIDDLE:
						Events->mouseMiddle = 0;
						break;
					case SDL_BUTTON_RIGHT:
						Events->mouseRight = 0;
						break;
				}
				break;
			
			case SDL_KEYDOWN:
				//printf("%s\n", SDL_GetKeyName(event.key.keysym.sym));
				switch (event.key.keysym.sym)
				{
					case SDLK_ESCAPE:
						Events->esc = 1;
						break;
				}
				break;
			
			case SDL_KEYUP:
				switch (event.key.keysym.sym)
				{
					case SDLK_ESCAPE:
						break;
				}
				break;
		}
	}
}
