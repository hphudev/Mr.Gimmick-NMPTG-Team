#pragma once
#include "Scene.h"
#include "InanimatedTile.h"
#include <iostream>
#include <list>


#define BACKGROUND_COLOR D3DCOLOR_XRGB(0, 255, 0)
class SceneIntro :
	public Scene
{

public:
	SceneIntro();
	~SceneIntro();

	SceneIntro(HWND window);
	void Run(DWORD time, DWORD& timeStart);
	void OnKeyUp(int keycode) {  };
	void OnKeyDown(int keycode) { nextScene = 3; };
};

