#include "DirectX.h"

// *
bool DirectX::InitDirectX(HWND window, int screenWidth, int screenHeight, bool isFullscreen)
{
	//make sure Direct3D objects was created okay
	if (!this->directXGraphic.InitDirect3DObjects(window, screenWidth, screenHeight, isFullscreen))
// *
	{
		return 0;
	}

	//make sure DirectInput objects was created okay
	if (!this->directInput.InitDirectInputObjects(window))
	{
		return 0;
	}

	//make sure DirectSound objects was created okay
	//if (!this->directSound.InitDirectSoundObjects(window))
	//{
	//	return 0;
	//}

	return 1;
}

DirectXGraphic DirectX::GetDirectXGraphic()
{
    return this->directXGraphic;
}

DirectInput DirectX::GetDirectInput()
{
    return this->directInput;
}

//DirectSound DirectX::GetDirectSound()
//{
//    return this->directSound;
//}

void DirectX::ReleaseDirectX()
{
	this->directXGraphic.Release();
	this->directInput.Release();
}