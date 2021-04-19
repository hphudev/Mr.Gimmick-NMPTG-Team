#include "Game.h"
#include "WindowHandler.h"

Game game;

LRESULT WINAPI WinProc(HWND window, UINT message, WPARAM wParameter, LPARAM lParameter);

//entry point for a Windows program
int WINAPI WinMain(HINSTANCE currentInstance, HINSTANCE previousInstance, LPSTR argCmdLines, 
	int cmdShowMode)
{
	WindowHandler windowHandler;
	HWND window = windowHandler.CreateGameWindow(currentInstance, WinProc);
	windowHandler.DisplayGameWidow(window, cmdShowMode);

	if (!game.InitGame(window))
	{
		return 0;
	}

	MSG message;
	windowHandler.RunGameWindow(message, window, game);

	return message.wParam;
}

//window event callback function
LRESULT WINAPI WinProc(HWND window, UINT message, WPARAM wParameter, LPARAM lParameter)
{
	switch (message)
	{
		case WM_DESTROY:
		{
			//call the "front-end" shutdown function
			game.EndGame(window);

			//tell Windows to kill this program
			PostQuitMessage(0);

			return 0;
		}
	}

	return DefWindowProc(window, message, wParameter, lParameter);
}