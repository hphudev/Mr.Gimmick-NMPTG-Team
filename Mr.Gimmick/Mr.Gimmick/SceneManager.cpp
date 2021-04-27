#include "SceneManager.h"
#include<conio.h>
#define KEY_DOWN(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0)
#define KEY_UP(vk_code) ((GetAsyncKeyState(vk_code) * 0x8000) ? 1 : 0)

SceneManager::SceneManager(HWND window)
{
	//scene = new Scene_StartMenu(window);
	//scene = new Scene_Map(window);
	//scene = new Scene_Play(window);
	this->window = window;
	scene = new Scene_Intro(window);
}
SceneManager::~SceneManager()
{

}
void SceneManager::Run()
{
	MSG msg;
	int done = 0;
	DWORD frameStart = GetTickCount();
	DWORD tickPerFrame = 1000 / MAX_FRAME_RATE;

	DWORD timeStart = GetTickCount();
	while (!done)
	{
		DWORD now = GetTickCount();
		DWORD dt = now - frameStart;
		if (dt >= tickPerFrame)
		{
			if (scene->GetNextScene() != -1)
			{
				InitNextScene(scene->GetNextScene(), timeStart);
			}
			else
				scene->Run(dt, timeStart);
		}
		else Sleep(tickPerFrame - dt);

	}
}
void SceneManager::InitNextScene(int id, DWORD& timeStart)
{

	timeStart = GetTickCount();
	switch (id)
	{
	case INTRO:
		scene = new Scene_Intro(window);
		break;
	case STARTMENU:
		scene = new Scene_StartMenu(window);
		break;
	case MAP:
		scene = new Scene_Map(window);
		break;
	case GAMEPLAY:
		scene = new Scene_Play(window);
		break;
	}
}
void SceneManager::OnKeyUp(int keycode)
{
	scene->OnKeyUp(keycode);
}
void SceneManager::OnKeyDown(int keycode)
{
	scene->OnKeyDown(keycode);
}

