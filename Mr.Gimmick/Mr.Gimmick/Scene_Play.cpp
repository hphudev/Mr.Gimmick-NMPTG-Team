#include "Scene_Play.h"

Scene_Play::~Scene_Play() {}

Scene_Play::Scene_Play(HWND window)
{
	this->window = window;
	bool flag = this->directX.InitDirectX(this->window, SCREEN_WIDTH, SCREEN_HEIGHT, FULLSCREEN);

	this->yumetaro =new  Yumetaro(YUMETARO_START_X, YUMETARO_START_Y, YUMETARO_VELOCITY_X,
		YUMETARO_VELOCITY_Y, YUMETARO_WIDTH, YUMETARO_HEIGHT, SPRITE_YUMETARO_PATH);

	this->yumetaro->Load(YUMETARO_BACKGROUND_COLOR, this->directX.GetDirectXGraphic());
	this->background = Background(NUMBER_OF_ROWS_LEVEL_1, NUMBER_OF_COLUMNS_LEVEL_1,
		FILE_TILEMAP_PATH_LEVEL_1, NUMBER_OF_TILES_LEVEL_1, L"Level_1", BACKGROUND_COLOR_LEVEL_1);

	this->background.LoadBackground(this->directX.GetDirectXGraphic());
}
void Scene_Play::Run(DWORD time, DWORD& timeStart)
{
	Update(time);
	Render();
}
void Scene_Play::Update(DWORD time)
{
	int velocity = 2;

	// Di chuyển bằng bàn phím
	if (KEY_DOWN(VK_LEFT))
	{
		yumetaro->SetVelocity(-velocity, 0);
		yumetaro->Move(SCREEN_WIDTH, SCREEN_HEIGHT);
	}

	if (KEY_DOWN(VK_RIGHT))
	{
		yumetaro->SetVelocity(velocity, 0);
		yumetaro->Move(SCREEN_WIDTH, SCREEN_HEIGHT);
	}

	if (KEY_DOWN(VK_UP))
	{
		yumetaro->SetVelocity(0, -velocity);
		yumetaro->Move(SCREEN_WIDTH, SCREEN_HEIGHT);
	}

	if (KEY_DOWN(VK_DOWN))
	{
		yumetaro->SetVelocity(0, velocity);
		yumetaro->Move(SCREEN_WIDTH, SCREEN_HEIGHT);
	}
}
void Scene_Play::Render()
{
	GraphicDevice graphicDevice = this->directX.GetDirectXGraphic().GetGraphicDevice();

	// Bắt đầu render
	if (graphicDevice.BeginRendering())
	{
		DirectXGraphic directXGraphic = this->directX.GetDirectXGraphic();
		this->background.DrawBackground(directXGraphic.GetGraphicDevice().GetBackbuffer(), directXGraphic);
		yumetaro->Draw(2, 0, graphicDevice);

		// Dừng render
		graphicDevice.EndRendering();
	}

	// Thể hiện backbuffer lên màn hình
	graphicDevice.ShowBackbuffer();
}
void Scene_Play::OnKeyUp(int keycode)
{
//	yumetaro->OnKeyUp(keycode);
}
void Scene_Play::OnKeyDown(int keycode)
{
//	yumetaro->OnKeyDown(keycode);
}