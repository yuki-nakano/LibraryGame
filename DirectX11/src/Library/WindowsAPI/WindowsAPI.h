#ifndef WINDOWS_API_H
#define WINDOWS_API_H

#include <Windows.h>
#include <string>

#include "../Utility/Singleton.h"

namespace engine
{
	class WindowsAPI : public Singleton<WindowsAPI>
	{
	public:
		static const char* m_windowClassName;

	private:
		friend class Singleton<WindowsAPI>;

		WindowsAPI() {};
		~WindowsAPI() {};

	public:
		bool CheckMessage();

		bool Draw(const std::string& window_name_, const int& widht_, const int& height_);

		static LRESULT CALLBACK Procedure(HWND window_handle_, UINT message_id_, WPARAM wparam, LPARAM lparam);

	private:
		WNDCLASSEX m_windowClass;

		MSG msg;
	};
}
#endif // !WINDOW_API_H
