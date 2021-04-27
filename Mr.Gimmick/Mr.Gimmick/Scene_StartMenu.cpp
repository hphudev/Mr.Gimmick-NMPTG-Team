#include "Scene_StartMenu.h"

Scene_StartMenu::Scene_StartMenu(HWND window)
{
	this->window = window;
	bool flag = this->directX.InitDirectX(this->window, SCREEN_WIDTH, SCREEN_HEIGHT, FULLSCREEN);

	D3DXIMAGE_INFO info;
	HRESULT result = D3DXGetImageInfoFromFile(L"../../Resource/MenuStart.png", &info);
	if (result != D3D_OK)
	{
		return;
	}
	directX.GetDirectXGraphic().GetGraphicDevice().CreateTexture(L"../../Resource/MenuStart.png", info, D3DCOLOR_XRGB(0, 0, 255), texture);
	directX.GetDirectXGraphic().GetGraphicDevice().CreateSpriteHandler(spriteHandler);
}

void Scene_StartMenu::Run(DWORD time, DWORD& timeStart)
{
	GraphicDevice graphicDevice = this->directX.GetDirectXGraphic().GetGraphicDevice();

	int frame = (GetTickCount() - timeStart) / 500 % 2;
	if (GetTickCount() - timeStart >= 12000)
	{
		nextScene = MAP;
	}
	if (graphicDevice.BeginRendering())
	{
		DirectXGraphic directXGraphic = this->directX.GetDirectXGraphic();
		Draw(texture, SCREEN_WIDTH / 2 - 120, SCREEN_HEIGHT / 2 - 120, 0, 0, 200, 170);
		if (frame == 1)
		{
			if (buttonOnMainMeNu == STARTBUTTON)
			{
				Draw(texture, SCREEN_WIDTH / 2 - 120 + 85, SCREEN_HEIGHT / 2 - 120 + 111, 220, 56.8f, 270, 65);
			}
			if (buttonOnMainMeNu == CONTINUEBUTTON)
			{
				Draw(texture, SCREEN_WIDTH / 2 - 120 + 84, SCREEN_HEIGHT / 2 - 120 + 122, 220, 70, 270, 80);
			}
		}
		Draw(texture, SCREEN_WIDTH / 2 - 120, SCREEN_HEIGHT / 2 - 120 + 140, 240 + -1 * posWidthMainMenu - 30, 0, 440 + -1 * posWidthMainMenu - 30, 30);
		posWidthMainMenu--;
		if (posWidthMainMenu == -329)
		{
			posWidthMainMenu = -30;
		}
		graphicDevice.EndRendering();
	}

	// Thể hiện backbuffer lên màn hình
	graphicDevice.ShowBackbuffer();
}