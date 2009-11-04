#include "FLib.h"

FScene::~FScene()
{
	for (int i = 0; i < 4; i++)
		if (backgrounds[i])
			delete backgrounds[i];

	for (int i = 0; i < SPRITE_COUNT; i++)
		if (sprites[i])
			delete sprites[i];
}

///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////

void FScene::AddBackground(int layer, FBackground *background, int init_x, int init_y)
{
	if (backgrounds[layer])
		delete backgrounds[layer];
	backgrounds[layer] = background;
	backgrounds[layer]->Load(mainEngine, layer, init_x, init_y);
}

///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////

void FScene::ClearBackground(int layer)
{
	if (backgrounds[layer])
	{
		delete backgrounds[layer];
		backgrounds[layer] = NULL;
	}
}

///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////

void FScene::AddSprite(FSprite *sprite)
{
	sprites[spriteCount] = sprite;
	sprites[spriteCount]->Load(mainEngine, spriteCount);
	spriteCount++;
}

///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////

void FScene::Load(bool mainEngine, FEngine* engine, FInputManager* im, FVideoManager *vm)
{
	this->mainEngine = mainEngine;
	this->engine = engine;
	this->im = im;
	this->vm = vm;
}
