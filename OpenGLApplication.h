#pragma once
#include "Win32Application.h"
#include "AppConfig.h"
#include "glad/glad_wgl.h"

#include <windows.h>
#include <windowsx.h>
namespace ZZ {
	class OpenGLApplication : public Win32Application
	{
	public:

		virtual int Init() override;

		virtual void Update() override;

		virtual void Exit() override;
	protected:
		HGLRC m_RenderContext;
	};
}
