#include "Device.h"
#include <d3d9.h>
#include "IOHandler.h"

class GraphicDevice : public Device
{
private:
	LPDIRECT3DDEVICE9 device;		//Biến đại diện cho card đồ họa máy tính
	LPDIRECT3DSURFACE9 backbuffer;
public:
	~GraphicDevice();
	bool InitDevice(LPDIRECT3D9 direct3D, HWND window, int width, int height, bool isFullscreen);
	LPDIRECT3DDEVICE9 GetDevice();
};