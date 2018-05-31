#pragma once
#include "GraphicsManager.h"
#include <d2d1.h>

namespace ZZ {
	class D2DGraphicsManager : public GraphicsManager
	{
	public:

		virtual int Init() override;
		virtual void Exit() override;
		virtual void Update() override;

		// Initialize device-independent resources.
		HRESULT CreateDeviceIndependentResources();

		// Initialize device-dependent resources.
		HRESULT CreateDeviceResources();

		// Release device-dependent resource.
		void DiscardDeviceResources();

		// Draw content.
		HRESULT OnRender();
	private:
		ID2D1Factory * m_pDirect2dFactory;
		ID2D1HwndRenderTarget* m_pRenderTarget;
		ID2D1SolidColorBrush* m_pLightSlateGrayBrush;
		ID2D1SolidColorBrush* m_pCornflowerBlueBrush;
	};
}

