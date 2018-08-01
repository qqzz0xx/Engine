#pragma once
#include "IApplication.h"
#include "OpenGLApplication.h"
#include "OpenGLGraphicsManager.h"
#include "AppConfig.h"
#include "StepTimer.h"

namespace ZZ {
	IApplication* g_pApp = static_cast<IApplication*>(new OpenGLApplication);
	GraphicsManager* g_pGraphicsManager = static_cast<GraphicsManager*>(new OpenGLGraphicsManager);
	AppConfig* g_pAppConfig = static_cast<AppConfig*>(new AppConfig);
	StepTimer* g_pTimer = static_cast<StepTimer*>(new StepTimer);
}

