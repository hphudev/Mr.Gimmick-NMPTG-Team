#include "GraphicDevice.h"

GraphicDevice::~GraphicDevice()
{
	//release the Direct3D device
	if (this->device != NULL)
	{
		this->device->Release();
	}
}

bool GraphicDevice::InitDevice(LPDIRECT3D9 direct3D, HWND window, int width, int height, 
	bool isFullscreen)
{
	D3DPRESENT_PARAMETERS deviceParameter;		//Biến chứa các tham số của thiết bị

	//Khởi tạo các tham số của thiết bị
	ZeroMemory(&deviceParameter, sizeof(deviceParameter));		//Xóa mọi tham số về 0 trước khi sử dụng
	deviceParameter.Windowed = (!isFullscreen);
	deviceParameter.SwapEffect = D3DSWAPEFFECT_COPY;
	deviceParameter.BackBufferFormat = D3DFMT_X8R8G8B8;
	deviceParameter.BackBufferCount = 1;
	deviceParameter.BackBufferWidth = width;
	deviceParameter.BackBufferHeight = height;
	deviceParameter.hDeviceWindow = window;

	//Khởi tạo đối tượng device từ card màn hình mặc định (D3DADAPTER_DEFAULT), quy định vẽ bằng phần 
	//cứng thay vì giả lập (D3DDEVTYPE_HAL) và dựa trên các tham số thể hiện của thiết bị 
	//(&deviceParameter)
	direct3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, window,
		D3DCREATE_SOFTWARE_VERTEXPROCESSING, &deviceParameter, &this->device);

	//Đảm bảo đối tượng device đã được khởi tạo
	if (this->device == NULL)
	{
		IOHandler::ExportError(window, L"Error initializing Direct3D device");
		return 0;
	}

	//Xóa backbuffer về màu đen
	this->device->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0, 0, 0), 1.0f, 0);

	//Tạo con trỏ trỏ đến backbuffer
	this->device->GetBackBuffer(0, 0, D3DBACKBUFFER_TYPE_MONO, &this->backbuffer);

	return 1;
}

LPDIRECT3DDEVICE9 GraphicDevice::GetDevice()
{
	return this->device;
}