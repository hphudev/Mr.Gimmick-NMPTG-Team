#pragma once

#include <d3dx9math.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "Yumetaro.h"
#include "DirectX.h"
#include "Background.h"

#pragma region Definition
#define APP_TITLE L"Mr.Gimmick"

#define KEY_DOWN(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0)
#define KEY_UP(vk_code) ((GetAsyncKeyState(vk_code) * 0x8000) ? 1 : 0)

#define FULLSCREEN 0
#define SCREEN_WIDTH 1920//16 * TILE_SIZE * SCALE
#define SCREEN_HEIGHT 1080//12 * TILE_SIZE * SCALE

#define FPS 60
#pragma region Level
#pragma region Level_1
#define NUMBER_OF_ROWS_LEVEL_1 26
#define NUMBER_OF_COLUMNS_LEVEL_1 130

#define NUMBER_OF_TILES_LEVEL_1 322

#define BACKGROUND_COLOR_LEVEL_1 D3DCOLOR_XRGB(255, 255, 0)

#define FILE_TILEMAP_PATH_LEVEL_1 L"C:/Users/DELL/Documents/TvT/UIT/SE102.L21/Project/Github/New folder/Mr.Gimmick-NMPTG-Team/Resource/Tilemap.txt"
#pragma endregion
#pragma endregion
#pragma endregion

class Game
{
private:
	Yumetaro yumetaro;
	long start;
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