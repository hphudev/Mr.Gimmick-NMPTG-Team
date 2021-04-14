#include "DirectXGraphic.h"
#include "DirectInput.h"
#include "DirectSound.h"		// *

class DirectX
{
private:
	DirectXGraphic directXGraphic;
	DirectInput directInput;
	//DirectSound directSound;		// *
public:
	DirectXGraphic GetDirectXGraphic();
	DirectInput GetDirectInput();
	//DirectSound GetDirectSound();		// *
};