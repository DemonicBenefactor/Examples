#version 100
precision mediump float;
varying lowp vec4 vertColor;
varying lowp vec2 TexCoord;

uniform sampler2D testTexture;

void main()
{
    //gl_FragColor = vec4(0.2, 0.6, 0.7, 1.0);
    gl_FragColor =  texture2D(testTexture, TexCoord) * vertColor;
} 
