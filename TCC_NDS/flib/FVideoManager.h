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

public:
	FVideoManager();

	FEngine* GetMainEngine();
	FEngine* GetSubEngine();
	void Enable3D();
	void Update();
};
	