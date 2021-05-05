#pragma once

#include "UnplayableObj.h"

#pragma region Definition
#define BOSSES_BACKGROUND_COLOR D3DCOLOR_XRGB(0, 0, 255)

#define SPRITE_BOSSES_PATH L"../../Resource/Image/Bosses.png"
#pragma endregion

class Bosses : public UnplayableObj
{
public:
    Bosses();
    Bosses(float x, float y, float vX = 2, float vY = 0, int numberOfAnimatedTiles = 1,
        float width = 40, float height = 50, LPCWSTR fileSpriteName = SPRITE_BOSSES_PATH);
    Bosses& operator = (const Bosses& bosses);
    bool Load(D3DXCOLOR transparentColor, DirectXGraphic directXGrphic);
};