#include "WindowsAPI.h"

const char* WindowsAPI::m_windowClassName = "WindowClass";

bool WindowsAPI::Draw(const char* window_name_, int widht_, int height_)
{
	m_windowClass = {
		sizeof(WNDCLASSEX),
		CS_HREDRAW | CS_VREDRAW,
		Procedure,
		0,
		0,
		GetModuleHandle(NULL),
		LoadIcon(NULL, IDI_APPLICATION),
		LoadCursor(NULL, IDC_ARROW),
		NULL,
		NULL,
		m_windowClassName,
		NULL };

	if (RegisterClassEx(&m_windowClass) == 0)
	{
		return false;
	}

	//ウィンドウ作成
	HWND windowHandle = CreateWindow(
		m_windowClassName,
		window_name_,
		(WS_OVERLAPPEDWINDOW ^ WS_THICKFRAME),
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		widht_,
		height_,
		NULL,
		NULL,
		GetModuleHandle(NULL),
		NULL);

	if (windowHandle == NULL)
	{
		return false;
	}

	//ウィンドウのリサイズ
	RECT windowRect;
	GetWindowRect(windowHandle, &windowRect);

	RECT clientRect;
	GetClientRect(windowHandle, &clientRect);

	int frameSizeX = (windowRect.right - windowRect.left) - (clientRect.right - clientRect.left);
	int frameSizeY = (windowRect.bottom - windowRect.top) - (clientRect.bottom - clientRect.top);

	SetWindowPos(
		windowHandle,
		NULL,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		frameSizeX + widht_,
		frameSizeY + height_,
		SWP_NOMOVE);

	ShowWindow(windowHandle, SW_SHOW);

	return true;
}

LRESULT WindowsAPI::Procedure(HWND window_handle_, UINT message_id_, WPARAM wparam_, LPARAM lparam_)
{
	return DefWindowProc(window_handle_, message_id_, wparam_, lparam_);
}
