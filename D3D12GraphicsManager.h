#pragma once
#include "GraphicsManager.h"
namespace ZZ {
	class D3D12GraphicsManager : public GraphicsManager
	{
	public:

		virtual int Init() override;
		virtual void Exit() override;
		virtual void Update() override;

	};
}