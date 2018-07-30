#include <stdio.h>
#include "IApplication.h"
#include "GraphicsManager.h"
#include "AssetLoader.h"
#include "AppConfig.h"

using namespace ZZ;


namespace ZZ {
	extern IApplication* g_pApp;
	extern GraphicsManager* g_pGraphicsManager;
	extern AppConfig* g_pAppConfig;
}

int main(int argc, char** argv) {
	int ret;

	AssetLoader::AddSearchPath(g_pAppConfig->resPath);

	if ((ret = g_pApp->Init()) != 0) {
		printf("App Initialize failed, will exit now.");
		return ret;
	}
	if ((ret = g_pGraphicsManager->Init()) != 0) {
		printf("App Initialize failed, will exit now.");
		return ret;
	}


	while (!g_pApp->IsQuit()) {
		g_pApp->Update();
	}

	g_pApp->Exit();

	return 0;
}

