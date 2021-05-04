#include "WindowHandler.h"

//helper function to set up the window properties
ATOM WindowHandler::RegisterClassWindow(HINSTANCE currentInstance, WNDPROC WinProc)
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

HWND WindowHandler::CreateGameWindow(HINSTANCE currentInstance, WNDPROC WinProc)
{
	//register the class
	RegisterClassWindow(currentInstance, WinProc);

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
	HWND window = CreateWindow(
		APP_TITLE, //window class
		APP_TITLE, //title bar
		style, //window style
		(1920 / 1.02 - SCREEN_WIDTH) / 2, //x position of window
		(1080 / 1.25 - SCREEN_HEIGHT) / 2, //y position of window
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
		return NULL;
	}

	return window;
}

void WindowHandler::DisplayGameWidow(HWND window, int cmdShowMode)
{
	ShowWindow(window, cmdShowMode);
	UpdateWindow(window);
}

void WindowHandler::RunGameWindow(MSG& message, HWND window, Game game)
{
	// main message loop
	bool done = 0;
	//SceneManager* sceneManager = new SceneManager(window);

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
			//sceneManager->Run();
		}
	}
}