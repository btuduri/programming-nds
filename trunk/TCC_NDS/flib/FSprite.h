#include "FLib.h"

#ifndef _F_SPRITE_
#define _F_SPRITE_

#define ANIM_LOOP 0
#define ANIM_UPDOWN 1
#define ANIM_ONESHOT ANIM_LOOP, 1
#define ANIM_INFINITE ANIM_LOOP, -1

class F_Sprite
{
	u8* gfx;
	int framesCount;
	u16** frames;
	int size;

	int currentFrame;
	int animationFrame;
	int framesPerAnimation;

	SpriteSize ss;
	SpriteEntry *se;

public:

	F_Sprite(u8* gfx, int width, int height, int framesCount);
	void Load(bool main, int id);
	void SetXY(int x, int y);
	void Center();
	void AddFrame();
};

#endif
