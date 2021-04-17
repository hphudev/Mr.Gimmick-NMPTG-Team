#include "DirectInput.h"

DirectInput::~DirectInput()
{
	if (this->directInput != NULL)
	{
		this->directInput->Release();
	}

	for (int i = 0; i < 2; i++)
	{
		delete this->devices[i];
	}

	delete[] this->devices;
}

bool DirectInput::InitDirectInputObjects(HWND window)
{
	this->devices = new InputDevice * [2];
	this->devices[0] = new Mouse();
	this->devices[1] = new Keyboard();

	// Khởi tạo đối tượng directInput
	HRESULT result = DirectInput8Create(
		GetModuleHandle(NULL),		// Thể hiện cho chương trình hiện tại
		DIRECTINPUT_VERSION,		// Luôn luôn là DIRECTINPUT_VERSION
		IID_IDirectInput8,		// Định danh phiên bản DirectInput mà ta muốn sử dụng (hiện tại là 
								// IID_IDirectInput8)
		(void**)&this->directInput,		// Con trỏ trỏ đến con trỏ đối tượng DirectInput	// *
		NULL);		// Luôn luôn là NULL

	// Chắc chắn đối tượng directInput được tạo
	if (result != DI_OK)
	{
		IOHandler::ExportError(window, L"Erorr initializing DirectInput");
		return 0;
	}

	// Chắc chắn đối tượng chuột được tạo
	if (!this->devices[0]->InitDevice(this->directInput, 1, window))
	{
		IOHandler::ExportError(window, L"Erorr initializing the mouse");
		return 0;
	}

	// Chắc chắn đối tượng bàn phím được tạo
	if (!this->devices[1]->InitDevice(this->directInput, 0, window))
	{
		IOHandler::ExportError(window, L"Erorr initializing the keyboard");
		return 0;
	}
	
	// Thiết lập cho chuột và bàn phím
	for (int i = 0; i < 2; i++)
	{
		this->devices[i]->PollDevice();
	}

	return 1;
}

Mouse* DirectInput::GetMouse()
{
	return (Mouse*)this->devices[0];
}