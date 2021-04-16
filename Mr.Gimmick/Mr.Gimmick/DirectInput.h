// *
#pragma once

#include "Mouse.h"
#include "Keyboard.h"
#include "IOHandler.h"

class DirectInput
{
private:
	LPDIRECTINPUT8 directInput;
	InputDevice** devices;
public:
	~DirectInput();		
	bool InitDirectInputObjects(HWND window);
	Mouse* GetMouse();
};