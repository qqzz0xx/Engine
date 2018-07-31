#version 440 core
layout (location=0) in vec3 position;
layout (location=1) in vec3 normal;
layout (location=2) in vec2 texCoord;
layout (location=3) in vec3 tangent;
layout (location=4) in vec3 bitangent;


out vec2 _TexCoord;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
    _TexCoord = texCoord;
    gl_Position = projection * view * model * vec4(position, 1.0f);
}