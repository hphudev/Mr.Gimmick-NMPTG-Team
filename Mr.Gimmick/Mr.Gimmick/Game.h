// *
#pragma once

#include <d3dx9math.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "Yumetaro.h"
#include "DirectX.h"

#pragma region Definition
// Tên của ứng dụng
#define APP_TITLE L"Mr.Gimmick"

// *
// Lệnh để đọc keyboard
#define KEY_DOWN(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0)
#define KEY_UP(vk_code) ((GetAsyncKeyState(vk_code) * 0x8000) ? 1 : 0)
#pragma endregion

class Game
{
private:
	Yumetaro yumetaro;
	long start;
	DirectX directX;
	HWND window;
public:
	bool InitGame(HWND window);
	void LoadGame();	// *
	void RunGame(HWND window);
	void UpdateGame();	// *
	void Render();	// *
	void EndGame(HWND window);
	DirectX GetDirectX();
};