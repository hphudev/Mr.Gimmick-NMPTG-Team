#include "InputDevice.h"

// Định nghĩa nút chuột được nhấn
#define BUTTON_DOWN(mouseState, button) (mouseState.rgbButtons[button] & 0x80)

class Mouse : public InputDevice
{
private:
	DIMOUSESTATE mouseState;		// Biến chỉ ra được trạng thái của thiết bị chuột (DIMOUSESTATE cho 
									// chuột 4 nút, DIMOUSESTATE2 cho chuột nhiều hơn 4 nút)
public:
	void PollDevice();
	int GetMouseX();
	int GetMouseY();
	int CheckPressedMouseButton(int button);		// Kiểm tra nút chuột được nhấn (bắt đầu từ 0 cho 
													// button 1)
};