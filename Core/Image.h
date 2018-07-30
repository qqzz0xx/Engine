#pragma once
#include "Header.h"
#include "Buffer.h"
class Image
{
public:
	Image();
	Image(const std::string& fileName);
	size_t Width() { return m_Width; }
	size_t Height() { return m_Height; }
	size_t Channels() { return m_Channels; }
	uint8* Data() { return m_Buffer.Data(); }
protected:
	size_t m_Width;
	size_t m_Height;
	size_t m_Channels;
	Buffer m_Buffer;
};

