#include "Game.h"

Game game;

ATOM RegisterClassWindow(HINSTANCE currentInstance);

//entry point for a Windows program
int WINAPI WinMain(HINSTANCE currentInstance, HINSTANCE previousInstance, LPSTR ArgCmdLines,
	int cmdShowMode)
{
	MSG message;
	HWND window;

	//register the class
	RegisterClassWindow(currentInstance);

	//set up the screen in windowed or fullscreen mode?
	DWORD style;

	if (FULLSCREEN)
	{
		style = WS_EX_TOPMOST | WS_VISIBLE | WS_POPUP;
	}
	else
	{
		style = WS_OVERLAPPED;
	}

	//create a new window
	window = CreateWindow(
		APP_TITLE, //window class
		APP_TITLE, //title bar
		style, //window style
		CW_USEDEFAULT, //x position of window
		CW_USEDEFAULT, //y position of window
		SCREEN_WIDTH, //width of the window
		SCREEN_HEIGHT, //height of the window
		NULL, //parent window
		NULL, //menu
		currentInstance, //application instance
		NULL); //window parameters

	//was there an error creating the window?
	if (!window)
	{
		IOHandler::ExportError(window, L"Error creating the window");
		return 0;
	}

	//display the window
	ShowWindow(window, cmdShowMode);
	UpdateWindow(window);

	DirectX directX = game.GetDirectX();

	//make sure Direct3D objects was created okay
	if (!directX.GetDirectXGraphic().InitDirect3DObjects(window, SCREEN_WIDTH, SCREEN_HEIGHT, 
		FULLSCREEN))
	{
		return 0;
	}

	//initialize the game
	if (!game.InitGame(window))
	{
		return 0;
	}

	//make sure DirectInput objects was created okay
	if (!directX.GetDirectInput().InitDirectInputObjects(window))
	{
		return 0;
	}

	// *
	//make sure DirectSound objects was created okay
	//if (!directX.GetDirectSound().InitDirectSoundObjects(window))
	//{
	//	return 0;
	//}

	// main message loop
	bool done = 0;

	while (!done)
	{
		if (PeekMessage(&message, NULL, 0, 0, PM_REMOVE))
		{
			//look for quit message
			if (message.message == WM_QUIT)
			{
				done = 1;
			}

			//decode and pass messages on to WndProc
			TranslateMessage(&message);
			DispatchMessage(&message);
		}
		else
		{
			//process game loop (else prevents running after window is closed)
			game.RunGame(window);
		}
	}

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

//helper function to set up the window properties
ATOM RegisterClassWindow(HINSTANCE currentInstance)
{
	//create the window class structure
	WNDCLASSEX windowClass;

	//fill the struct with info
	windowClass.cbSize = sizeof(WNDCLASSEX);
	windowClass.style = CS_HREDRAW | CS_VREDRAW;
	windowClass.lpfnWndProc = (WNDPROC)WinProc;
	windowClass.cbClsExtra = 0;
	windowClass.cbWndExtra = 0;
	windowClass.hInstance = currentInstance;
	windowClass.hIcon = NULL;
	windowClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	windowClass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	windowClass.lpszMenuName = NULL;
	windowClass.lpszClassName = APP_TITLE;
	windowClass.hIconSm = NULL;

	//set up the window with the class info
	return RegisterClassEx(&windowClass);
}