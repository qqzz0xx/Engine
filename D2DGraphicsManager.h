#pragma once
#include "GraphicsManager.h"
#include <d2d1.h>

template<class Interface>
inline void SafeRelease(
	Interface **ppInterfaceToRelease
)
{
	if (*ppInterfaceToRelease != NULL)
	{
		(*ppInterfaceToRelease)->Release();

		(*ppInterfaceToRelease) = NULL;
	}
}
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

		// Resize the render target.
		void OnResize(
			UINT width,
			UINT height
		);
	private:
		ID2D1Factory * m_pDirect2dFactory = NULL;
		ID2D1HwndRenderTarget* m_pRenderTarget = NULL;
		ID2D1SolidColorBrush* m_pLightSlateGrayBrush = NULL;
		ID2D1SolidColorBrush* m_pCornflowerBlueBrush = NULL;
	};
}

