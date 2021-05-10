#include "Game.h"

Game::Game()
{
	this->uselessObjs = NULL;
	this->window = NULL;
	this->enemies = NULL;
	this->hazardsAndInteractables = NULL;
	this->itemsAndHUD = NULL;
	this->passiveCreatures = NULL;
	this->numberOfUselessObjs = this->numberOfEnemies = this->numberOfHazardsAndInteractables =
		this->numberOfItemsAndHUD = this->numberOfPassiveCreatures = this->indexOfScene = 0;
}

Game::Game(const Game& game)
{
	this->scene = game.scene;
	this->indexOfScene = game.indexOfScene;
	this->camera = game.camera;
	this->quadtree = game.quadtree;
	this->background = game.background;
	this->directX = game.directX;
	this->window = game.window;
	this->yumetaro = game.yumetaro;
	this->boss = game.boss;
	this->treasure = game.treasure;
	this->gameObjs = game.gameObjs;

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

	this->numberOfHazardsAndInteractables = game.numberOfHazardsAndInteractables;
	this->hazardsAndInteractables = new HazardsAndInteractables[game.numberOfHazardsAndInteractables];

	for (int i = 0; i < game.numberOfHazardsAndInteractables; i++)
	{
		this->hazardsAndInteractables[i] = game.hazardsAndInteractables[i];
	}

	this->numberOfItemsAndHUD = game.numberOfItemsAndHUD;
	this->itemsAndHUD = new ItemsAndHUD[game.numberOfItemsAndHUD];

	for (int i = 0; i < game.numberOfItemsAndHUD; i++)
	{
		this->itemsAndHUD[i] = game.itemsAndHUD[i];
	}

	this->numberOfPassiveCreatures = game.numberOfPassiveCreatures;
	this->passiveCreatures = new PassiveCreatures[game.numberOfPassiveCreatures];

	for (int i = 0; i < game.numberOfPassiveCreatures; i++)
	{
		this->passiveCreatures[i] = game.passiveCreatures[i];
	}
}

Game::~Game()
{
	delete[] this->uselessObjs;

	delete[] this->enemies;

	delete[] this->hazardsAndInteractables;

	delete[] this->itemsAndHUD;

	delete[] this->passiveCreatures;
}

TreeObj* Game::InitTreeObjs()
{
	TreeObj* treeObjs = new TreeObj[NUMBER_OF_GAME_OBJS];
	treeObjs[0] = TreeObj(&this->boss);
	treeObjs[1] = TreeObj(&this->treasure);
	int index = 2;

	for (int i = 0; i < this->numberOfEnemies; i++)
	{
		treeObjs[index + i] = TreeObj(&this->enemies[i]);
	}
	
	index += this->numberOfEnemies;

	for (int i = 0; i < this->numberOfUselessObjs; i++)
	{
		treeObjs[index + i] = TreeObj(this->uselessObjs[i]);
	}

	index += this->numberOfUselessObjs;

	for (int i = 0; i < this->numberOfHazardsAndInteractables; i++)
	{
		treeObjs[index + i] = TreeObj(&this->hazardsAndInteractables[i]);
	}

	index += this->numberOfHazardsAndInteractables;

	for (int i = 0; i < this->numberOfPassiveCreatures; i++)
	{
		treeObjs[index + i] = TreeObj(&this->passiveCreatures[i]);
	}

	index += numberOfPassiveCreatures;

	for (int i = 0; i < this->numberOfItemsAndHUD; i++)
	{
		treeObjs[index + i] = TreeObj(&this->itemsAndHUD[i]);
	}

	return treeObjs;
}

void Game::InitUselessObjs(int key, int* numberOfUselessObjs)
{
	for (int i = numberOfUselessObjs[key]; i < numberOfUselessObjs[key + 1]; i++)
	{
		switch (key)
		{
			case 0:
			{
				this->uselessObjs[i] = new ScrollBar(288, 288, 1, 20 + i - numberOfUselessObjs[key]);
				break;
			}
			case 1:
			{
				this->uselessObjs[i] = new Waterfall(1056, 16, 1, 24);
				break;
			}
		}

		this->gameObjs.insert(pair<int, GameObj*>(this->uselessObjs[i]->GetID(), this->uselessObjs[i]));
	}
}

