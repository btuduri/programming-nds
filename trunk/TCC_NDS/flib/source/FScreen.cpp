#include "FLib.h"

F_Screen::F_Screen(bool mainEngine)
{
	this->mainEngine = mainEngine;
}

void F_Screen::AddBackground(int layer, F_Background *background, int init_x, int init_y)
{
	backgrounds[layer] = background;
	background->Load(mainEngine, layer, init_x, init_y);
}

void F_Screen::AddSprite(F_Sprite *sprite)
{
	sprite->Load(mainEngine, spriteCount);
	sprites[spriteCount++] = sprite;
}

void F_Screen::AddTileset(const void* tileset, int tilesetLen)
{
	if (mainEngine)
		dmaCopy(tileset, BG_TILE_RAM(3), tilesetLen);
	else
		dmaCopy(tileset, BG_TILE_RAM_SUB(3), tilesetLen);
}
