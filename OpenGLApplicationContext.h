#pragma once
#include "IApplication.h"
#include "OpenGLApplication.h"
#include "OpenGLGraphicsManager.h"

namespace ZZ {
	IApplication* g_pApp = static_cast<IApplication*>(new OpenGLApplication);
	GraphicsManager* g_pGraphicsManager = static_cast<GraphicsManager*>(new OpenGLGraphicsManager);
}

