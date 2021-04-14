#pragma once

#include <dinput.h>
#include "Device.h"

class InputDevice : public Device
{
protected:
	LPDIRECTINPUTDEVICE8 device;
public:
	~InputDevice();
	virtual void PollDevice() = 0;		// Thiết lập trạng thái thiết bị
	bool InitDevice(LPDIRECTINPUT8& directInput, int type, HWND window);		// type = 0 = keyboard
																				// type = 1 = mouse
																				// *
};