#pragma once
#include "GraphicsManager.h"
#include <d3d11.h>
namespace ZZ {
	class D3D11GraphicsManager : public GraphicsManager
	{
	public:
		virtual int Init() override;
		virtual void Exit() override;
		virtual void Update() override;
	private:
		void CreateDevice();
		
	private:
		IDXGISwapChain * m_pSwapchain = nullptr;

	};
}