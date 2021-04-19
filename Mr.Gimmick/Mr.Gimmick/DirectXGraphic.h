#pragma once

#include <d3d9.h>
#include <d3dx9.h>
#include "IOHandler.h"
#include "GraphicDevice.h"
#include "DirectXComponent.h"

class DirectXGraphic : public DirectXComponent
{
private:
	LPDIRECT3D9 direct3D;		//Biến "tổng" của toàn bộ thư viện Direct3D
	GraphicDevice graphicDevice;
public:
	bool InitDirect3DObjects(HWND window, int width, int height, bool isFullscreeen);
	void Release();
	LPDIRECT3DSURFACE9 LoadSurface(LPCWSTR filename, D3DCOLOR transparentColor);
	LPDIRECT3DTEXTURE9 LoadTexture(LPCWSTR filename, D3DCOLOR transparentColor);
	GraphicDevice GetGraphicDevice();
};