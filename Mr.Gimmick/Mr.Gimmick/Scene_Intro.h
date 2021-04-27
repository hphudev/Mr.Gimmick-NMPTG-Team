#pragma once
#include "Scene.h"
#include "ImmovableTile.h"
#include <iostream>
#include <list>


#define BACKGROUND_COLOR D3DCOLOR_XRGB(0, 255, 0)
class Scene_Intro :
	public Scene
{

public:
	Scene_Intro();
	~Scene_Intro();

	Scene_Intro(HWND window);
	void Run(DWORD time, DWORD& timeStart);
	void OnKeyUp(int keycode) {  };
	void OnKeyDown(int keycode) { nextScene = 3; };
};

