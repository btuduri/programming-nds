#include "FLib.h"

void FScene::AddBackground(int layer, FBackground *background, int init_x, int init_y)
{
	backgrounds[layer] = background;
	this->init_x[layer] = init_x;
	this->init_y[layer] = init_y;
}

void FScene::AddSprite(FSprite *sprite)
{
	sprites[spriteCount] = sprite;
	spriteCount++;
}

void FScene::Load(bool mainEngine)
{
	for (int i = 0; i < 4; i++)
		if (backgrounds[i])
			backgrounds[i]->Load(mainEngine, i, init_x[i], init_y[i]);
	for (int i = 0; i < 128; i++)
		if (sprites[i])
			sprites[i]->Load(mainEngine, spriteCount);
}
