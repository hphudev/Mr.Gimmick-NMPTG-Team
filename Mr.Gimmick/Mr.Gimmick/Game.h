#pragma once

#include <d3dx9math.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "Yumetaro.h"
#include "DirectX.h"
#include "Background.h"
#include "LevelOne.h"
#include "ScrollBar.h"
#include "Waterfall.h"
#include "Enemies.h"
#include "HazardsAndInteractables.h"
#include "ItemsAndHUD.h"
#include "Bosses.h"
#include "Treasures.h"
#include "PassiveCreatures.h"
#include "Quadtree.h"

#pragma region Definition
#define APP_TITLE L"Mr.Gimmick"

#define KEY_DOWN(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0)
#define KEY_UP(vk_code) ((GetAsyncKeyState(vk_code) * 0x8000) ? 1 : 0)

#define FULLSCREEN 0
#define SCREEN_WIDTH 16 * TILE_SIZE * SCALE
#define SCREEN_HEIGHT 12 * TILE_SIZE * SCALE

#define FPS 30
#pragma endregion

class Game
{
private:
	map<int, GameObj*> gameObjs;
	Quadtree quadtree;
	Yumetaro yumetaro;
	Bosses boss;
	Treasures treasure;
	Enemies* enemies;
	UselessObj** uselessObjs;
	HazardsAndInteractables* hazardsAndInteractables;
	ItemsAndHUD* itemsAndHUD;
	PassiveCreatures* passiveCreatures;
	int numberOfUselessObjs, numberOfEnemies, numberOfHazardsAndInteractables, numberOfItemsAndHUD;
	int numberOfPassiveCreatures;
	DirectX directX;
	HWND window;
	Background background;
public:
	TreeObj* InitTreeObjs();
	Game();
	Game(const Game& game);
	~Game();
	void InitUselessObjs(int key, int* numberOfUselessObjs);
	void InitEnemies();
	void InitHazardsAndInteractables();
	void InitItemsAndHUD();
	void InitPassiveCreatures();
	bool InitGame(HWND window);
	bool LoadGame();
	void RunGame(HWND window);
	void UpdateGame();
	void Render();
	void EndGame(HWND window);
	DirectX GetDirectX();
};