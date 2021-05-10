#pragma once

#include <d3dx9.h>
#include "Tileset.h"
#include "TwoDimensionObj.h"
#include "Keyboard.h"
#include "DirectX.h"
#include "Background.h"

#define APP_TITLE L"Mr.Gimmick"

#define KEY_DOWN(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0)
#define KEY_UP(vk_code) ((GetAsyncKeyState(vk_code) * 0x8000) ? 1 : 0)

#define FULLSCREEN 0
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

#define INTRO 0
#define STARTMENU 1 
#define MAP 2 
#define GAMEPLAY 3

class Scene : public TwoDimensionObj
{
protected:
	LPDIRECT3DTEXTURE9 texture;
	LPD3DXSPRITE spriteHandler;
	LPCWSTR sceneFilePath;
	HWND window;
	DirectX directX;
	int nextScene = -1;
public:
	Scene();
	virtual void Run(DWORD time, DWORD& timeStart) = 0;

	int GetNextScene() { return nextScene; };
	void Draw(LPDIRECT3DTEXTURE9 texture, float posx, float posy, float left, float top, float right, float bottom);
	virtual void OnKeyUp(int keycode) = 0;
	virtual void OnKeyDown(int keycode) = 0;
};