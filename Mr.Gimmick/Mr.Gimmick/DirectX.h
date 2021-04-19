#pragma once

#include "DirectXGraphic.h"
#include "DirectInput.h"
#include "DirectSound.h"
#include "GameComponent.h"

#pragma region Definition
// Thiết lập màn hình
#define FULLSCREEN 0		// 0 = windowed, 1 = fullscreen
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
#pragma endregion

class DirectX : public GameComponent
{
private:
	DirectXGraphic directXGraphic;
	DirectInput directInput;
	//DirectSound directSound;
public:
	bool InitDirectX(HWND window);
	void ReleaseDirectX();
	DirectXGraphic GetDirectXGraphic();
	DirectInput GetDirectInput();
	//DirectSound GetDirectSound();
};