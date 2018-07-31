#version 440 core
out vec4 fsColor;

in vec2 _TexCoord;
uniform sampler2D texture_diffuse1;


void main()
{
    fsColor = texture(texture_diffuse1, _TexCoord);
}