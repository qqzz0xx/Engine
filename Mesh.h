#pragma once
#include "Header.h"
#include "Image.h"
#include "Shader.h"

#include "glm.hpp"
#include "glad/glad.h"

using namespace std;

namespace ZZ
{
	struct Vertex
	{
		glm::vec3 Position;
		glm::vec3 Normal;
		glm::vec2 TexCoords;
		glm::vec3 Tangent;
		glm::vec3 Bitangent;
	};

	struct Texture {
		unsigned int id;
		string type;
		string path;
	};

	class Mesh
	{
	public:
		Mesh();
		Mesh(vector<Vertex> vertices, vector<GLuint> indices, vector<Texture> textures);
		vector<Vertex> Vertices;
		vector<GLuint> Indices;
		vector<Texture> textures;
		GLuint VAO, VBO, EBO;
		void Draw(const Shader& shader);
	private:
		void BuildGLBuffer();
	};
}