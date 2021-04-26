#pragma once

#include "DirectXGraphic.h"
#include "DirectInput.h"
#include "DirectSound.h"
#include "GameComponent.h"

class DirectX : public GameComponent
{
private:
	DirectXGraphic directXGraphic;
	DirectInput directInput;
	//DirectSound directSound;
public:
	bool InitDirectX(HWND window, int screenWidth, int screenHeight, bool isFullscreen);
	void ReleaseDirectX();
	DirectXGraphic GetDirectXGraphic();
	DirectInput GetDirectInput();
	//DirectSound GetDirectSound();
};