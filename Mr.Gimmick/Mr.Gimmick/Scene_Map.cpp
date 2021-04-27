#include "Scene_Map.h"

Scene_Map::Scene_Map(HWND window)
{
	this->window = window;
	bool flag = this->directX.InitDirectX(this->window, SCREEN_WIDTH, SCREEN_HEIGHT, FULLSCREEN);

	D3DXIMAGE_INFO info;
	HRESULT result = D3DXGetImageInfoFromFile(L"../../Resource/Map.png", &info);
	if (result != D3D_OK)
	{
		return;
	}
	directX.GetDirectXGraphic().GetGraphicDevice().CreateTexture(L"../../Resource/Map.png", info, D3DCOLOR_XRGB(0, 0, 255), texture);
	directX.GetDirectXGraphic().GetGraphicDevice().CreateSpriteHandler(spriteHandler);

	for (int i = 0; i < COUNT_CLOUD; i++)
	{
		arrCloud[i].posHeight = rand() % 150 + 30;
		arrCloud[i].posWidth = rand() % 180;
		arrCloud[i].isBigCloud = rand() % 2;
		arrCloud[i].isBefore = rand() % 2;
		arrCloud[i].speed = rand() % 2 + 1 + (rand() % 2 + 1) / min(0.1f, (rand() % 5));
	}
}

void Scene_Map::Run(DWORD time, DWORD& timeStart)
{
	GraphicDevice graphicDevice = this->directX.GetDirectXGraphic().GetGraphicDevice();

	int frame = (GetTickCount() - timeStart) / 200 % 4;
	if (GetTickCount() - timeStart >= 12000)
	{
		nextScene = GAMEPLAY;
	}
	if (graphicDevice.BeginRendering())
	{
		DirectXGraphic directXGraphic = this->directX.GetDirectXGraphic();
		for (int i = 0; i < COUNT_CLOUD; i++)
		{
			arrCloud[i].posWidth -= arrCloud[i].speed;
			if (arrCloud[i].posWidth <= 0 - 200)
			{
				arrCloud[i].posHeight = rand() % 150 + 30;
				arrCloud[i].posWidth = SCREEN_WIDTH + 1;
				arrCloud[i].isBigCloud = rand() % 2;
				arrCloud[i].isBefore = rand() % 2;
				arrCloud[i].speed = rand() % 2 + 0.5f + (rand() % 2 + 1) / (rand() % 5 + 1);
			}
		}

		Draw(texture, 0, 0, 310, 0, 310 + SCREEN_WIDTH, SCREEN_HEIGHT);

		for (int i = 0; i < COUNT_CLOUD; i++)
		{
			if (arrCloud[i].isBefore)
				if (arrCloud[i].isBigCloud)
					Draw(texture, SCREEN_WIDTH / 2 - 120 + arrCloud[i].posWidth, SCREEN_HEIGHT / 2 - 120 + arrCloud[i].posHeight, 220, 0, 260, 100);
				else
					Draw(texture, SCREEN_WIDTH / 2 - 120 + arrCloud[i].posWidth, SCREEN_HEIGHT / 2 - 120 + arrCloud[i].posHeight, 260, 0, 290, 100);
		}

		Draw(texture, SCREEN_WIDTH / 2 - 120, SCREEN_HEIGHT / 2 - 120, 0, frame * 186, 200, frame * 186 + 186);

		for (int i = 0; i < COUNT_CLOUD; i++)
		{
			if (!arrCloud[i].isBefore)
				if (arrCloud[i].isBigCloud)
					Draw(texture, SCREEN_WIDTH / 2 - 120 + arrCloud[i].posWidth, SCREEN_HEIGHT / 2 - 120 + arrCloud[i].posHeight, 220, 0, 260, 100);
				else
					Draw(texture, SCREEN_WIDTH / 2 - 120 + arrCloud[i].posWidth, SCREEN_HEIGHT / 2 - 120 + arrCloud[i].posHeight, 260, 0, 290, 100);
		}
		graphicDevice.EndRendering();
	}

	// Thể hiện backbuffer lên màn hình
	graphicDevice.ShowBackbuffer();
}