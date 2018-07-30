#include "Image.h"
#include "AssetLoader.h"


Image::Image()
{
	m_Width = 0;
	m_Height = 0;
	m_Channels = 0;
}

Image::Image(const std::string & fileName)
{
	m_Buffer = AssetLoader::ReadText(fileName);
	int width, height, nrChannels;
	stbi_load_from_memory(m_Buffer.Data(), m_Buffer.Size(), &width, &height, &nrChannels, 0);
	m_Width = width;
	m_Height = height;
	m_Channels = nrChannels;
}

