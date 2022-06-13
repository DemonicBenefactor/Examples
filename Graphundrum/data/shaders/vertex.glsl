#version 100

attribute vec3 a_position;
attribute vec4 a_color;
attribute vec2 a_coords;

varying vec4 vertColor;
varying vec2 TexCoord;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
    gl_Position = projection * view * model * vec4(a_position, 1.0);

    vertColor = a_color;
    TexCoord = a_coords;
}
