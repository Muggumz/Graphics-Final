#version 430

layout(location = 0) in vec2 inUV;
layout(location = 0) out vec3 outColor;

uniform layout(binding = 0) sampler2D s_Image;

//How many pixels
uniform float u_amount = 1;

void main() {
    
    vec2 newUV = floor(inUV * u_amount) / u_amount;
    // floor is used to return a value equal to the nearest integer 
    // that is less than or equal to x which in this case, u_amount
    outColor = (texture(s_Image, newUV)).rgb;
}