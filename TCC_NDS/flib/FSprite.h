#pragma once

#include "FLib.h"

#define ANIM_LOOP 0
#define ANIM_UPDOWN 1
#define ANIM_ONESHOT ANIM_LOOP, 1
#define ANIM_INFINITE ANIM_LOOP, -1

class FSprite
{
	u8* gfx;
	int framesCount;
	u16** frames;
	int size;
	int x, y, width;
	int middle_x, middle_y;
	bool visible;

	int currentFrame;
	int animationFrame;
	int framesPerAnimation;

	SpriteSize ss;
	SpriteEntry *se;

public:

	FSprite(u8* gfx, int width, int height, int framesCount);
	void Load(bool main, int id);
	void SetXY(int x, int y);
	void SetXYCorner(int x, int y);
	void Center();
	void Show();
	void Hide();
	void AddFrame();
};
