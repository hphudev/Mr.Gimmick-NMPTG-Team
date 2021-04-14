#include "DirectXGraphic.h"
#include "DirectInput.h"

class DirectX
{
private:
	DirectXGraphic directXGraphic;
	DirectInput directInput;
public:
	DirectXGraphic GetDirectXGraphic();
	DirectInput GetDirectInput();
};