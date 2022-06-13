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
#ifndef __graphicsgl__
#define __graphicsgl__

#include "linmath.h"
#include <SDL2/SDL.h>
#ifdef rpi
#include <SDL2/SDL_opengles2.h>
#else
#include <SDL2/SDL_opengl.h>
#endif

typedef struct {
    GLenum type;
    const char *filename;
    GLuint shader;
} Gshaders;

typedef struct{
    mat4x4 Scale;
    mat4x4 Rotate;
    mat4x4 Translation;
} Gtransform;

typedef struct{
    Gtransform transform;
    GLuint Buffers[3];
    GLuint *attributes;
    GLuint *program;
    GLfloat *verticies;
    GLfloat *vertcolor;
    GLfloat *uv1;
    GLfloat *uv2;
} Gobject;

typedef struct{
    Gtransform transform;
} Gcamera;

typedef struct{
    Gtransform transform;
} Glight;

typedef struct {
    mat4x4 projection;
    GLuint *programs;
    Gobject *objects;
    GLuint *textures;
    Glight *lights;
    Gcamera *cameras;    
} Gscene;

mat4x4 mModel, mView, mProjection;

GLuint VAOs[1], Buffers[3], program;
GLuint attPosition, attColor, attCoords;
GLuint uniModel, uniView, uniProjection, uniTexture, idTexture;

GLuint LoadShaders(Gshaders* shaders);
GLuint LoadTextures();
void triangleInit();
void triangleDraw();
void triangleCleanup();

#endif