void Game::InitEnemies()
{
	this->numberOfEnemies = NUMBER_OF_ENEMIES;
	this->enemies = new Enemies[this->numberOfEnemies];
	this->enemies[0] = Enemies(16 * 28, 16 * 22, 4);
	this->enemies[1] = Enemies(16 * 30, 16 * 22, 5);
	this->enemies[2] = Enemies(16 * 33, 16 * 21, 6);
	this->enemies[3] = Enemies(16 * 37, 16 * 22, 7);
	this->enemies[4] = Enemies(16 * 41, 16 * 21, 8);
	this->enemies[5] = Enemies(16 * 45, 16 * 22, 9);
	this->enemies[6] = Enemies(16 * 47, 16 * 22, 10);
	this->enemies[7] = Enemies(16 * 49, 16 * 22, 11);
	this->enemies[8] = Enemies(16 * 36, 16 * 31, 12);
	this->enemies[9] = Enemies(16 * 114, 16 * 28, 13);
	this->enemies[10] = Enemies(16 * 114, 16 * 19, 14);
	this->enemies[11] = Enemies(16 * 108, 16 * 7, 15);
	this->enemies[12] = Enemies(16 * 89, 16 * 10, 16);
	this->enemies[13] = Enemies(16 * 85, 16 * 10, 17);
	this->enemies[14] = Enemies(16 * 47, 16 * 40 - 3, 18, 2, 0, 1, 26);
	this->enemies[15] = Enemies(16 * 117, 16 * 31 - 3, 19, 2, 0, 1, 26);

	for (int i = 0; i < this->numberOfEnemies; i++)
	{
		this->gameObjs.insert(pair<int, GameObj*>(this->enemies[i].GetID(), &this->enemies[i]));
	}
}

void Game::InitHazardsAndInteractables()
{
	this->numberOfHazardsAndInteractables = NUMBER_OF_HAZARDS_AND_INTERACTABLES;
	this->hazardsAndInteractables = new HazardsAndInteractables[this->numberOfHazardsAndInteractables];

	for (int i = 0; i < 2; i++)
	{
		this->hazardsAndInteractables[i] = HazardsAndInteractables(16 * (55 - i * 3), 16 * 27, 25 + i);
	}

	for (int i = 2; i < 6; i++)
	{
		this->hazardsAndInteractables[i] = HazardsAndInteractables(16 * (53 + (i - 2) * 2), 16 * 39, 25 + 
			i);
	}

	for (int i = 6; i < 8; i++)
	{
		this->hazardsAndInteractables[i] = HazardsAndInteractables(16 * (64 + (i - 6) * 2), 16 * 39, 25 + 
			i);
	}

	this->hazardsAndInteractables[8] = HazardsAndInteractables(16 * 36, 16 * 28 - 2, 33, 6);
	this->hazardsAndInteractables[9] = HazardsAndInteractables(16 * 74, 16 * 42 - 2, 34, 6);
	this->hazardsAndInteractables[10] = HazardsAndInteractables(16 * 115 + 8, 16 * 41 + 1, 35 , 1, 53, 77);

	for (int i = 0; i < this->numberOfHazardsAndInteractables; i++)
	{
		this->gameObjs.insert(pair<int, GameObj*>(this->hazardsAndInteractables[i].GetID(), 
			&this->hazardsAndInteractables[i]));
	}
}

void Game::InitItemsAndHUD()
{
	this->numberOfItemsAndHUD = NUMBER_OF_ITEMS_AND_HUD;
	this->itemsAndHUD = new ItemsAndHUD[this->numberOfItemsAndHUD];
	this->itemsAndHUD[0] = ItemsAndHUD(16 * 27, 16 * 19, 42, 2);
	this->itemsAndHUD[1] = ItemsAndHUD(16 * 34, 16 * 43, 43, 3);
	this->itemsAndHUD[2] = ItemsAndHUD(16 * 126, 16 * 22, 44, 2);
	this->itemsAndHUD[3] = ItemsAndHUD(16 * 127 - 6, 16 * 4 - 3, 45, 4);

	for (int i = 0; i < this->numberOfItemsAndHUD; i++)
	{
		this->gameObjs.insert(pair<int, GameObj*>(this->itemsAndHUD[i].GetID(), &this->itemsAndHUD[i]));
	}
}

