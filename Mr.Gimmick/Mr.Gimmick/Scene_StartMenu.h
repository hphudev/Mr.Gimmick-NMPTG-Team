#pragma once
#include "Scene.h"

#define STARTBUTTON 0
#define CONTINUEBUTTON 1

class Scene_StartMenu :
	public Scene
{
	int buttonOnMainMeNu = STARTBUTTON;
	float posWidthMainMenu = -30;

public:
	Scene_StartMenu() {};
	~Scene_StartMenu() {};

	Scene_StartMenu(HWND window);
	void Run(DWORD time, DWORD& timeStart);

	void OnKeyUp(int keycode) {  };
	void OnKeyDown(int keycode) { nextScene = 3; };
};

