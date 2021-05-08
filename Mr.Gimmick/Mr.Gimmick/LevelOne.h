#pragma once

#include "Level.h"

#pragma region Definition
#define FILE_QUADTREE_PATH_LEVEL_ONE "../../Resource/Quadtree.txt"

#define MAP_LEVEL_ONE_WIDTH 2080
#define MAP_LEVEL_ONE_HEIGHT 800

#define NUMBER_OF_ROWS_LEVEL_ONE 50
#define NUMBER_OF_COLUMNS_LEVEL_ONE 130

#define NUMBER_OF_TILES_LEVEL_ONE 322

#define NUMBER_OF_GAME_OBJS 44

#define NUMBER_OF_TYPE_OF_USELESS_OBJS 2
#define NUMBER_OF_SCROLLBARS 4
#define NUMBER_OF_WATERFALLS 1

#define NUMBER_OF_ENEMIES 16

#define NUMBER_OF_HAZARDS_AND_INTERACTABLES 11

#define NUMBER_OF_ITEMS_AND_HUD 4

#define NUMBER_OF_PASSIVE_CREATURES 6

#define BACKGROUND_COLOR_LEVEL_ONE D3DCOLOR_XRGB(255, 255, 0)

#define FILE_TILEMAP_PATH_LEVEL_ONE L"../../Resource/Map/Level_1/Tilemap.txt"
#pragma endregion

class LevelOne : public Level
{

};