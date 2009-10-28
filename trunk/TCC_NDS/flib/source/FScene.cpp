#include "FLib.h"

void FScene::AddBackground(int layer, FBackground *background, int init_x, int init_y)
{
	backgrounds[layer] = background;
	backgrounds[layer]->Load(mainEngine, layer, init_x, init_y);
}

void FScene::AddSprite(FSprite *sprite)
{
	sprites[spriteCount] = sprite;
	sprites[spriteCount]->Load(mainEngine, spriteCount);
	spriteCount++;
}

void FScene::Load(bool mainEngine, FEngine* engine, FInputManager* im, FVideoManager *vm)
{
	this->mainEngine = mainEngine;
	this->engine = engine;
	this->im = im;
	this->vm = vm;
}
