#include "Win32Application.h"
#include "D3D12GraphicsManager.h"
#include "D2DGraphicsManager.h"

namespace ZZ {
	IApplication* g_pApp = static_cast<IApplication*>(new Win32Application);
	GraphicsManager* g_pGraphicsManager = static_cast<GraphicsManager*>(new D2DGraphicsManager);
}