#pragma once
#include "Scene.h"
#include "Yumetaro.h"

#pragma region Level
#pragma region Level_1
#define NUMBER_OF_ROWS_LEVEL_1 30
#define NUMBER_OF_COLUMNS_LEVEL_1 40

#define NUMBER_OF_TILES_LEVEL_1 322

#define BACKGROUND_COLOR_LEVEL_1 D3DCOLOR_XRGB(0, 255, 0)

#define FILE_TILEMAP_PATH_LEVEL_1 L"../../Resource/Tilemap.txt"

#pragma endregion
#pragma endregion

class Scene_Play :
	public Scene
{
	Yumetaro* yumetaro;
	//long start;
	Background background;
public:
	Scene_Play() {};
	Scene_Play(HWND window);
	//Scene_Play(int level);
	~Scene_Play();

	void Run(DWORD time, DWORD& timeStart);
	void Update(DWORD dt);
	void Render();

	void OnKeyUp(int keycode);
	void OnKeyDown(int keycode);
};

