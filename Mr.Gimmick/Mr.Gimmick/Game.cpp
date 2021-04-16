#include "Game.h"

// *
// Khởi tạo game
bool Game::InitGame(HWND window)
{
	this->window = window;

	return this->directX.InitDirectX(this->window);
}

// *
void Game::LoadGame()
{

}

// Vòng lặp game chính
void Game::RunGame(HWND window)
{
	GraphicDevice graphicDevice = this->directX.GetDirectXGraphic().GetGraphicDevice();

	// Đảm bảo Direct3D device đã có
	if (!graphicDevice.CheckDevice())
	{
		return;
	}

	// Bắt đầu render
	if (graphicDevice.BeginRendering())
	{
		// Dừng render
		graphicDevice.EndRendering();
	}

	// Thể hiện backbuffer lên màn hình
	graphicDevice.ShowBackbuffer();

	// Kiểm tra phím escape và nút chuột (để kết thúc chương trình)
	if (KEY_DOWN(VK_ESCAPE) || this->directX.GetDirectInput().GetMouse()->CheckPressedMouseButton(0))
	{
		PostMessage(window, WM_DESTROY, 0, 0);
	}
}

// *
void Game::UpdateGame()
{

}

// *
void Game::Render()
{

}

// Giải phóng bộ nhớ và dọn dẹp trước khi kết thúc game
void Game::EndGame(HWND window)
{
	
}

DirectX Game::GetDirectX()
{
	return this->directX;
}