#pragma once

#include <d3d9.h>
#include "Handler.h"
#include "Game.h"
//#include "SceneManager.h"

class WindowHandler : public Handler
{
public:
	ATOM RegisterClassWindow(HINSTANCE currentInstance, WNDPROC WinProc);
	HWND CreateGameWindow(HINSTANCE currentInstance, WNDPROC WinProc);
	void DisplayGameWidow(HWND window, int cmdShowMode);
	void RunGameWindow(MSG& message, HWND window, Game game);
};