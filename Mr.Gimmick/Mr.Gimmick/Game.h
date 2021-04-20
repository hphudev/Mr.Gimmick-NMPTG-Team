#pragma once

#include <d3dx9math.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "Yumetaro.h"
#include "DirectX.h"
#include "Background.h"

#pragma region Definition
#pragma region Game
// Tên của ứng dụng
#define APP_TITLE L"Mr.Gimmick"

// Lệnh để đọc keyboard
#define KEY_DOWN(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0)
#define KEY_UP(vk_code) ((GetAsyncKeyState(vk_code) * 0x8000) ? 1 : 0)
#pragma endregion
#pragma region Yumetaro
#define YUMETARO_START_X 16 * 4
#define YUMETARO_START_Y 16 * 21 - 5

#define YUMETARO_VELOCITY_X 1
#define YUMETARO_VELOCITY_Y 0

#define YUMETARO_SIZE 21

#define YUMETARO_BACKGROUND_COLOR D3DCOLOR_XRGB(0, 0, 255)

#define SPRITE_YUMETARO_PATH L"C:/Users/DELL/Documents/TvT/UIT/SE102.L21/Project/Resource/Yumetaro.png"
#pragma endregion
#pragma region Level
#pragma region Level_1
#define NUMBER_OF_ROWS_LEVEL_1 30
#define NUMBER_OF_COLUMNS_LEVEL_1 40

#define NUMBER_OF_TILES_LEVEL_1 322

#define BACKGROUND_COLOR_LEVEL_1 D3DCOLOR_XRGB(0, 255, 0)

#define FILE_TILEMAP_PATH_LEVEL_1 L"C:/Users/DELL/Documents/TvT/UIT/SE102.L21/Project/Resource/Tilemap.txt"
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