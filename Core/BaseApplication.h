#pragma once
#include "IApplication.h"
#include "GraphicsManager.h"


namespace ZZ {
	class BaseApplication : public IApplication
	{
	public:
		virtual int Init();
		virtual void Exit();
		// One cycle of the main loop
		virtual void Update();

		virtual bool IsQuit();

	protected:
		// Flag if need quit the main loop of the application
		bool m_bQuit;
	};
}