void Game::InitPassiveCreatures()
{
	this->numberOfPassiveCreatures = NUMBER_OF_PASSIVE_CREATURES;
	this->passiveCreatures = new PassiveCreatures[this->numberOfPassiveCreatures];
	this->passiveCreatures[0] = PassiveCreatures(16 * 110, 16 * 41, 36);
	this->passiveCreatures[1] = PassiveCreatures(16 * 106, 16 * 41, 37);
	this->passiveCreatures[2] = PassiveCreatures(16 * 102, 16 * 48 - 8, 38);
	this->passiveCreatures[3] = PassiveCreatures(16 * 98, 16 * 47, 39);
	this->passiveCreatures[4] = PassiveCreatures(16 * 94, 16 * 42, 40);
	this->passiveCreatures[5] = PassiveCreatures(16 * 90, 16 * 39, 41);

	for (int i = 0; i < this->numberOfPassiveCreatures; i++)
	{
		this->gameObjs.insert(pair<int, GameObj*>(this->passiveCreatures[i].GetID(), 
			&this->passiveCreatures[i]));
	}
}

// Khởi tạo game
bool Game::InitGame(HWND window)
{
	this->camera = Camera(TILE_SIZE, TILE_SIZE * 13, Dimension(SCREEN_WIDTH / SCALE, SCREEN_HEIGHT / 
		SCALE));
	this->scene = TwoDimensionObj(16, 16 * 13);
	this->scene.SetDimension(Dimension(16 * 64, 16 * 13));

	this->window = window;
	bool flag = this->directX.InitDirectX(this->window, SCREEN_WIDTH, SCREEN_HEIGHT, FULLSCREEN);

	this->yumetaro = Yumetaro(YUMETARO_START_X, YUMETARO_START_Y, YUMETARO_VELOCITY_X,
		YUMETARO_VELOCITY_Y, 1, YUMETARO_WIDTH, YUMETARO_HEIGHT, SPRITE_YUMETARO_PATH, 1);

	this->background = Background(NUMBER_OF_ROWS_LEVEL_ONE, NUMBER_OF_COLUMNS_LEVEL_ONE,
		FILE_TILEMAP_PATH_LEVEL_ONE, NUMBER_OF_TILES_LEVEL_ONE, L"Level_1", BACKGROUND_COLOR_LEVEL_ONE);

	this->boss = Bosses(16 * 70 - 4, 16 * 6, 2);

	this->treasure = Treasures(16 * 5 + 3, 16 * 5 + 3, 3);

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
	InitHazardsAndInteractables();
	InitItemsAndHUD();
	InitPassiveCreatures();

	this->gameObjs.insert(pair<int, GameObj*>(this->yumetaro.GetID(), &this->yumetaro));
	this->gameObjs.insert(pair<int, GameObj*>(this->boss.GetID(), &this->boss));
	this->gameObjs.insert(pair<int, GameObj*>(this->treasure.GetID(), &this->treasure));

	map<int, QuadtreeNode*> quadtreeNodes = this->quadtree.InitQuadtreeNodeFromFile(this->gameObjs);
	this->quadtree.LinkQuadtreeNode(quadtreeNodes);

	return flag;
}

