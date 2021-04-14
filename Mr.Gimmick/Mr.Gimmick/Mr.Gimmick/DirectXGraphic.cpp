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

	//create surface
	result = this->graphicDevice.GetDevice()->CreateOffscreenPlainSurface(
		imageInfo.Width, //width of the surface
		imageInfo.Height, //height of the surface
		D3DFMT_X8R8G8B8, //surface format
		D3DPOOL_DEFAULT, //memory pool to use
		&image, //pointer to the surface
		NULL); //reserved (always NULL)

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

	// Tạo texture mới bằng cách tải lên tệp bitmap
	result = D3DXCreateTextureFromFileEx(
		this->graphicDevice.GetDevice(), // Đối tượng Direct3D
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

void DirectXGraphic::DrawSurface(LPDIRECT3DSURFACE9 sourceSurface, 
	LPDIRECT3DSURFACE9 destinationSurface, RECT* sourceRectangle, RECT* destinationRectangle)
{
	this->graphicDevice.GetDevice()->StretchRect(
		sourceSurface,		// Pointer to source surface
		sourceRectangle,		// Pointer to source rectangle
		destinationSurface,			// Pointer to destination surface
		destinationRectangle,		// Pointer to destination rectangle
		D3DTEXF_NONE);		// Filter
}