#pragma once

#include "FLib.h"
#include "backgrounds.h"
#include "sprites.h"

class MainScene : public FScene
{
	FInputManager* im;
	FBackground* bg;
	FSprite* sp;
	float squareRot;
	float triangRot;

	void DrawGLScene();

public:
	MainScene(FInputManager* im);
	virtual void Update();
};