bool Game::LoadGame()
{
	if (!this->yumetaro.Load(YUMETARO_BACKGROUND_COLOR, this->directX.GetDirectXGraphic()))
	{
		return 0;
	}

	for (int i = 0; i < this->numberOfEnemies; i++)
	{
		this->enemies[i].Load(ENEMIES_BACKGROUND_COLOR, this->directX.GetDirectXGraphic());
	}

	for (int i = 0; i < this->numberOfHazardsAndInteractables; i++)
	{
		this->hazardsAndInteractables[i].Load(HAZARDS_AND_INTERACTABLES_BACKGROUND_COLOR,
			this->directX.GetDirectXGraphic());
	}

	for (int i = 0; i < this->numberOfItemsAndHUD; i++)
	{
		this->itemsAndHUD[i].Load(ITEMS_AND_HUD_BACKGROUND_COLOR, this->directX.GetDirectXGraphic());
	}

	for (int i = 0; i < this->numberOfPassiveCreatures; i++)
	{
		this->passiveCreatures[i].Load(PASSIVE_CREATURES_BACKGROUND_COLOR,
			this->directX.GetDirectXGraphic());
	}

	this->background.LoadBackground(this->directX.GetDirectXGraphic());

	this->boss.Load(BOSSES_BACKGROUND_COLOR, this->directX.GetDirectXGraphic());

	this->treasure.Load(TREASURES_BACKGROUND_COLOR, this->directX.GetDirectXGraphic());

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
	int velocity = YUMETARO_VELOCITY_X, tileSize = TILE_SIZE;
	
	if (KEY_DOWN(0x56))
	{
		this->indexOfScene++;
		int tileSize = TILE_SIZE;
		int sceneHeight = tileSize * 12;

		switch (this->indexOfScene)
		{
			case 1:
			{
				this->scene.IncreaseSecondValueOfPoint(-sceneHeight);
				this->camera.SetPoint(tileSize * 49, tileSize);
				this->yumetaro.SetPoint(tileSize * 57, 9 * tileSize - 4);
				break;
			}
			case 2:
			{
				this->scene.IncreaseSecondValueOfPoint(sceneHeight);
				this->camera.SetPoint(tileSize * 49, tileSize + sceneHeight);
				this->yumetaro.SetPoint(tileSize * 56, sceneHeight + 6 * tileSize - 4);
				break;
			}
			case 3:
			{
				this->scene.IncreaseFirstValueOfPoint(tileSize * 32);
				this->scene.IncreaseSecondValueOfPoint(sceneHeight);
				this->scene.SetFirstValueOfDimension(tileSize * 32);
				this->camera.SetPoint(tileSize * 49, sceneHeight * 2 + tileSize);
				this->yumetaro.SetPoint(tileSize * 57, sceneHeight * 2 + tileSize * 8 - 4);
				break;
			}
			case 4:
			{
				this->scene.IncreaseSecondValueOfPoint(sceneHeight);
				this->scene.SetFirstValueOfDimension(tileSize * 49);
				this->camera.SetPoint(tileSize * 33, sceneHeight * 3 + tileSize);
				this->yumetaro.SetPoint(tileSize * 37, sceneHeight * 3 + tileSize * 10 - 4);
				break;
			}
			case 5:
			{
				this->scene.IncreaseFirstValueOfPoint(tileSize * 48);
				this->scene.SetFirstValueOfDimension(tileSize * 32);
				this->camera.SetFirstValueOfPoint(tileSize * 81);
				this->yumetaro.SetFirstValueOfPoint(tileSize * 84);
				this->yumetaro.IncreaseSecondValueOfPoint(-tileSize * 2);
				break;
			}
			case 6:
			{
				this->scene.IncreaseFirstValueOfPoint(tileSize * 32);
				this->scene.SetFirstValueOfDimension(tileSize * 16);
				this->camera.SetFirstValueOfPoint(tileSize * 113);
				this->yumetaro.SetFirstValueOfPoint(tileSize * 116);
				break;
			}
			case 7:
			{
				this->scene.IncreaseSecondValueOfPoint(-sceneHeight);
				this->camera.IncreaseSecondValueOfPoint(-sceneHeight);
				this->yumetaro.IncreaseSecondValueOfPoint(-sceneHeight);
				break;
			}
			case 8:
			{
				this->scene.IncreaseSecondValueOfPoint(-sceneHeight);
				this->camera.IncreaseSecondValueOfPoint(-sceneHeight);
				this->yumetaro.IncreaseSecondValueOfPoint(-sceneHeight);
				break;
			}
			case 9:
			{
				this->scene.IncreaseValueOfPoint(-tileSize * 32, -sceneHeight);
				this->camera.IncreaseSecondValueOfPoint(-sceneHeight);
				this->yumetaro.IncreaseValueOfPoint(tileSize * 4, -sceneHeight);
				this->scene.SetFirstValueOfDimension(tileSize * 48);
				break;
			}
			case 10:
			{
				this->scene.IncreaseFirstValueOfPoint(-tileSize * 16);
				this->camera.SetPoint(tileSize * 65, tileSize);
				this->yumetaro.SetPoint(tileSize * 70, tileSize * 8 - 4);
				this->scene.SetFirstValueOfDimension(tileSize * 16);
				break;
			}
		}
	}

	// Di chuyển bằng bàn phím
	if (KEY_DOWN(VK_LEFT))
	{
		this->yumetaro.SetVelocity(-velocity, 0);
		this->yumetaro.Move(SCENE_MAX_WIDTH, SCREEN_HEIGHT);
		this->camera.Update(this->yumetaro, this->scene, tileSize);
		this->yumetaro.Animate();
	}

	if (KEY_DOWN(VK_RIGHT))
	{
		this->yumetaro.SetVelocity(velocity, 0);
		this->yumetaro.Move(SCENE_MAX_WIDTH, SCREEN_HEIGHT);
		this->yumetaro.Animate();
		this->camera.Update(this->yumetaro, this->scene, tileSize);
	}

	if (KEY_DOWN(VK_UP))
	{
		if (camera.GetPoint().GetFirstValue() == SCENE_MIN_WIDTH ||
			camera.GetPoint().GetFirstValue() == SCENE_MAX_WIDTH)
		{
			this->yumetaro.SetVelocity(0, -velocity);
			this->yumetaro.Move(SCENE_MAX_WIDTH, SCREEN_HEIGHT);
		}

		this->yumetaro.Animate();
		this->camera.Update(this->yumetaro, this->scene, tileSize);
	}

	if (KEY_DOWN(VK_DOWN))
	{
		if (camera.GetPoint().GetFirstValue() == SCENE_MIN_WIDTH ||
			camera.GetPoint().GetFirstValue() == SCENE_MAX_WIDTH)
		{
			this->yumetaro.SetVelocity(0, velocity);
			this->yumetaro.Move(SCENE_MAX_WIDTH, SCREEN_HEIGHT);
		}

		this->yumetaro.Animate();
		this->camera.Update(this->yumetaro, this->scene, tileSize);
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
	this->quadtree.ListObjInCamera(this->camera, this->quadtree.GetRoot());
	map<int, GameObj*> gameObjsInCamera = this->quadtree.GetGameObjsInCamera();

	// Bắt đầu render
	if (graphicDevice.BeginRendering())
	{
		DirectXGraphic directXGraphic = this->directX.GetDirectXGraphic();
		this->background.DrawBackground(directXGraphic.GetGraphicDevice().GetBackbuffer(), 
			directXGraphic, this->camera);

		Point cameraPoint = this->camera.GetPoint();
		this->treasure.Draw(1, 0, graphicDevice, cameraPoint);
		this->yumetaro.Draw(2, 0, graphicDevice, cameraPoint);

		for (int i = 0; i < this->numberOfEnemies; i++)
		{
			if (i <= 13)
			{
				this->enemies[i].Draw(1, 0, graphicDevice, cameraPoint);
			}
			else
			{
				this->enemies[i].Draw(17, 0, graphicDevice, cameraPoint);
			}
		}

		for (int i = 0; i < this->numberOfHazardsAndInteractables - 1; i++)
		{
			this->hazardsAndInteractables[i].Draw(1, 0, graphicDevice, cameraPoint);
		}

		this->hazardsAndInteractables[this->numberOfHazardsAndInteractables - 1].Draw(3, 0, 
			graphicDevice, cameraPoint);

		for (int i = 0; i < this->numberOfItemsAndHUD; i++)
		{
			this->itemsAndHUD[i].Draw(1, 0, graphicDevice, cameraPoint);
		}

		for (int i = 0; i < this->numberOfPassiveCreatures; i++)
		{
			if (i == 0)
			{
				this->passiveCreatures[i].Draw(1, 0, graphicDevice, cameraPoint);
			}
			else if (i < 3)
			{
				this->passiveCreatures[i].Draw(2, 0, graphicDevice, cameraPoint);
			}
			else
			{
				this->passiveCreatures[i].Draw(3, 0, graphicDevice, cameraPoint);
			}
		}

		this->boss.Draw(3, 0, graphicDevice, cameraPoint);

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