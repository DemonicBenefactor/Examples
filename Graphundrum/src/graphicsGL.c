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

#include <stdio.h>
#include <stdlib.h>
#include "game.h"
#include "graphicsGL.h"

///////////////////////////////////////////////////////////////
// LoadShaders
///////////////////////////////////////////////////////////////
static const GLchar* ReadShader(const char* filename)
{
    int len;
    GLchar *source;
    FILE* inFile = fopen(filename, "rb");

    if(!inFile)
    {
        printf("unable to open file %s\n",filename);
        return NULL;
    }
    fseek(inFile, 0, SEEK_END);
    len = ftell(inFile);
    fseek(inFile, 0, SEEK_SET);
    source = malloc(sizeof(GLchar) * (len+1));
    fread(source, 1, len, inFile);
    fclose(inFile);
    source[len] = 0;    

    return (const GLchar*)source;
}

GLuint LoadShaders(Gshaders* shaders)
{
    if (shaders == NULL){return 0;}
    GLuint program;
    GLint linked;
    Gshaders *entry;

    program = glCreateProgram();
    entry = shaders;
    while (entry->type != GL_NONE)
    {
        GLuint shader;
        GLint compiled;
        const GLchar *source;
        
        shader = glCreateShader( entry->type );
        entry->shader = shader;
        source = ReadShader(entry->filename);
        if (source == NULL)
        {
            for (entry = shaders; entry->type != GL_NONE; ++entry)
            {
                glDeleteShader(entry->shader);
                entry->shader = 0;
            }
            return 0;
        }
        glShaderSource(shader, 1, &source, NULL);
        free((char*)source);
        glCompileShader(shader);
        glGetShaderiv(shader, GL_COMPILE_STATUS, &compiled);
        if (!compiled)
        {
            GLchar *log;
            GLsizei len;
            glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &len);
            log = malloc(sizeof(GLchar) * (len + 1));
            glGetShaderInfoLog(shader, len, &len, log);
            printf("Shader compilation failed: %s\n", log);
            free(log);
            return 0;
        }

        glAttachShader(program, shader);
        ++entry;
    }

    glLinkProgram(program);
    glGetProgramiv(program, GL_LINK_STATUS, &linked);
    if (!linked)
    {
        GLsizei len;
        GLchar *log;
        glGetProgramiv(program, GL_INFO_LOG_LENGTH, &len);
        log = malloc(sizeof(GLchar) * (len + 1));
        glGetProgramInfoLog(program, len, &len, log);
        printf("Shader linking failed: %s\n", log);
        free(log);
        for (entry = shaders; entry->type != GL_NONE; ++entry)
        {
            glDeleteShader(entry->shader);
            entry->shader = 0;
        }
        return 0;
    }    
    return program;
}

///////////////////////////////////////////////////////////////
// LoadTextures
///////////////////////////////////////////////////////////////

GLuint LoadTextures()
{
  SDL_Surface *Surface = SDL_LoadBMP("data/textures/triangle.bmp");
    glGenTextures(1, &idTexture);
    glActiveTexture(GL_TEXTURE0);    
    glBindTexture(GL_TEXTURE_2D, idTexture);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, Surface->w, Surface->h, 0, GL_RGB, 
                                    GL_UNSIGNED_BYTE, Surface->pixels);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  	glUniform1i(uniTexture, 0);
  	SDL_FreeSurface(Surface);
  
  
  GLuint texture = 0;
  return texture;
}

///////////////////////////////////////////////////////////////
// Let's play a little bit to see if our loaders work
///////////////////////////////////////////////////////////////


