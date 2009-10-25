#pragma once

#include "FLib.h"

class FScene
{
	FBackground* backgrounds[4];
	FSprite* sprites[SPRITE_COUNT];
	int spriteCount, init_x[4], init_y[4];
public:

	void AddBackground(int layer, FBackground *background, int init_x, int init_y);
	void AddSprite(FSprite *sprite);
	void Load(bool mainEngine);
	virtual void Update() = 0;
};
