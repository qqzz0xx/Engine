#pragma once
#include "GraphicsManager.h"
#include "Header.h"
#include "Shader.h"
#include "Triangles.h"
#include "glad/glad.h"

#include "Model.h"

namespace ZZ {
	class OpenGLGraphicsManager : public GraphicsManager
	{
	public:

		virtual int Init() override;
		virtual void Exit() override;
		virtual void Update() override;

		void BuildBuffers();
		void InitGLState();

	private:
		struct DrawBatchContext {
			GLuint  vao;
			GLenum  mode;
			GLenum  type;
			GLsizei count;
		};

		std::vector<DrawBatchContext> m_Vao;
		Shader shader;
		Triangles triangle;
		Model model;
	};
}
