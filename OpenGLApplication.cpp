#include "OpenGLApplication.h"
#include <tchar.h>

using namespace std;

int ZZ::OpenGLApplication::Init()
{
	HRESULT hr = S_OK;
	//create gl init window
	HINSTANCE hInstance = GetModuleHandle(NULL);
	WNDCLASSEX wc;
	memset(&wc, 0, sizeof(WNDCLASSEX));
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
	wc.lpfnWndProc = DefWindowProc;
	wc.lpszClassName = _T("InitWindow");
	wc.hInstance = hInstance;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
	
	RegisterClassEx(&wc);

	DWORD Style = WS_OVERLAPPEDWINDOW | WS_CLIPSIBLINGS | WS_CLIPCHILDREN;
	// create the window and use the result as the handle
	HWND TemphWnd = CreateWindowEx(0,
		wc.lpszClassName,      // name of the window class
		"Init",                 // title of the window
		Style,              // window style
		CW_USEDEFAULT,                    // x-position of the window
		CW_USEDEFAULT,                    // y-position of the window
		0,             // width of the window
		0,            // height of the window
		NULL,                             // we have no parent window, NULL
		NULL,                             // we aren't using menus, NULL
		hInstance,                        // application handle
		this);                            // pass pointer to current object

										  // display the window on the screen

	// gl init context
	HDC TemphDC = GetDC(TemphWnd);
	m_RenderContext = wglCreateContext(TemphDC);
	if (!m_RenderContext)
	{
		printf("wglCreateContext failed!\n");
		return -1;
	}

	hr = wglMakeCurrent(TemphDC, m_RenderContext);

	hr = gladLoadWGL(TemphDC);

	hr = wglMakeCurrent(NULL, NULL);

	wglDeleteContext(m_RenderContext);
	ReleaseDC(TemphWnd, TemphDC);
	DestroyWindow(TemphWnd);

	//create main window
	CreateMainWindow();

	BaseApplication::Init();

	return hr;
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
