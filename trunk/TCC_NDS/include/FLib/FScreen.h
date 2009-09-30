#include "FLib.h"

#ifndef _F_SCREEN_
#define _F_SCREEN_

class F_Screen
{
	F_Background *backgrounds[4];
	F_Sprite *sprites[128];
	int spriteCount;

public:
	F_Screen(u8 *tileset, int tilesetLen, u16* backgroundPal, u16* spritePal)
	{
		dmaCopy(backgroundPal, BG_PALETTE, 512);
		dmaCopy(spritePal, SPRITE_PALETTE, 512);
		dmaCopy(tileset, BG_TILE_RAM(2), tilesetLen);
		spriteCount = 0;
	}

	void AddBackground(int layer, F_Background *background, int init_x, int init_y)
	{
		backgrounds[layer] = background;
		background->Load(layer, init_x, init_y);
	}

	void AddSprite(F_Sprite *sprite)
	{
		sprite->Load(true, spriteCount);
		sprites[spriteCount++] = sprite;
	}
};

#endif