#include "Scene.h"

Scene::Scene()
{
	int nextScene = -1;
}
void Scene::Draw(LPDIRECT3DTEXTURE9 texture, float posx, float posy, float left, float top, float right, float bottom)
{
	D3DXVECTOR3 p(posx, posy, 0);
	RECT r;
	r.left = left;
	r.top = top;
	r.right = right;
	r.bottom = bottom;
	spriteHandler->Begin(D3DXSPRITE_ALPHABLEND);
	spriteHandler->Draw(texture, &r, NULL, &p, D3DCOLOR_XRGB(255, 255, 255));
	spriteHandler->End();
}