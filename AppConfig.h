#pragma once
#include <string>

namespace ZZ {
	struct AppConfig
	{
		std::string appName = "Main";
		int screenWidth = 800;
		int screenHeight = 600;
		int redBits = 8;
		int greenBits = 8;
		int blueBits = 8;
		int alphaBits = 8;
		int depthBits = 24;
		int stencilBits = 0;
	};

	extern AppConfig * g_pAppConfig;
}