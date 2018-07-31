#include "Model.h"
#include "AssetLoader.h"

using namespace ZZ;

Model::Model()
{
}

Model::~Model()
{
}

void Model::loadModel(string const & path, bool gamma)
{
	this->gammaCorrection = gamma;

	Assimp::Importer importer;
	auto fullPath = AssetLoader::GetFullPath(path);
	auto scene = 
		importer.ReadFile(fullPath,
		aiProcess_Triangulate | aiProcess_FlipUVs | aiProcess_CalcTangentSpace);
	if (!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode) // if is Not Zero
	{
		cout << "ERROR::ASSIMP:: " << importer.GetErrorString() << endl;
		return;
	}

	processNode(scene->mRootNode, scene);

}


void ZZ::Model::processNode(aiNode * node, const aiScene * scene)
{
	for (size_t i = 0, length = node->mNumMeshes; i < length; i++)
	{
		aiMesh* aimesh = scene->mMeshes[node->mMeshes[i]];
		Mesh mesh;
		processMesh(aimesh, scene, &mesh);
		meshes.emplace_back(mesh);
	}
	for (size_t i = 0, length = node->mNumChildren; i < length; i++)
	{
		auto child = node->mChildren[i];
		processNode(child, scene);
	}
}

void Model::processMesh(aiMesh * mesh, const aiScene * scene, Mesh * outMesh)
{
	for (size_t i = 0; i < mesh->mNumVertices; i++)
	{
		Vertex vertex;
		vertex.Position.x = mesh->mVertices[i].x;
		vertex.Position.y = mesh->mVertices[i].y;
		vertex.Position.z = mesh->mVertices[i].z;

		if (mesh->mNormals)
		{
			vertex.Normal.x = mesh->mNormals[i].x;
			vertex.Normal.y = mesh->mNormals[i].y;
			vertex.Normal.z = mesh->mNormals[i].z;
		}

		if (mesh->mTextureCoords[0] != NULL)
		{
			vertex.TexCoords.x = mesh->mTextureCoords[0][i].x;
			vertex.TexCoords.y = mesh->mTextureCoords[0][i].y;
		}
		else
		{
			vertex.TexCoords = glm::vec2(0, 0);
		}

		// tangent
		if (mesh->mTangents)
		{
			vertex.Tangent.x = mesh->mTangents[i].x;
			vertex.Tangent.y = mesh->mTangents[i].y;
			vertex.Tangent.z = mesh->mTangents[i].z;
		}
		// bitangent
		if (mesh->mBitangents)
		{
			vertex.Bitangent.x = mesh->mBitangents[i].x;
			vertex.Bitangent.y = mesh->mBitangents[i].y;
			vertex.Bitangent.z = mesh->mBitangents[i].z;
		}

		outMesh->Vertices.emplace_back(vertex);
	}

	// now wak through each of the mesh's faces (a face is a mesh its triangle) and retrieve the corresponding vertex indices.
	for (unsigned int i = 0; i < mesh->mNumFaces; i++)
	{
		aiFace face = mesh->mFaces[i];
		// retrieve all indices of the face and store them in the indices vector
		for (unsigned int j = 0; j < face.mNumIndices; j++)
			outMesh->Indices.push_back(face.mIndices[j]);
	}

	// process materials
	aiMaterial* material = scene->mMaterials[mesh->mMaterialIndex];
	// we assume a convention for sampler names in the shaders. Each diffuse texture should be named
	// as 'texture_diffuseN' where N is a sequential number ranging from 1 to MAX_SAMPLER_NUMBER. 
	// Same applies to other texture as the following list summarizes:
	// diffuse: texture_diffuseN
	// specular: texture_specularN
	// normal: texture_normalN

	// 1. diffuse maps
	vector<Texture> diffuseMaps = loadMaterialTextures(material, aiTextureType_DIFFUSE, "texture_diffuse");
	outMesh->textures.insert(outMesh->textures.end(), diffuseMaps.begin(), diffuseMaps.end());
	// 2. specular maps
	vector<Texture> specularMaps = loadMaterialTextures(material, aiTextureType_SPECULAR, "texture_specular");
	outMesh->textures.insert(outMesh->textures.end(), specularMaps.begin(), specularMaps.end());
	// 3. normal maps
	std::vector<Texture> normalMaps = loadMaterialTextures(material, aiTextureType_HEIGHT, "texture_normal");
	outMesh->textures.insert(outMesh->textures.end(), normalMaps.begin(), normalMaps.end());
	// 4. height maps
	std::vector<Texture> heightMaps = loadMaterialTextures(material, aiTextureType_AMBIENT, "texture_height");
	outMesh->textures.insert(outMesh->textures.end(), heightMaps.begin(), heightMaps.end());
}

vector<Texture> Model::loadMaterialTextures(aiMaterial * mat, aiTextureType type, string typeName)
{
	vector<Texture> textures;
	for (unsigned int i = 0; i < mat->GetTextureCount(type); i++)
	{
		aiString str;
		mat->GetTexture(type, i, &str);
		// check if texture was loaded before and if so, continue to next iteration: skip loading a new texture
		bool skip = false;
		for (unsigned int j = 0; j < textures_loaded.size(); j++)
		{
			if (std::strcmp(textures_loaded[j].path.data(), str.C_Str()) == 0)
			{
				textures.push_back(textures_loaded[j]);
				skip = true; // a texture with the same filepath has already been loaded, continue to next one. (optimization)
				break;
			}
		}
		if (!skip)
		{   // if texture hasn't been loaded already, load it
			Texture texture;
			texture.id = BuildGLTexture(str.C_Str());
			texture.type = typeName;
			texture.path = str.C_Str();
			textures.push_back(texture);
			textures_loaded.push_back(texture);  // store it as texture loaded for entire model, to ensure we won't unnecesery load duplicate textures.
		}
	}
	return textures;
}

GLuint Model::BuildGLTexture(const std::string & fileName)
{
	auto image = AssetLoader::LoadImage(fileName);
	if (image.Empty()) return 0;
	GLuint id;
	glGenTextures(1, &id);
	glBindTexture(GL_TEXTURE_2D, id);
	GLenum format;
	if (image.Channels() == 1)
		format = GL_RED;
	else if (image.Channels() == 3)
		format = GL_RGB;
	else if (image.Channels() == 4)
		format = GL_RGBA;

	glTexImage2D(GL_TEXTURE_2D, 0, format, image.Width(), image.Height(), 0, format, GL_UNSIGNED_BYTE, image.Data());
	glGenerateMipmap(GL_TEXTURE_2D);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	return id;
}

void ZZ::Model::BuildBuffer()
{
	for (auto& mesh : meshes)
	{
		mesh.BuildBuffer();
	}
}

void ZZ::Model::Draw(const Shader & shader)
{
	for (auto& mesh : meshes)
	{
		mesh.Draw(shader);
	}
}


