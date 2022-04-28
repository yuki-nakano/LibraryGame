﻿#include "Mouse.h"

#include "../WindowsAPI/WindowsAPI.h"

namespace engine
{
	void Mouse::Update()
	{
		GetCursorPos(&screenPos);

		clientPos = screenPos;

		HWND windowHandle = FindWindow(WindowsAPI::m_windowClassName, nullptr);
		ScreenToClient(windowHandle, &clientPos);
	}
}