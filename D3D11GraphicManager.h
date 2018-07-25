#pragma once
#include "GraphicsManager.h"
#include <d3d11.h>
#include <d3d11_1.h>
#include <d3dcommon.h>
#include <dxgi.h>
#include <DirectXMath.h>
#include <DirectXPackedVector.h>
#include <DirectXColors.h>

namespace ZZ {
	class D3D11GraphicManager : public GraphicsManager
	{
	public:

		virtual int Init() override;
		virtual void Exit() override;
		virtual void Update() override;

		HRESULT CreateDevice();
		void InitScene();
		void UpdateScene();
		void OnRender();

	private:
		IDXGISwapChain* m_pSwapChain = NULL;
		ID3D11Device* m_pD3D11Device = NULL;
		ID3D11DeviceContext* m_pDeviceContext = NULL;
		ID3D11RenderTargetView* m_pRenderTargetView = NULL;
	};
}
