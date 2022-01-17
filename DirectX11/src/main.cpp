#include <Windows.h>

#include "DirectX/DirectXGraphics.h"
#include "WindowsAPI/WindowsAPI.h"

int WINAPI WinMain(
	HINSTANCE hInstace,
	HINSTANCE hPrevInstance,
	LPSTR lpCmpLine,
	int nCmdshow)
{
	WindowsAPI window;
	if (!window.Draw("test", 640, 480)) { return 0; }

	DirectXGraphics directGraphics;
	if (!directGraphics.Init()) { return 0; }

	while (true)
	{
		MSG msg;

		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
			{
				break;
			}
			else
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
		}
		else
		{
			directGraphics.StartRendering();

			directGraphics.FinishRendering();
		}
	}

	directGraphics.Releace();
}
