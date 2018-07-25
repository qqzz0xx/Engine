#include "D3D11GraphicManager.h"
#include "Win32Application.h"
#include <windowsx.h>

using namespace DirectX;
using namespace DirectX::PackedVector;

namespace ZZ {
	extern IApplication* g_pApp;
}

HRESULT ZZ::D3D11GraphicManager::CreateDevice()
{
	HRESULT hr;

	HWND hwnd = ((Win32Application*)g_pApp)->GetHWND();
	RECT rc;
	GetClientRect(hwnd, &rc);

	//Describe our Buffer
	DXGI_MODE_DESC bufferDesc;

	ZeroMemory(&bufferDesc, sizeof(DXGI_MODE_DESC));

	bufferDesc.Width = rc.right - rc.left;
	bufferDesc.Height = rc.bottom - rc.top;
	bufferDesc.RefreshRate.Numerator = 60;
	bufferDesc.RefreshRate.Denominator = 1;
	bufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	bufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
	bufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;

	//Describe our SwapChain
	DXGI_SWAP_CHAIN_DESC swapChainDesc;

	ZeroMemory(&swapChainDesc, sizeof(DXGI_SWAP_CHAIN_DESC));

	swapChainDesc.BufferDesc = bufferDesc;
	swapChainDesc.SampleDesc.Count = 1;
	swapChainDesc.SampleDesc.Quality = 0;
	swapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	swapChainDesc.BufferCount = 1;
	swapChainDesc.OutputWindow = hwnd;
	swapChainDesc.Windowed = TRUE;
	swapChainDesc.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;

	//Create our SwapChain
	hr = D3D11CreateDeviceAndSwapChain(NULL, D3D_DRIVER_TYPE_HARDWARE, NULL, NULL, NULL, NULL,
		D3D11_SDK_VERSION, &swapChainDesc, &m_pSwapChain, &m_pD3D11Device, NULL, &m_pDeviceContext);

	//Create our BackBuffer
	ID3D11Texture2D* BackBuffer;
	hr = m_pSwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (void**)&BackBuffer);

	//Create our Render Target
	hr = m_pD3D11Device->CreateRenderTargetView(BackBuffer, NULL, &m_pRenderTargetView);
	BackBuffer->Release();

	//Set our Render Target
	m_pDeviceContext->OMSetRenderTargets(1, &m_pRenderTargetView, NULL);

	return hr;
}

void ZZ::D3D11GraphicManager::InitScene()
{
	HRESULT hr;
	//Compile Shaders from shader file
	ID3DBlob *VS, *PS;
	//D3DReadFileToBlob(L"copy.vso", &VS);


	D3D11_INPUT_ELEMENT_DESC layout[] =
	{
		{ "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0 },
	};
}

void ZZ::D3D11GraphicManager::UpdateScene()
{
}

int ZZ::D3D11GraphicManager::Init()
{
	auto hr = CreateDevice();
	InitScene();
	return hr;
}

void ZZ::D3D11GraphicManager::Exit()
{
}

void ZZ::D3D11GraphicManager::Update()
{
	UpdateScene();
	OnRender();
}

void ZZ::D3D11GraphicManager::OnRender()
{
	static float red = 0.0f;
	static float green = 0.0f;
	static float blue = 0.0f;
	static int colormodr = 1;
	static  int colormodg = 1;
	static int colormodb = 1;

	//Update the colors of our scene
	red += colormodr * 0.00005f;
	green += colormodg * 0.00002f;
	blue += colormodb * 0.00001f;

	if (red >= 1.0f || red <= 0.0f)
		colormodr *= -1;
	if (green >= 1.0f || green <= 0.0f)
		colormodg *= -1;
	if (blue >= 1.0f || blue <= 0.0f)
		colormodb *= -1;

	//Clear our backbuffer to the updated color
	const XMVECTORF32 bgColor = { red, green, blue, 1.0f };

	m_pDeviceContext->ClearRenderTargetView(m_pRenderTargetView, bgColor);

	//Present the backbuffer to the screen
	m_pSwapChain->Present(0, 0);

}
