#pragma once

#include "GameComponent.h"
#include "WindowHandler.h"
#include "Scene.h"
#include "Scene_Play.h"
#include "Scene_Intro.h"
#include "Scene_StartMenu.h"
#include "Scene_Map.h"

#define MAX_FRAME_RATE 120;


class SceneManager : public GameComponent
{
	int idScene = INTRO;
	Scene* scene;
	HWND window;
public:
	SceneManager(HWND window);
	~SceneManager();
	void InitNextScene(int id, DWORD& timeStart);
	void Run();
	void OnKeyUp(int keycode);
	void OnKeyDown(int keycode);
};