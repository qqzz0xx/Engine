#include "Win32Application.h"
#include "imgui.h"
#include "imgui_impl_opengl3.h"
#include "imgui_impl_win32.h"

#include <tchar.h>


int ZZ::Win32Application::Init()
{
	CreateMainWindow();
	BaseApplication::Init();

	// Setup Dear ImGui binding
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	ImGui_ImplWin32_Init(this->GetHWND());
	ImGui_ImplOpenGL3_Init();

	// Setup style
	ImGui::StyleColorsDark();

	return 0;
}

void ZZ::Win32Application::Exit()
{
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplWin32_Shutdown();
	ImGui::DestroyContext();

	BaseApplication::Exit();
}

void ZZ::Win32Application::Update()
{
	MSG msg;
	if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();

	BaseApplication::Update();

	// Rendering
	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

	SwapBuffers(m_hDC);
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
		g_pAppConfig->appName.c_str(),                 // title of the window
		WS_OVERLAPPEDWINDOW,              // window style
		CW_USEDEFAULT,                    // x-position of the window
		CW_USEDEFAULT,                    // y-position of the window
		g_pAppConfig->screenWidth,             // width of the window
		g_pAppConfig->screenHeight,            // height of the window
		NULL,                             // we have no parent window, NULL
		NULL,                             // we aren't using menus, NULL
		hInstance,                        // application handle
		this);                            // pass pointer to current object

										  // display the window on the screen

	ShowWindow(m_hWnd, SW_SHOW);
}
extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
LRESULT ZZ::Win32Application::WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{

	ImGui_ImplWin32_WndProcHandler(hWnd, message, wParam, lParam);
	return DefWindowProc(hWnd, message, wParam, lParam);
}
