#ifndef WINDOWS_API_H
#define WINDOWS_API_H

#include <Windows.h>

class WindowsAPI
{
public:
	static const char* m_windowClassName;

public:
	bool Draw(const char* window_name_, int widht_, int height_);

	static LRESULT CALLBACK Procedure(HWND window_handle_, UINT message_id_, WPARAM wparam, LPARAM lparam);


private:
	WNDCLASSEX m_windowClass;
};

#endif // !WINDOW_API_H
