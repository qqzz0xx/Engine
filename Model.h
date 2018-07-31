#pragma once
#include "IDrawNode.h"
#include "Mesh.h"
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

namespace ZZ
{
	class Model : public IDrawNode
	{
	public:
		Model();
		~Model();

		/*  Functions   */
		// constructor, expects a filepath to a 3D model.
	
		void loadModel(string const &path, bool gamma = false);

		// Í¨¹ý IDrawNode ¼Ì³Ð
		virtual void BuildBuffer() override;
		virtual void Draw(const Shader & shader) override;
	private:
		void processNode(aiNode *node, const aiScene *scene);
		void processMesh(aiMesh *mesh, const aiScene *scene, Mesh* outMesh);
		vector<Texture> loadMaterialTextures(aiMaterial *mat, aiTextureType type, string typeName);
		GLuint BuildGLTexture(const std::string& fileName);

	private:
		/*  Model Data */
		vector<Texture> textures_loaded;	// stores all the textures loaded so far, optimization to make sure textures aren't loaded more than once.
		vector<Mesh> meshes;
		string directory;
		bool gammaCorrection;

	};

}