void triangleInit()
{
    // I like the red book way,  so.....  ^^
    Gshaders shaders[] = 
    {
        { GL_VERTEX_SHADER, "data/shaders/vertex.glsl" },
        { GL_FRAGMENT_SHADER, "data/shaders/fragment.glsl" },
        { GL_NONE, NULL }
    };
    
    program = LoadShaders(shaders);
    glUseProgram(program);

    //Get handles on our shader attributes and uniforms
    attPosition = glGetAttribLocation(program, "a_position");
    attColor = glGetAttribLocation(program, "a_color");
    attCoords = glGetAttribLocation(program, "a_coords");
    uniTexture = glGetUniformLocation(program, "testTexture");
    uniModel = glGetUniformLocation(program, "model");
    uniView = glGetUniformLocation(program, "view");
    uniProjection = glGetUniformLocation(program, "projection");

    GLfloat vertices[] =
    {
			-0.5, -0.5, 0.0,
			0.5, -0.5, 0.0,
			0.0, 0.5, 0.0
    };

    GLfloat vertColor[] =
    {
      0.7, 0.5, 0.5, 1.0,
      0.5, 0.7, 0.5, 1.0,
      0.5, 0.5, 0.7, 1.0
    };
    
    GLfloat vertCoord[] = 
    {
      0.0, 0.0,
      1.0, 0.0,
      0.5, 1.0
    };

    glGenBuffers(3, Buffers);
    //vertex position
    glBindBuffer(GL_ARRAY_BUFFER, Buffers[0]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glEnableVertexAttribArray(attPosition);
    glVertexAttribPointer(attPosition, 3, GL_FLOAT, GL_FALSE, 0, (GLvoid*) 0);

    //vertex color
    glBindBuffer(GL_ARRAY_BUFFER, Buffers[1]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertColor), vertColor, GL_STATIC_DRAW);
    glEnableVertexAttribArray(attColor);
    glVertexAttribPointer(attColor, 4, GL_FLOAT, GL_FALSE, 0, (GLvoid*) 0);
    
    //texture coordinates
    glBindBuffer(GL_ARRAY_BUFFER, Buffers[2]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertCoord), vertCoord, GL_STATIC_DRAW);
    glEnableVertexAttribArray(attCoords);
    glVertexAttribPointer(attCoords, 2, GL_FLOAT, GL_FALSE, 0, (GLvoid*) 0);

    //texture
    //idTexture = LoadTextures();
    SDL_Surface *Surface = SDL_LoadBMP("data/textures/triangle.bmp");
    glGenTextures(1, &idTexture);
    glActiveTexture(GL_TEXTURE0);    
    glBindTexture(GL_TEXTURE_2D, idTexture);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, Surface->w, Surface->h, 0, GL_RGB, 
                                    GL_UNSIGNED_BYTE, Surface->pixels);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  	glUniform1i(uniTexture, 0);
  	SDL_FreeSurface(Surface);

  	//transform
  	mat4x4_identity(mModel);

  	vec3 upAxis = 	{0,1,0};
		vec3 center = 	{0,0,0};
		vec3 eye = 		{0,0,2};
		mat4x4_look_at(mView, eye, center, upAxis);
  	mat4x4_perspective(mProjection, .7853, 16.f/9.f, .5, 20); //.7853 = 45degrees
  	//mat4x4_rotate(mModel, mModel, 0,0,1, 0);

  	glUniformMatrix4fv(uniModel, 1, GL_FALSE, mModel[0]);
  	glUniformMatrix4fv(uniView, 1, GL_FALSE, mView[0]);
  	glUniformMatrix4fv(uniProjection, 1, GL_FALSE, mProjection[0]);
    
		glEnable(GL_DEPTH_TEST);
}

void triangleDraw()
{    
  mat4x4_rotate_Z(mModel, mModel, .03);
	mat4x4_rotate_X(mModel, mModel, .03);
  glUniformMatrix4fv(uniModel, 1, GL_FALSE, mModel[0]);
	
	glBindBuffer(GL_ARRAY_BUFFER, Buffers[0]);
  glDrawArrays( GL_TRIANGLE_STRIP, 0, 3 );
}

void triangleCleanup()
{
	glDeleteBuffers(3, Buffers);
	glDeleteTextures(1, &idTexture);
	glDeleteProgram(program);

}
