#include "InputDevice.h"

InputDevice::~InputDevice()
{
	if (this->device != NULL)
	{
		// Trả quyền kiểm soát thiết bị
		this->device->Unacquire();

		this->device->Release();
	}
}

bool InputDevice::InitDevice(LPDIRECTINPUT8& directInput, int type, HWND window)	// *
{
	// Khởi tạo đối tượng thiết bị
	HRESULT result = directInput->CreateDevice(
		!type ? GUID_SysKeyboard : GUID_SysMouse,		// Giá trị đặc tả cho kiểu của đối tượng mà bạn 
														// muốn tạo (GUID_SysKeyboard hoặc 
														// GUID_SysMouse)
		&this->device,		// Con trỏ đến đối tượng thiết bị
		NULL);		// Luôn luôn là NULL

	// Chắc chắn đối tượng thiết bị được tạo
	if (result != DI_OK)
	{
		return 0;
	}

	// Thiết lập định dạng dữ liệu
	result = this->device->SetDataFormat(
		!type ? &c_dfDIKeyboard : &c_dfDIMouse);		// Tham số đặc tả cho kiểu thiết bị 
														// (c_dfDIKeyboard hoặc c_dfDIMouse)

	// Chắc chắn thiết lập định dạng dữ liệu thành công
	if (result != DI_OK)
	{
		return 0;
	}

	// Thiết lập mức độ hợp tác, chỉ ra được mức độ bàn phím DirectInput sẽ đưa vào trong chương trình 
	// theo độ ưu tiên, đồng thời ẩn con trỏ chuột (với chuột)
	result = this->device->SetCooperativeLevel(
		window,		// Tham số đầu tiên là handle của cửa sổ
		DISCL_NONEXCLUSIVE | DISCL_FOREGROUND);		// Tham số thứ hai xác định độ ưu tiên của bàn phím 
													// và chuột đối với chương trình của chúng ta. Giá 
													// trị chung thường được truyền khi làm việc với 
													// bàn phím và chuột là DISCL_NONEXCLUSIVE và 
													// DISCL_FOREGROUND
													// *

	// Chắc chắn thiết lập mức độ hợp tác thành công
	if (result != DI_OK)
	{
		return 0;
	}

	// Giành quyền kiểm soát thiết bị
	result = this->device->Acquire();

	// Chắc chắn giành quyền kiểm soát thiết bị thành công
	if (result != DI_OK)
	{
		return 0;
	}

	return 1;
}