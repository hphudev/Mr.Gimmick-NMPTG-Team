#include "PlayableObj.h"

#pragma region Definition
#define YUMETARO_START_X 16 * 4
#define YUMETARO_START_Y 16 * 21 - 5

#define YUMETARO_VELOCITY_X 1
#define YUMETARO_VELOCITY_Y 0

#define YUMETARO_WIDTH 19.4f
#define YUMETARO_HEIGHT 23.0f

#define YUMETARO_BACKGROUND_COLOR D3DCOLOR_XRGB(0, 0, 255)

#define SPRITE_YUMETARO_PATH L"../../Resource/Yumetaro.png"
#pragma endregion

class Yumetaro : public PlayableObj
{
public:
    Yumetaro();
    Yumetaro(float x, float y, float vX, float vY, float width, float height, LPCWSTR fileSpriteName);
    bool Load(D3DXCOLOR transparentColor, DirectXGraphic directXGrphic);
    void Move(int screenWidth, int screenHeight);
};