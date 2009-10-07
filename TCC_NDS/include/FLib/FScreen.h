#include "FLib.h"

#ifndef _F_SCREEN_
#define _F_SCREEN_

class F_Screen
{
private:

	bool mainEngine;
	F_Background* backgrounds[4];
	F_Sprite* sprites[SPRITE_COUNT];
	int spriteCount;

public:

	F_Screen(bool mainEngine)
	{
		this->mainEngine = mainEngine;
	}

	void Enable3D()
	{
		if (mainEngine)
		{
		}
	}

	void AddBackground(int layer, F_Background *background, int init_x, int init_y)
	{
		backgrounds[layer] = background;
		background->Load(mainEngine, layer, init_x, init_y);
	}

	void AddSprite(F_Sprite *sprite)
	{
		sprite->Load(mainEngine, spriteCount);
		sprites[spriteCount++] = sprite;
	}

	void AddTileset(const void* tileset, int tilesetLen)
	{
		if (mainEngine)
			dmaCopy(tileset, BG_TILE_RAM(2), tilesetLen);
		else
			dmaCopy(tileset, BG_TILE_RAM_SUB(2), tilesetLen);
	}
};

F_Screen* mainScreen = new F_Screen(true);
F_Screen* subScreen = new F_Screen(false);

#endif