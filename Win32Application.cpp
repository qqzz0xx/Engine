#include "Win32Application.h"

#include <tchar.h>


int ZZ::Win32Application::Init()
{
	BaseApplication::Init();

	CreateMainWindow();

	return 0;
}

void ZZ::Win32Application::Exit()
{
	BaseApplication::Exit();

}

void ZZ::Win32Application::Update()
{
	BaseApplication::Update();
	MSG msg;
	if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

}

bool ZZ::Win32Application::IsQuit()
{
	return false;
}

HWND ZZ::Win32Application::GetHWND()
{
	return m_hWnd;
}

void ZZ::Win32Application::CreateMainWindow()
{
	// get the HINSTANCE of the Console Program
	HINSTANCE hInstance = GetModuleHandle(NULL);

	// this struct holds information for the window class
	WNDCLASSEX wc;

	// clear out the window class for use
	ZeroMemory(&wc, sizeof(WNDCLASSEX));

	// fill in the struct with the needed information
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = WindowProc;
	wc.hInstance = hInstance;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
	wc.lpszClassName = _T("GameEngineFromScratch");

	// register the window class
    RegisterClassEx(&wc);

	// create the window and use the result as the handle
	m_hWnd = CreateWindowEx(0,
		_T("GameEngineFromScratch"),      // name of the window class
		m_Config.appName.c_str(),                 // title of the window
		WS_OVERLAPPEDWINDOW,              // window style
		CW_USEDEFAULT,                    // x-position of the window
		CW_USEDEFAULT,                    // y-position of the window
		m_Config.screenWidth,             // width of the window
		m_Config.screenHeight,            // height of the window
		NULL,                             // we have no parent window, NULL
		NULL,                             // we aren't using menus, NULL
		hInstance,                        // application handle
		this);                            // pass pointer to current object

										  // display the window on the screen

	ShowWindow(m_hWnd, SW_SHOW);
}

LRESULT ZZ::Win32Application::WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{

	return DefWindowProc(hWnd, message, wParam, lParam);
}
