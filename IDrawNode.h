#pragma once
#include "Shader.h"
namespace ZZ
{
	class IDrawNode
	{
	public:
		virtual void BuildBuffer() = 0;
		virtual void Draw(const Shader& shader) = 0;
	};
}