#pragma once
#include <string>

namespace ZZ {
	class AppConfig
	{
	public:
		std::string appName = "Main";
		int screenWidth = 800;
		int screenHeight = 600;
		int redBits = 8;
		int greenBits = 8;
		int blueBits = 8;
		int alphaBits = 8;
		int depthBits = 24;
		int stencilBits = 0;

		std::string resPath = "c:\\GameEngineProjects\\Engine\\res";
	};

	extern AppConfig * g_pAppConfig;
}