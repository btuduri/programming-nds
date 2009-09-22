#include "FLib.h"

#ifndef _F_STAGE_
#define _F_STAGE_

class F_Stage
{
	F_Background *backgrounds[4];
	int scroll_speeds[4];
	//F_Sprite *sprites[128];
	F_Music *music;

public:
	F_Stage(u8 *tileset, int tilesetLen, u16* palette, int paletteLen)
	{
		dmaCopy(palette, BG_PALETTE, paletteLen);
		dmaCopy(palette, SPRITE_PALETTE, paletteLen);
		dmaCopy(tileset, BG_TILE_RAM(2), tilesetLen);
	}

	void SetMusic(F_Music *music)
	{
		this->music = music;
		music->Play();
	}

	void AddBackground(int layer, F_Background *background, int scroll_speed)
	{
		backgrounds[layer] = background;
		scroll_speeds[layer] = scroll_speed;
		background->Load(layer);
	}

	void AddSprite(u8* gfx, int framesCount)
	{
	//	sprites[spriteCount++] = new F_Sprite(u8* gfx, int framesCount);
	}
};

#endif