#pragma once

#include "main.h"

class MarioScene : public FScene
{
	FBackground* bg3;
	FBackground* bg2;
	FSprite* mario;
	int timer;
	int frame;
	int parallax;
public:
	virtual void Load();
	virtual void Update();
};

class MarioSceneSub : public FScene
{
public:
	virtual void Load();
	virtual void Update();
};
