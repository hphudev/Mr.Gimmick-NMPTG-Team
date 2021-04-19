#pragma once

#include "Mouse.h"
#include "Keyboard.h"
#include "IOHandler.h"
#include "DirectXComponent.h"

class DirectInput : public DirectXComponent
{
private:
	LPDIRECTINPUT8 directInput;
	InputDevice** devices;
public:	
	bool InitDirectInputObjects(HWND window);
	void Release();
	Mouse* GetMouse();
};