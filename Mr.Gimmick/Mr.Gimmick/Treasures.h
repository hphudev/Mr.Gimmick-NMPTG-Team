#pragma once

#include "UsefulObj.h"

#pragma region Definition
#define TREASURES_BACKGROUND_COLOR D3DCOLOR_XRGB(60, 188, 252)

#define SPRITE_TREASURES_PATH L"../../Resource/Image/Treasures.png"
#pragma endregion

class Treasures : public UsefulObj
{
public:
    Treasures();
    Treasures(float x, float y, int gameObjID, int currentFrame = 1, float width = 23, float height = 50,
        int numberOfAnimatedTiles = 1, LPCWSTR fileSpriteName = SPRITE_TREASURES_PATH);
    Treasures& operator = (const Treasures& itemsAndHUD);
    bool Load(D3DXCOLOR transparentColor, DirectXGraphic directXGrphic);
};