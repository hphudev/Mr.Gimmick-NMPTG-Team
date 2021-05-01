#include "GraphicDevice.h"

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

void GraphicDevice::ReleaseDevice()
{
	//release the Direct3D device
	if (this->device != NULL)
	{
		this->device->Release();
	}
}

HRESULT GraphicDevice::CreateSurface(D3DXIMAGE_INFO imageInfo, LPDIRECT3DSURFACE9& image)
{
	//create surface
	return this->device->CreateOffscreenPlainSurface(
		imageInfo.Width, //width of the surface
		imageInfo.Height, //height of the surface
		D3DFMT_X8R8G8B8, //surface format
		D3DPOOL_DEFAULT, //memory pool to use
		&image, //pointer to the surface
		NULL); //reserved (always NULL)
}

HRESULT GraphicDevice::CreateTexture(LPCWSTR filename, D3DXIMAGE_INFO& imageInfo, 
	D3DCOLOR transparentColor, LPDIRECT3DTEXTURE9& image)
{
	// Tạo texture mới bằng cách tải lên tệp bitmap
	return D3DXCreateTextureFromFileEx(
		this->device, // Đối tượng Direct3D Device
		filename, // Tên tệp bitmap
		imageInfo.Width, // Width của tệp bitmap
		imageInfo.Height, // Height của tệp bitmap
		1, // Kết nối level (1 nếu không có thay đổi)
		D3DPOOL_DEFAULT, // Kiểu của surface (thông thường)
		D3DFMT_UNKNOWN, // Định dạng surface (mặc định)
		D3DPOOL_DEFAULT, // Lớp bộ nhớ cho texture
		D3DX_DEFAULT, // Bộ lọc hình ảnh
		D3DX_DEFAULT, // Bộ lọc mip
		transparentColor, // Màu chỉ ra trong suốt
		&imageInfo, // Thông tin tệp bitmap (từ tệp tải lên)
		NULL, // Đổ màu
		&image); // Texture đích
}

void GraphicDevice::DrawSurface(LPDIRECT3DSURFACE9 sourceSurface, 
	LPDIRECT3DSURFACE9 destinationSurface, RECT* sourceRectangle, RECT* destinationRectangle)
{
	this->device->StretchRect(
		sourceSurface,		// Pointer to source surface
		sourceRectangle,		// Pointer to source rectangle
		destinationSurface,			// Pointer to destination surface
		destinationRectangle,		// Pointer to destination rectangle
		D3DTEXF_NONE);		// Filter
}

bool GraphicDevice::CheckDevice()
{
	return this->device != NULL;
}

bool GraphicDevice::BeginRendering()
{
	HRESULT result = this->device->BeginScene();
	return result == S_OK;
}

void GraphicDevice::EndRendering()
{
	this->device->EndScene();
}

void GraphicDevice::ShowBackbuffer()
{
	this->device->Present(NULL, NULL, NULL, NULL);
}

HRESULT GraphicDevice::CreateSpriteHandler(LPD3DXSPRITE& spriteHandler)
{
	return D3DXCreateSprite(this->device, &spriteHandler);
}

LPDIRECT3DSURFACE9 GraphicDevice::GetBackbuffer()
{
	return this->backbuffer;
}