#pragma once
#include "IBehavior.h"

namespace ZZ {
	class GraphicsManager :  public IBehavior
	{
	public:
		// Í¨¹ý IBehavior ¼Ì³Ð
		virtual int Init() override;
		virtual void Exit() override;
		virtual void Update() override;


	};

	extern GraphicsManager* g_pGraphicsManager;
}

