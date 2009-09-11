#ifndef _F_MEMORY_
#define _F_MEMORY_

#include "FLib.h"

void F_LoadPalette(const void *palette)
{
	dmaCopy(palette, BG_PALETTE, sizeof(palette));
}

void F_LoadTileset(const void *tileset, u16 bank)
{
	dmaCopy(tileset, BG_TILE_RAM(bank), sizeof(tileset));
}

void F_LoadTilemap(const void *tilemap, u16 bank)
{
	dmaCopy(tilemap, BG_MAP_RAM(bank), sizeof(tilemap));
}

void F_LoadPaletteSub(const void *palette)
{
	dmaCopy(palette, BG_PALETTE_SUB, sizeof(palette));
}

void F_LoadTilesetSub(const void *tileset, u16 bank)
{
	dmaCopy(tileset, BG_TILE_RAM_SUB(bank), sizeof(tileset));
}

void F_LoadTilemapSub(const void *tilemap, u16 bank)
{
	dmaCopy(tilemap, BG_MAP_RAM_SUB(bank), sizeof(tilemap));
}

#endif