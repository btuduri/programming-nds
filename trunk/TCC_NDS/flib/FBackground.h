#include "FLib.h"

#ifndef _F_BACKGROUND_
#define _F_BACKGROUND_

class F_Background
{
	int id;
	int layer;
	bool mainEngine;

	u16 *tilemap;
	int map_base;
	int ram_base;
	int width, height;

	int x, y;
	int limit_x, limit_y;
	int screen_x, screen_y;
	bool alternate_x, alternate_y;

public:
	F_Background(const void* tilemap, int width, int height);
	void Load(bool mainEngine, int layer, int init_x, int init_y);
	void Scroll(int offset_x, int offset_y);
	void InfiniteScroll(int offset_x, int offset_y);

private:
	int Offset(int i) { return i * 1024; }
	u16* BgMapRam(int base) { return mainEngine ? BG_MAP_RAM(base) : BG_MAP_RAM_SUB(base); }
};

#endif
