#pragma once

#include "DirectXGraphic.h"
#include "Tile.h"
#include "Sprite.h"
#include "TransformHandler.h"

class MovableTile : public Tile
{
protected:
    Sprite* sprite;
    LPDIRECT3DTEXTURE9 texture;
public:
    MovableTile();
    MovableTile(float x, float y, float spriteWidth, float spriteHeight, LPCWSTR fileSpriteName, 
        int lastSpriteFrame, int animationDelay, int currentSpriteFrame = 0, int animationCount = 0);
    ~MovableTile();
    void Draw(GraphicDevice graphicDevice, int indexOfRow = 0, bool isRotate = 0,
        LPDIRECT3DSURFACE9 backbuffer = NULL);
    bool Load(D3DXCOLOR transparentColor, DirectXGraphic directXGraphic);
    RECT* GetRectangleOfSprite();
    Sprite* GetSprite();
    void Animate();
};