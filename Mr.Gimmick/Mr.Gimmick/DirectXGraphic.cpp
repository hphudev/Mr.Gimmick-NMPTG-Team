#include "DirectXGraphic.h"

DirectXGraphic::~DirectXGraphic()
{
	//release the Direct3D object
	if (this->direct3D != NULL)
	{
		this->direct3D->Release();
	}
}

bool DirectXGraphic::InitDirect3DObjects(HWND window, int width, int height, bool isFullscreen)
{
	//Khởi tạo đối tượng direct3D
	this->direct3D = Direct3DCreate9(D3D_SDK_VERSION);

	//Đảm bảo đối tượng direct3D đã được khởi tạo
	if (this->direct3D == NULL)
	{
		IOHandler::ExportError(window, L"Error initializing Direct3D");
		return 0;
	}

	//Đảm bảo đối tượng graphicDevice đã được khởi tạo
	if (!this->graphicDevice.InitDevice(this->direct3D, window, width, height, isFullscreen))
	{
		return 0;
	}

	return 1;
}

LPDIRECT3DSURFACE9 DirectXGraphic::LoadSurface(LPCWSTR filename, D3DCOLOR transparentColor)
{
	//pointer to surface
	LPDIRECT3DSURFACE9 image = NULL;
	//variable to read info of bitmap file
	D3DXIMAGE_INFO imageInfo;
	//casual window's value
	HRESULT result;

	//get width and height from bitmap file
	result = D3DXGetImageInfoFromFile(filename, &imageInfo);

	//make sure result was loaded okay
	if (result != D3D_OK)
	{
		return NULL;
	}

	result = this->graphicDevice.CreateSurface(imageInfo, image);

	//make sure surface was created okay
	if (result != D3D_OK)
	{
		return NULL;
	}

	//load surface from file into newly created surface
	result = D3DXLoadSurfaceFromFile(
		image, //destination surface
		NULL, //destination palette
		NULL, //destination rectangle
		filename, //source filename
		NULL, //source rectangle
		D3DX_DEFAULT, //controls how image is filtered
		transparentColor, //for transparency (0 for none)
		NULL); //source image info (usually NULL)

	//make sure file was loaded okay
	if (result != D3D_OK)
	{
		return NULL;
	}

	return image;
}

LPDIRECT3DTEXTURE9 DirectXGraphic::LoadTexture(LPCWSTR filename, D3DCOLOR transparentColor)
{
	// Con trỏ đến texture
	LPDIRECT3DTEXTURE9 image = NULL;
	// Biến để đọc thông tin tệp bitmap
	D3DXIMAGE_INFO imageInfo;
	// Giá trị window thông thường
	HRESULT result;

	// Lấy ra thông tin width và height từ tệp bitmap
	result = D3DXGetImageInfoFromFile(filename, &imageInfo);

	if (result != D3D_OK)
	{
		return NULL;
	}

	result = this->graphicDevice.CreateTexture(filename, imageInfo, transparentColor, image);

	// Đảm bảo texture đã được tải lên thành công
	if (result != D3D_OK)
	{
		return NULL;
	}

	return image;
}

GraphicDevice DirectXGraphic::GetGraphicDevice()
{
	return this->graphicDevice;
}