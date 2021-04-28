#pragma once
#include "Scene.h"

#define STARTBUTTON 0
#define CONTINUEBUTTON 1

class SceneStartMenu :
	public Scene
{
	int buttonOnMainMeNu = STARTBUTTON;
	float posWidthMainMenu = -30;

public:
	SceneStartMenu() {};
	~SceneStartMenu() {};

	SceneStartMenu(HWND window);
	void Run(DWORD time, DWORD& timeStart);

	void OnKeyUp(int keycode) {  };
	void OnKeyDown(int keycode) { nextScene = 3; };
};

