#pragma once

#include "FLib.h"

#define ANIM_LOOP 0
#define ANIM_UPDOWN 1
#define ANIM_ONESHOT ANIM_LOOP, 1
#define ANIM_INFINITE ANIM_LOOP, -1

class FSprite
{
	u8* gfx;
	u16* frame;
	int size;
	int x, y, width;
	int middle_x, middle_y;
	bool visible, mainEngine;

	SpriteSize ss;
	SpriteEntry *se;

public:

	FSprite(u8* gfx, int width, int height);
	void Load(bool main, int id);
	void SetXY(int x, int y);
	void SetXYCorner(int x, int y);
	void Center();
	void Show();
	void Hide();
	void Remove();
	void SetFrame(int frame);
	void SetRotateId(int id);
	void Rotate(int angle);
};
