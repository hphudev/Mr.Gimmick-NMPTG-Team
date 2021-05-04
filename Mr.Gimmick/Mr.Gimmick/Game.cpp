#include "Game.h"

Game::Game()
{
	this->uselessObjs = NULL;
	this->window = NULL;
	this->numberOfUselessObjs = 0;
}

Game::Game(const Game& game)
{
	this->background = game.background;
	this->directX = game.directX;
	this->window = game.window;
	this->yumetaro = game.yumetaro;
	this->numberOfUselessObjs = game.numberOfUselessObjs;
	this->uselessObjs = new UselessObj*[game.numberOfUselessObjs];

	for (int i = 0; i < game.numberOfUselessObjs; i++)
	{
		this->uselessObjs[i] = game.uselessObjs[i]->Clone();
	}
}

Game::~Game()
{
	delete[] this->uselessObjs;
}

void Game::InitUselessObjs(int key, int* numberOfUselessObjs)
{
	for (int i = numberOfUselessObjs[key]; i < numberOfUselessObjs[key + 1]; i++)
	{
		switch (key)
		{
			case 0:
			{
				this->uselessObjs[i] = new ScrollBar();
				break;
			}
			case 1:
			{
				this->uselessObjs[i] = new Waterfall();
				break;
			}
		}
	}
}

// Khởi tạo game
bool Game::InitGame(HWND window)
{
	this->window = window;
	bool flag = this->directX.InitDirectX(this->window, SCREEN_WIDTH, SCREEN_HEIGHT, FULLSCREEN);

	this->yumetaro = Yumetaro(YUMETARO_START_X, YUMETARO_START_Y, YUMETARO_VELOCITY_X,
		YUMETARO_VELOCITY_Y, 1, YUMETARO_WIDTH, YUMETARO_HEIGHT, SPRITE_YUMETARO_PATH);

	this->background = Background(NUMBER_OF_ROWS_LEVEL_ONE, NUMBER_OF_COLUMNS_LEVEL_ONE,
		FILE_TILEMAP_PATH_LEVEL_ONE, NUMBER_OF_TILES_LEVEL_ONE, L"Level_1", BACKGROUND_COLOR_LEVEL_ONE);

	const int numberOfTypeOfUselessObjs = NUMBER_OF_TYPE_OF_USELESS_OBJS;
	int numberOfUselessObjs[numberOfTypeOfUselessObjs + 1];
	numberOfUselessObjs[0] = 0;
	numberOfUselessObjs[1] = numberOfUselessObjs[0] + NUMBER_OF_SCROLLBARS;
	numberOfUselessObjs[2] = numberOfUselessObjs[1] + NUMBER_OF_WATERFALLS;

	this->numberOfUselessObjs = numberOfUselessObjs[numberOfTypeOfUselessObjs];
	this->uselessObjs = new UselessObj*[this->numberOfUselessObjs];
	
	for (int i = 0; i < numberOfTypeOfUselessObjs; i++)
	{
		InitUselessObjs(i, numberOfUselessObjs);
	}

	return flag;
}

bool Game::LoadGame()
{
	if (!yumetaro.Load(YUMETARO_BACKGROUND_COLOR, this->directX.GetDirectXGraphic()))
	{
		return 0;
	}

	this->background.LoadBackground(this->directX.GetDirectXGraphic());

	this->background.LoadUselessObjs(this->uselessObjs);
	
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
	int velocity = YUMETARO_VELOCITY_X;

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

	this->background.UpdateBackground(this->directX.GetDirectXGraphic());
}

void Game::Render()
{
	Sleep(1000 / FPS);

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