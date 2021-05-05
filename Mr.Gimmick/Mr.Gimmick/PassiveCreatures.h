#pragma once

#include "UnplayableObj.h"

#pragma region Definition
#define PASSIVE_CREATURES_BACKGROUND_COLOR D3DCOLOR_XRGB(60, 188, 252)

#define SPRITE_PASSIVE_CREATURES_PATH L"../../Resource/Image/Passive_creatures.png"
#pragma endregion

class PassiveCreatures : public UnplayableObj
{
public:
    PassiveCreatures();
    PassiveCreatures(float x, float y, float vX = 2, float vY = 0, int numberOfAnimatedTiles = 1,
        float width = 20.4, float height = 20.4, LPCWSTR fileSpriteName = SPRITE_PASSIVE_CREATURES_PATH);
    PassiveCreatures& operator = (const PassiveCreatures& enemies);
    bool Load(D3DXCOLOR transparentColor, DirectXGraphic directXGrphic);
};