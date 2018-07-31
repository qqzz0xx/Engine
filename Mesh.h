#pragma once
#include "Header.h"
#include "Image.h"
#include "Shader.h"
#include "IDrawNode.h"

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

	class Mesh : public IDrawNode
	{
	public:
		Mesh();
		Mesh(vector<Vertex> vertices, vector<GLuint> indices, vector<Texture> textures);
		vector<Vertex> Vertices;
		vector<GLuint> Indices;
		vector<Texture> textures;
		// Í¨¹ý IDrawNode ¼Ì³Ð
		virtual void BuildBuffer() override;
		void Draw(const Shader& shader);
	private:
		GLuint VAO, VBO, EBO;

	
	};
}