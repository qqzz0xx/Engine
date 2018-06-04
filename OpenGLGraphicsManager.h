#pragma once
#include "GraphicsManager.h"
#include "glad/glad.h"
namespace ZZ {
	class OpenGLGraphicsManager : public GraphicsManager
	{
	public:

		virtual int Init() override;
		virtual void Exit() override;
		virtual void Update() override;

	};
}
