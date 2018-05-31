#pragma once
#include "IBehavior.h"
namespace ZZ {
	class IApplication : public IBehavior
	{
	public:
		virtual int Init() = 0;
		virtual void Exit() = 0;
		virtual void Update() = 0;
		virtual bool IsQuit() = 0;
	};
}