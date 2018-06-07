#include "OpenGLApplication.h"
#include <tchar.h>
#include "glad/glad.h"

using namespace std;

namespace ZZ {
	extern IApplication* g_pApp;
}

int ZZ::OpenGLApplication::Init()
{
	HRESULT result = S_OK;
	//create main window
	CreateMainWindow();
	PIXELFORMATDESCRIPTOR pfd;
	memset(&pfd, 0, sizeof(PIXELFORMATDESCRIPTOR));
	pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);
	pfd.nVersion = 1;
	pfd.dwFlags = PFD_DOUBLEBUFFER | PFD_SUPPORT_OPENGL | PFD_DRAW_TO_WINDOW;
	pfd.iPixelType = PFD_TYPE_RGBA;
	pfd.cColorBits = 32;
	pfd.cDepthBits =0;
	pfd.iLayerType = PFD_MAIN_PLANE;

	HWND hWnd = reinterpret_cast<Win32Application*>(g_pApp)->GetHWND();
	HDC  hDC = GetDC(hWnd);
	// Set a temporary default pixel format.
	int nPixelFormat = ChoosePixelFormat(hDC, &pfd);
	if (nPixelFormat == 0) return -1;

	result = SetPixelFormat(hDC, nPixelFormat, &pfd);
	if (result != 1)
	{
		return -1;
	}

	// Create a temporary rendering context.
	m_RenderContext = wglCreateContext(hDC);
	if (!m_RenderContext)
	{
		return -1;
	}

	// Set the temporary rendering context as the current rendering context for this window.
	result = wglMakeCurrent(hDC, m_RenderContext);
	if (result != 1)
	{
		return -1;
	}

	if (!gladLoadWGL(hDC)) {
		printf("WGL initialize failed!\n");
		result = -1;
	}
	else {
		result = 0;
		printf("WGL initialize finished!\n");
	}


	BaseApplication::Init();

	return result;
}

void ZZ::OpenGLApplication::Update()
{
	BaseApplication::Update();
	MSG msg;
	if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
}

void ZZ::OpenGLApplication::Exit()
{
}
