#include "D2DGraphicsManager.h"
#include "Win32Application.h"

namespace ZZ {
	extern IApplication* g_pApp;
}

int ZZ::D2DGraphicsManager::Init()
{
	return 0;
}

void ZZ::D2DGraphicsManager::Exit()
{
}

void ZZ::D2DGraphicsManager::Update()
{
}

HRESULT ZZ::D2DGraphicsManager::CreateDeviceIndependentResources()
{
	HRESULT hr = S_OK;

	// Create a Direct2D factory.
	hr = D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, &m_pDirect2dFactory);

	return hr;
}

HRESULT ZZ::D2DGraphicsManager::CreateDeviceResources()
{
	HRESULT hr = S_OK;

	if (!m_pRenderTarget)
	{
		HWND hwnd = ((Win32Application*)g_pApp)->GetHWND();
		RECT rc;
		GetClientRect(hwnd, &rc);

		D2D1_SIZE_U size = D2D1::SizeU(
			rc.right - rc.left,
			rc.bottom - rc.top
		);

		// Create a Direct2D render target.
		hr = m_pDirect2dFactory->CreateHwndRenderTarget(
			D2D1::RenderTargetProperties(),
			D2D1::HwndRenderTargetProperties(hwnd, size),
			&m_pRenderTarget
		);


		if (SUCCEEDED(hr))
		{
			// Create a gray brush.
			hr = m_pRenderTarget->CreateSolidColorBrush(
				D2D1::ColorF(D2D1::ColorF::LightSlateGray),
				&m_pLightSlateGrayBrush
			);
		}
		if (SUCCEEDED(hr))
		{
			// Create a blue brush.
			hr = m_pRenderTarget->CreateSolidColorBrush(
				D2D1::ColorF(D2D1::ColorF::CornflowerBlue),
				&m_pCornflowerBlueBrush
			);
		}
	}

	return hr;
}

void ZZ::D2DGraphicsManager::DiscardDeviceResources()
{
}

HRESULT ZZ::D2DGraphicsManager::OnRender()
{
	return E_NOTIMPL;
}


