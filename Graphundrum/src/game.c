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
#include "game.h"
#include "graphicsGL.h"


int Graph_init()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		#ifdef cygwin		
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_COMPATIBILITY);
		#else
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_ES);
		#endif
		SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
		printf("SDL init success\n");
		
		window = SDL_CreateWindow("Graphundrum",
				SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,960,540,SDL_WINDOW_OPENGL);

		if(window != 0)
		{
			mainContext = SDL_GL_CreateContext(window);
			
			//Verify some openGL stuff.
			#ifdef cygwin
			glversion = glGetString(GL_VERSION);
			fflush(stdout);
			printf("%s \n", (char*)glversion);
			int glMinor, glMajor;
			SDL_GL_GetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, &glMinor);
			SDL_GL_GetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, &glMajor);
			printf("minor %d, major %d\n", glMinor, glMajor);
			if (glMinor < 2)
			{
				printf("Your openGL is legacy, unrolling to soft renderer.\n");
			}
			else
			{
				printf("Your openGL is good, let's rock and roll.\n");
				GLenum err;
				glewExperimental = GL_TRUE; 
				err = glewInit();
				if (GLEW_OK != err)
				{
				fprintf(stderr, "Error: %s\n", glewGetErrorString(err));
				}
				fprintf(stdout, "Status: Using GLEW %s\n", glewGetString(GLEW_VERSION));
			}
			#endif
			printf("Window creation success\n");
			renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_PRESENTVSYNC);
			if (renderer != 0)
			{
				printf("Renderer init success\n");
				SDL_RenderSetLogicalSize(renderer,960,540);
				SDL_SetRenderDrawColor(renderer,120,120,120,255);
				SDL_RenderClear(renderer);
				SDL_RenderPresent(renderer);

				//INIT SOME GL CODE HERE IF YOU WANT
				SDL_GL_SetSwapInterval(1);
				
				glClearColor(0.2,0.2,0.2,0.0);
				glClear(GL_COLOR_BUFFER_BIT);
				///////////////////////////////////////////////////////////
				triangleInit();  
				//////////////////////////////////////////////////////////
				SDL_GL_SwapWindow(window);
			}
			else
			{
				printf("Renderer init failed\n");
				return 0;
			}
		}
		else
		{
			printf("Window init failed\n");
			return 0;
		}
	}
	else
	{
		printf("SDL init failed\n");
		return 0;
	}
	
	printf("init complete\n");
	Graph_gameRunning = 1;
	return 1;
}
//==================================================================
void Graph_update(inputEvents *Events)
{
	if (Events->esc == 1){Graph_gameRunning = 0;}
	if (Events->mouseLeft == 1){Graph_mouseEvents(SDL_BUTTON_LEFT);}
	else if (Events->mouseMiddle == 1){Graph_mouseEvents(SDL_BUTTON_MIDDLE);}	
	else if (Events->mouseRight == 1){Graph_mouseEvents(SDL_BUTTON_RIGHT);}
	else Graph_mouseEvents(0);	
	triangleDraw();
}
//==================================================================
void Graph_cleanup()
{
	printf("shutting down and cleaning house\n");
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_GL_DeleteContext(mainContext);
	triangleCleanup();
	SDL_Quit();
}
//==================================================================
int Graph_mouseEvents(int mouseButton)
{
	switch (mouseButton)
	{
		case SDL_BUTTON_LEFT:
			
			glClearColor(0.2,0.2,0.3,0.0);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			break;
		case SDL_BUTTON_MIDDLE:
			glClearColor(0.2,0.3,0.2,0.0);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			break;
		case SDL_BUTTON_RIGHT:
			glClearColor(0.3,0.2,0.2,0.0);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			break;
		default:
			glClearColor(0.2,0.2,0.2,0.0);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			break;
	}
	return 0;
}
