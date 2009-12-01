#pragma once

#include "main.h"

class IntroScene : public FScene
{
public:
	virtual void Load();
	virtual void Update();
};

class IntroSceneSub : public FScene
{
public:
	virtual void Load();
	virtual void Update();
};
