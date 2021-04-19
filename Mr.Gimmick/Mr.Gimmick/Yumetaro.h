#include "PlayableObj.h"

class Yumetaro : public PlayableObj
{
public:
    Yumetaro();
    Yumetaro(float x, float y, float vX, float vY, float size, LPCWSTR fileSpriteName);
    bool Load(D3DXCOLOR transparentColor, DirectXGraphic directXGrphic);
    void Move(int screenWidth, int screenHeight);
};