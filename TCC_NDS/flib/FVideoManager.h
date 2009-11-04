#pragma once

#include "FLib.h"

#include "FBackground.h"
#include "FSprite.h"
#include "FConsole.h"
#include "FScene.h"
#include "FPalette.h"
#include "FEngine.h"

class FVideoManager
{
	FEngine* mainEngine;
	FEngine* subEngine;
	FInputManager* im;

public:
	FVideoManager(FInputManager* im, bool is3D);

	FEngine* GetMainEngine();
	FEngine* GetSubEngine();
	void Update();
	void Hide();
	void Show();
	void FadeIn(int time);
	void FadeOut(int time);
	void SwapScreens();
};
	