#include "Game.h"

Game::Game()
{
	this->uselessObjs = NULL;
	this->window = NULL;
	this->enemies = NULL;
	this->numberOfUselessObjs = this->numberOfEnemies = 0;
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

	this->numberOfEnemies = game.numberOfEnemies;
	this->enemies = new Enemies[game.numberOfEnemies];

	for (int i = 0; i < game.numberOfEnemies; i++)
	{
		this->enemies[i] = game.enemies[i];
	}
}

Game::~Game()
{
	delete[] this->uselessObjs;

	delete[] this->enemies;
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

void Game::InitEnemies()
{
	this->numberOfEnemies = NUMBER_OF_ENEMIES;
	this->enemies = new Enemies[this->numberOfEnemies];
	this->enemies[0] = Enemies(16 * 28, 16 * 22);
	this->enemies[1] = Enemies(16 * 30, 16 * 22);
	this->enemies[2] = Enemies(16 * 33, 16 * 21);
	this->enemies[3] = Enemies(16 * 37, 16 * 22);
	this->enemies[4] = Enemies(16 * 41, 16 * 21);
	this->enemies[5] = Enemies(16 * 45, 16 * 22);
	this->enemies[6] = Enemies(16 * 47, 16 * 22);
	this->enemies[7] = Enemies(16 * 49, 16 * 22);
	this->enemies[8] = Enemies(16 * 36, 16 * 31);
	this->enemies[9] = Enemies(16 * 114, 16 * 28);
	this->enemies[10] = Enemies(16 * 114, 16 * 19);
	this->enemies[11] = Enemies(16 * 108, 16 * 7);
	this->enemies[12] = Enemies(16 * 89, 16 * 10);
	this->enemies[13] = Enemies(16 * 85, 16 * 10);
	this->enemies[14] = Enemies(16 * 47, 16 * 40 - 3, 2, 0, 1, 26);
	this->enemies[15] = Enemies(16 * 117, 16 * 31 - 3, 2, 0, 1, 26);
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

	InitEnemies();

	return flag;
}

bool Game::LoadGame()
{
	if (!yumetaro.Load(YUMETARO_BACKGROUND_COLOR, this->directX.GetDirectXGraphic()))
	{
		return 0;
	}

	for (int i = 0; i < this->numberOfEnemies; i++)
	{
		this->enemies[i].Load(ENEMIES_BACKGROUND_COLOR, this->directX.GetDirectXGraphic());
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

	for (int i = 0; i < this->numberOfUselessObjs; i++)
	{
		this->uselessObjs[i]->Synchronize();
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

		for (int i = 0; i < this->numberOfEnemies; i++)
		{
			if (i <= 13)
			{
				this->enemies[i].Draw(1, 0, graphicDevice);
			}
			else
			{
				this->enemies[i].Draw(17, 0, graphicDevice);
			}
		}

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