#include "Mouse.h"

void Mouse::PollDevice()
{
	// Đặt giá trị cho biến mouseState
	this->device->GetDeviceState(
		sizeof(this->mouseState),		// Kích thước của bộ đệm trạng thái thiết bị cần lấy dữ liệu
		(LPVOID)(&this->mouseState));		// Con trỏ cho dữ liệu
}

int Mouse::GetMouseX()
{
	return this->mouseState.lX;
}

int Mouse::GetMouseY()
{
	return this->mouseState.lY;
}

int Mouse::CheckPressedMouseButton(int button)
{
	return BUTTON_DOWN(this->mouseState, button);
}