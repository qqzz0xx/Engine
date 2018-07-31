#pragma once
#include "Mesh.h"
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

namespace ZZ
{
	class Model
	{
	public:
		Model();
		~Model();
		/*  Model Data */
		vector<Texture> textures_loaded;	// stores all the textures loaded so far, optimization to make sure textures aren't loaded more than once.
		vector<Mesh> meshes;
		string directory;
		bool gammaCorrection;

		/*  Functions   */
		// constructor, expects a filepath to a 3D model.
		Model(string const &path, bool gamma = false) : gammaCorrection(gamma)
		{
			loadModel(path);
		}
	private:
		void loadModel(string const &path);
		void processNode(aiNode *node, const aiScene *scene);
		void processMesh(aiMesh *mesh, const aiScene *scene, Mesh* outMesh);
		vector<Texture> loadMaterialTextures(aiMaterial *mat, aiTextureType type, string typeName);
		GLuint BuildGLTexture(const std::string& fileName);
	};

}