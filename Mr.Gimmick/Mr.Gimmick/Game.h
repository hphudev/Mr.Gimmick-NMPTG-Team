#pragma once

#include <d3dx9math.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "Yumetaro.h"
#include "DirectX.h"
#include "Background.h"
#include "LevelOne.h"
#include "ScrollBar.h"

#pragma region Definition
#define APP_TITLE L"Mr.Gimmick"

#define KEY_DOWN(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0)
#define KEY_UP(vk_code) ((GetAsyncKeyState(vk_code) * 0x8000) ? 1 : 0)

#define FULLSCREEN 0
#define SCREEN_WIDTH 1920//16 * TILE_SIZE * SCALE
#define SCREEN_HEIGHT 1080//12 * TILE_SIZE * SCALE

#define FPS 60
#pragma endregion

class Game
{
private:
	Yumetaro yumetaro;
	UselessObj** uselessObjs;
	DirectX directX;
	HWND window;
	Background background;
public:
	Game();
	bool InitGame(HWND window);
	bool LoadGame();
	void RunGame(HWND window);
	void UpdateGame();
	void Render();
	void EndGame(HWND window);
	DirectX GetDirectX();
};