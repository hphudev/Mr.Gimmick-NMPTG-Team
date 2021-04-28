#pragma once
#include "Scene.h"

#define COUNT_CLOUD 10

class SceneMap :
	public Scene
{
	struct Cloud
	{
		float posHeight;
		float posWidth;
		bool isBigCloud;
		bool isBefore;
		float speed;
	} arrCloud[COUNT_CLOUD];
public:
	SceneMap() {};
	~SceneMap() {};

	SceneMap(HWND window);
	void Run(DWORD time, DWORD& timeStart);

	void OnKeyUp(int keycode) {  };
	void OnKeyDown(int keycode) { nextScene = 3; };
};

