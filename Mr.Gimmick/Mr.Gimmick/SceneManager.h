#pragma once

#include "GameComponent.h"
#include "WindowHandler.h"
#include "Scene.h"
#include "ScenePlay.h"
#include "SceneIntro.h"
#include "SceneStartMenu.h"
#include "SceneMap.h"

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