#include "MovableTile.h"

MovableTile::MovableTile()
{

}

MovableTile::MovableTile(float x, float y, float spriteWidth, float spriteHeight, 
	LPCWSTR fileSpriteName, int lastSpriteFrame, int animationDelay, int currentSpriteFrame, 
	int animationCount) : Tile(x, y)
{
	this->sprite = new Sprite(spriteWidth, spriteHeight, fileSpriteName, lastSpriteFrame, animationDelay,
		currentSpriteFrame, animationCount);
}

MovableTile::~MovableTile()
{
	if (this->texture != NULL)
	{
		this->texture->Release();
	}

	delete this->sprite;
}

void MovableTile::Draw(GraphicDevice graphicDevice, int indexOfRow, bool isRotate, 
	LPDIRECT3DSURFACE9 backbuffer)
{
	LPD3DXSPRITE spriteHandler;		// Biến để gọi các hàm để vẽ sprite từ texture
	
	// Tạo đối tượng sprite handler
	HRESULT result = graphicDevice.CreateSpriteHandler(spriteHandler);

	// Chắc chắn sprite handler được tạo thành công
	if (result != D3D_OK)
	{
		return;
	}

	// Bắt đầu Sprite Handler (khóa surface hiện tại)
	spriteHandler->Begin(
		D3DXSPRITE_ALPHABLEND);		// Sprite được vẽ hỗ trợ trong suốt

	// Tạo vector để cập nhật vị trí của sprite
	D3DXVECTOR3 position(this->point.GetFirstValue(), this->point.GetSecondValue(), 0);

	// Thiết đặt kích thước cho từng tile nguồn
	Dimension dimension = this->sprite->GetDimension();
	RECT sourceRectangle = this->sprite->GetSpriteHandler().GetTile(indexOfRow, dimension);

	// Xác định vị trí của điểm tâm trong trường hợp xoay ảnh
	D3DXVECTOR3 center;

	if (isRotate)
	{
		center = D3DXVECTOR3(dimension.GetFirstValue() / 2, dimension.GetSecondValue() / 2, 0);
	}

	// Vẽ sprite
	spriteHandler->SetTransform((new TransformHandler())->GetScaleMatrix());
	spriteHandler->Draw(
		this->texture,		// Texture được sử dụng làm hình ảnh nguồn cho sprite
		&sourceRectangle,		// Vị trí của tile trong sprite
		(isRotate ? &center : NULL),		// Điểm tâm dùng để xoay
		&position,		// Vị trí của sprite
		D3DCOLOR_XRGB(255, 255, 255));	// Màu thay thế được áp dụng khi vẽ sprite

	// Dừng Sprite Handler (mở khóa surface)
	spriteHandler->End();

	if (spriteHandler != NULL)
	{
		spriteHandler->Release();
	}
}

bool MovableTile::Load(D3DXCOLOR transparentColor, DirectXGraphic directXGraphic)
{
	this->texture = directXGraphic.LoadTexture(this->sprite->GetFilename(), transparentColor);

	if (this->texture == NULL)
	{
		return 0;
	}

	return 1;
}

RECT* MovableTile::GetRectangleOfSprite()
{
	Dimension dimension = this->sprite->GetDimension();
	float x = this->point.GetFirstValue();
	float y = this->point.GetSecondValue();
	float width = dimension.GetFirstValue();
	float height = dimension.GetSecondValue();

	RECT rectangle;
	rectangle.left = x + 1;
	rectangle.top = y + 1;
	rectangle.right = x + width - 1;
	rectangle.bottom = y + height - 1;

	return &rectangle;
}

Sprite* MovableTile::GetSprite()
{
	return this->sprite;
}

void MovableTile::Animate()
{
	this->sprite->Animate();
}

Tile* MovableTile::Clone()
{
	return new MovableTile(*this);
}

string MovableTile::GetType()
{
	return "MovableTile";
}