#include "SceneIntro.h"

SceneIntro::SceneIntro()
{

}
SceneIntro::~SceneIntro()
{

}
SceneIntro::SceneIntro(HWND window)
{
	this->window = window;
	bool flag = this->directX.InitDirectX(this->window, SCREEN_WIDTH, SCREEN_HEIGHT, FULLSCREEN);

	D3DXIMAGE_INFO info;
	HRESULT result = D3DXGetImageInfoFromFile(L"../../Resource/intro.png", &info);
	if (result != D3D_OK)
	{
		return;
	}
	directX.GetDirectXGraphic().GetGraphicDevice().CreateTexture(L"../../Resource/intro.png", info, D3DCOLOR_XRGB(0, 0, 255), texture);

	HRESULT r = 	directX.GetDirectXGraphic().GetGraphicDevice().CreateSpriteHandler(spriteHandler);
	if (r != D3D_OK)
	{
		OutputDebugString(L"asdfadsf");
	}
}
void SceneIntro::Run(DWORD time, DWORD& timeStart)
{
	GraphicDevice graphicDevice = this->directX.GetDirectXGraphic().GetGraphicDevice();

	int frame = (GetTickCount() - timeStart) / 3000 % 58;
	if (frame == 57)
	{
		nextScene = STARTMENU;
	}
	else
	{
		if (graphicDevice.BeginRendering())
		{
			DirectXGraphic directXGraphic = this->directX.GetDirectXGraphic();

			Draw(texture, SCREEN_WIDTH / 2 - 70, SCREEN_HEIGHT / 2 - 60, 0, frame * 80 + 5, 120, frame * 80 + 80 - 5);
			if (12 <= frame && frame <= 13)
			{
				timeStart -= 1500;
			}
			if (15 <= frame && frame <= 35)
			{
				timeStart -= 3000;
			}
			if (39 <= frame && frame <= 57)
			{
				timeStart -= 3000;
			}
			graphicDevice.EndRendering();
		}

		// Thể hiện backbuffer lên màn hình
		graphicDevice.ShowBackbuffer();
	}
}