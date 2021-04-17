#include "IOHandler.h"

void IOHandler::ExportError(HWND window, LPCWSTR content)
{
	MessageBox(window, content, L"Error", MB_OK);
}