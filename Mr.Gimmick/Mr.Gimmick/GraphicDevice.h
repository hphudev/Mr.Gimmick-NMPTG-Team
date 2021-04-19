#pragma once

#include "Device.h"
#include <d3d9.h>
#include <d3dx9.h>
#include "IOHandler.h"

class GraphicDevice : public Device
{
private:
	LPDIRECT3DDEVICE9 device;		//Biến đại diện cho card đồ họa máy tính
	LPDIRECT3DSURFACE9 backbuffer;
public:
	bool InitDevice(LPDIRECT3D9 direct3D, HWND window, int width, int height, bool isFullscreen);
	void ReleaseDevice();
	HRESULT CreateSurface(D3DXIMAGE_INFO imageInfo, LPDIRECT3DSURFACE9& image);
	HRESULT CreateTexture(LPCWSTR filename, D3DXIMAGE_INFO& imageInfo, D3DCOLOR transparentColor, 
		LPDIRECT3DTEXTURE9& image);
	void DrawSurface(LPDIRECT3DSURFACE9 sourceSurface, LPDIRECT3DSURFACE9 destinationSurface,
		RECT* sourceRectangle, RECT* destinationRectangle);
	bool CheckDevice();
	bool BeginRendering();
	void EndRendering();
	void ShowBackbuffer();
	HRESULT CreateSpriteHandler(LPD3DXSPRITE& spriteHandler);
	LPDIRECT3DSURFACE9 GetBackbuffer();
};