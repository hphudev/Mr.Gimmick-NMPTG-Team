#pragma once

#include <d3d9.h>
#include "Handler.h"

class IOHandler : public Handler
{
public:
	static void ExportError(HWND window, LPCWSTR content);
};