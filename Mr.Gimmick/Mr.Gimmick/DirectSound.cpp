#include "DirectSound.h"
//
//DirectSound::~DirectSound()
//{
//	if (this->soundManager != NULL)
//	{
//		this->soundManager->Release();
//	}
//}
//
//bool DirectSound::InitDirectSoundObjects(HWND window)
//{
//	this->soundManager = new CSoundManager();
//	this->soundManager->Initialize(
//		window,		// Handle của chương trình
//		DSSCL_PRIORITY);		// Mức độ phối hợp của DirectSound với các chương trình khác
//
//	if (this->soundManager == NULL)
//	{
//		IOHandler::ExportError(window, L"Error initialize DirectSound");
//		return 0;
//	}
//
//	return 1;
//}
//
//bool DirectSound::LoadSound(LPCWSTR filename, CSound*& wave)
//{
//	this->soundManager->Create(&wave, filename);
//
//	return wave != NULL;
//}
//
//void DirectSound::PlaySound(CSound* wave)
//{
//	return wave->Play();
//}
//
//void DirectSound::LoopSound(CSound* wave)
//{
//	return wave->Play(0, DSBPLAY_LOOPING);
//}
//
//void DirectSound::StopSound(CSound* wave)
//{
//	return wave->Stop();
//}