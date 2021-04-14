#include <d3dx9math.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "Yumetaro.h"
#include "DirectX.h"

#pragma region Definition
// Tên của ứng dụng
#define APP_TITLE L"Mr.Gimmick"

// Thiết lập màn hình
#define FULLSCREEN 0		// 0 = windowed, 1 = fullscreen
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

// Lệnh để đọc keyboard
#define KEY_DOWN(vk_code)((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0)
#define KEY_UP(vk_code)((GetAsyncKeyState(vk_code) * 0x8000) ? 1 : 0)
#pragma endregion

class Game
{
private:
	Yumetaro yumetaro;
	long start;
	DirectX directX;
public:
	bool InitGame(HWND window);
	void RunGame(HWND window);
	void EndGame(HWND window);
	DirectX GetDirectX();
};