#pragma once
#include "BaseApplication.h"
#include "AppConfig.h"
#include <windows.h>
#include <windowsx.h>

namespace ZZ {
	class Win32Application : public BaseApplication
	{
	public:
		// ͨ�� IApplication �̳�
		virtual int Init() override;
		virtual void Exit() override;
		virtual void Update() override;
		virtual bool IsQuit() override;

	protected:
		void CreateMainWindow();
		// the WindowProc function prototype
		static LRESULT CALLBACK WindowProc(HWND hWnd,
			UINT message,
			WPARAM wParam,
			LPARAM lParam);

	private:
		AppConfig m_Config;
		HWND m_hWnd;
	};

}