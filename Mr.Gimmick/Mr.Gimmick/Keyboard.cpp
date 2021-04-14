#include "Keyboard.h"

void Keyboard::PollDevice()
{
	// Đặt giá trị cho mảng các phím
	this->device->GetDeviceState(
		sizeof(this->keys),		// Kích thước của bộ đệm trạng thái thiết bị cần lấy dữ liệu
		(LPVOID)&this->keys);		// Con trỏ cho dữ liệu
}

int Keyboard::CheckPressedKey(int key)
{
	return this->keys[key] & 0x80;
}