#version 440 core

in vec3 outColor;

out vec4 fsColor;

void main()
{
    fsColor = vec4(outColor, 1.0f);
}