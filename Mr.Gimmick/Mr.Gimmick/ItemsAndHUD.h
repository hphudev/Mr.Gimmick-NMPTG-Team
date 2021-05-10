#pragma once

#include "UsefulObj.h"

#pragma region Definition
#define ITEMS_AND_HUD_BACKGROUND_COLOR D3DCOLOR_XRGB(255, 255, 255)

#define SPRITE_ITEMS_AND_HUD_PATH L"../../Resource/Image/Items_and_HUD.png"
#pragma endregion

class ItemsAndHUD : public UsefulObj
{
public:
    ItemsAndHUD();
    ItemsAndHUD(float x, float y, int gameObjID, int currentFrame = 1, float width = 16.5, 
        float height = 17, int numberOfAnimatedTiles = 1, 
        LPCWSTR fileSpriteName = SPRITE_ITEMS_AND_HUD_PATH);
    ItemsAndHUD& operator = (const ItemsAndHUD& itemsAndHUD);
    bool Load(D3DXCOLOR transparentColor, DirectXGraphic directXGrphic);
};