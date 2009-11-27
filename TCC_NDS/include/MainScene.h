#pragma once

#include "FLib.h"
#include "backgrounds.h"
#include "sprites.h"

class MainScene : public FScene
{
	FBackground* bg;
	FSprite* sp;
	float squareRot;
	float triangRot;
	int frame;

	void DrawGLScene();

public:
	virtual void Load();
	virtual void Update();
};