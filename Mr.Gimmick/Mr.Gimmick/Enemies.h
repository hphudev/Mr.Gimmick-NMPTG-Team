#pragma once

#include "UnplayableObj.h"

#pragma region Definition
#define ENEMIES_BACKGROUND_COLOR D3DCOLOR_XRGB(57, 189, 255)

#define SPRITE_ENEMIES_PATH L"../../Resource/Image/Enemies.png"
#pragma endregion

class Enemies : public UnplayableObj
{
public:
    Enemies();
    Enemies(float x, float y, float vX = 2, float vY = 0, int numberOfAnimatedTiles = 1, 
        float width = 19.4, float height = 19.4, LPCWSTR fileSpriteName = SPRITE_ENEMIES_PATH);
    Enemies& operator = (const Enemies& enemies);
    bool Load(D3DXCOLOR transparentColor, DirectXGraphic directXGrphic);
};