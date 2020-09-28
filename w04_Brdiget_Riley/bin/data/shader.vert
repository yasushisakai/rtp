#version 150

#define PI 3.1415926535897932384626433832795

uniform mat4 modelViewProjectionMatrix;
uniform vec2 windowSize;
in vec4 position;


void main(){

    vec4 pos = position;

    gl_Position = modelViewProjectionMatrix * pos;
}