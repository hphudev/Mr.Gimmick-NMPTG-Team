#include "InputDevice.h"

class Keyboard : public InputDevice
{
private:
	char keys[256];		// Mảng các phím có thể đặt giá trị, chỉ ra được trạng thái của thiết bị bàn 
						// phím
public:
	void PollDevice();
	int CheckPressedKey(int key);
};