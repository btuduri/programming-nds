#pragma once

#include "FLib.h"

class FEngine;
class FVideoManager;

class FScene
{
	FBackground* backgrounds[4];
	FSprite* sprites[SPRITE_COUNT];
	int spriteCount;
	bool mainEngine;

protected:
	FEngine* engine;
	FInputManager* im;
	FVideoManager* vm;
	
public:
	~FScene();
	void AddBackground(int layer, FBackground *background, int init_x, int init_y);
	void ClearBackground(int layer);
	void AddSprite(FSprite *sprite);
	void Load(bool mainEngine, FEngine* engine, FInputManager *im, FVideoManager *vm);
	virtual void Load() = 0;
	virtual void Update() = 0;
};
