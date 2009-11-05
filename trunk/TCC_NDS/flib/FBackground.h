#pragma once

#include "FLib.h"

class FBackground
{
	int id;
	int layer;
	bool mainEngine;
	bool bitmapMode;

	u16 *tilemap;
	int map_base;
	int ram_base;
	int width, height;

	int x, y;
	int limit_x, limit_y;
	int screen_x, screen_y;
	bool alternate_x, alternate_y;

public:
	FBackground(const void* tilemap, int width, int height);
	FBackground(const void* bitmap);
	~FBackground();
	void Load(bool mainEngine, int layer, int init_x, int init_y);
	void Scroll(int offset_x, int offset_y);
	void InfiniteScroll(int offset_x, int offset_y);
	void FadeIn();
	void FadeOut();

private:
	int Offset(int i) { return i * 1024; }
	u16* BgMapRam(int base) { return mainEngine ? BG_MAP_RAM(base) : BG_MAP_RAM_SUB(base); }
};
