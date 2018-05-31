#include <stdio.h>
#include "IApplication.h"

using namespace ZZ;

namespace ZZ {
	extern IApplication* g_pApp;
}

int main(int argc, char** argv) {
	int ret;

	if ((ret = g_pApp->Init()) != 0) {
		printf("App Initialize failed, will exit now.");
		return ret;
	}

	while (!g_pApp->IsQuit()) {
		g_pApp->Update();
	}

	g_pApp->Exit();

	return 0;
}

