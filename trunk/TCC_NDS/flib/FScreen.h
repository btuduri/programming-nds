#pragma once

#include "FLib.h"

class F_Screen
{
private:

	bool mainEngine;
	F_Background* backgrounds[4];
	F_Sprite* sprites[SPRITE_COUNT];
	int spriteCount;

public:

	F_Screen(bool mainEngine);
	void Enable3D();
	void AddBackground(int layer, F_Background *background, int init_x, int init_y);
	void AddSprite(F_Sprite *sprite);
	void AddTileset(const void* tileset, int tilesetLen);
};
