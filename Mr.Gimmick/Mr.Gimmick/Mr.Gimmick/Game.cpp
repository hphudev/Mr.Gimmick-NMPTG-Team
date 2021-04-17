#include "Game.h"

// Khởi tạo game
bool Game::InitGame(HWND window)
{
	// Đặt lại tiến trình số ngẫu nhiên
	srand((unsigned int)time(NULL));

	// Trả về okay
	return 1;
}

// Vòng lặp game chính
void Game::RunGame(HWND window)
{
	LPDIRECT3DDEVICE9 direct3DDevice = this->directX.GetDirectXGraphic().GetGraphicDevice().GetDevice();

	// Đảm bảo Direct3D device đã có
	if (!direct3DDevice == NULL)
	{
		return;
	}

	// Bắt đầu render
	if (direct3DDevice->BeginScene())
	{
		// Dừng render
		direct3DDevice->EndScene();
	}

	// Thể hiện back buffer lên màn hình
	direct3DDevice->Present(NULL, NULL, NULL, NULL);

	// Kiểm tra phím escape và nút chuột (để kết thúc chương trình)
	if (KEY_DOWN(VK_ESCAPE) || this->directX.GetDirectInput().GetMouse()->CheckPressedMouseButton(0))
	{
		PostMessage(window, WM_DESTROY, 0, 0);
	}
}

// Giải phóng bộ nhớ và dọn dẹp trước khi kết thúc game
void Game::EndGame(HWND window)
{
	
}

DirectX Game::GetDirectX()
{
	return this->directX;
}