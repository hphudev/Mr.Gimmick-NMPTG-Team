#include "Game.h"

Game::Game()
{

}

// Khởi tạo game
bool Game::InitGame(HWND window)
{
	this->window = window;
	bool flag = this->directX.InitDirectX(this->window);
	this->yumetaro = Yumetaro(YUMETARO_START_X, YUMETARO_START_Y, YUMETARO_VELOCITY_X,
		YUMETARO_VELOCITY_Y, YUMETARO_SIZE, SPRITE_YUMETARO_PATH);
	this->background = Background(NUMBER_OF_ROWS_LEVEL_1, NUMBER_OF_COLUMNS_LEVEL_1,
		FILE_TILEMAP_PATH_LEVEL_1, NUMBER_OF_TILES_LEVEL_1, L"Level_1", BACKGROUND_COLOR_LEVEL_1);
	
	return flag;
}

bool Game::LoadGame()
{
	if (!yumetaro.Load(YUMETARO_BACKGROUND_COLOR, this->directX.GetDirectXGraphic()))
	{
		return 0;
	}

	return 1;
}

// Vòng lặp game chính
void Game::RunGame(HWND window)
{
	// Đảm bảo Direct3D device đã có
	if (!this->directX.GetDirectXGraphic().GetGraphicDevice().CheckDevice())
	{
		return;
	}

	if (!LoadGame())
	{
		return;
	}

	UpdateGame();
	Render();

	// Kiểm tra phím escape (để kết thúc chương trình)
	if (KEY_DOWN(VK_ESCAPE))
	{
		PostMessage(window, WM_DESTROY, 0, 0);
	}
}

void Game::UpdateGame()
{
	int velocity = 5;

	// Di chuyển bằng bàn phím
	if (KEY_DOWN(VK_LEFT))
	{
		yumetaro.SetVelocity(-velocity, 0);
		yumetaro.Move(SCREEN_WIDTH, SCREEN_HEIGHT);
	}

	if (KEY_DOWN(VK_RIGHT))
	{
		yumetaro.SetVelocity(velocity, 0);
		yumetaro.Move(SCREEN_WIDTH, SCREEN_HEIGHT);
	}

	if (KEY_DOWN(VK_UP))
	{
		yumetaro.SetVelocity(0, -velocity);
		yumetaro.Move(SCREEN_WIDTH, SCREEN_HEIGHT);
	}

	if (KEY_DOWN(VK_DOWN))
	{
		yumetaro.SetVelocity(0, velocity);
		yumetaro.Move(SCREEN_WIDTH, SCREEN_HEIGHT);
	}
}

void Game::Render()
{
	GraphicDevice graphicDevice = this->directX.GetDirectXGraphic().GetGraphicDevice();

	// Bắt đầu render
	if (graphicDevice.BeginRendering())
	{
		DirectXGraphic directXGraphic = this->directX.GetDirectXGraphic();
		this->background.DrawBackground(directXGraphic.GetGraphicDevice().GetBackbuffer(), 
			directXGraphic);
		yumetaro.Draw(2, 0, graphicDevice);

		// Dừng render
		graphicDevice.EndRendering();
	}

	// Thể hiện backbuffer lên màn hình
	graphicDevice.ShowBackbuffer();
}

// Giải phóng bộ nhớ và dọn dẹp trước khi kết thúc game
void Game::EndGame(HWND window)
{
	this->directX.ReleaseDirectX();
}

DirectX Game::GetDirectX()
{
	return this->directX;
}