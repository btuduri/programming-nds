#include "FLib.h"

#ifndef _F_SPRITE_
#define _F_SPRITE_

#define ANIM_LOOP 0
#define ANIM_UPDOWN 1
#define ANIM_ONESHOT ANIM_LOOP, 1
#define ANIM_INFINITE ANIM_LOOP, -1
#define MAX_SPRITE 128
#define NO_SPRITE -1

class F_Sprite
{
	int id;
	int framesCount;
	u16** frames;
	
	int currentFrame;
	int animationFrame;
	int framesPerAnimation;

	static bool allocSprite[MAX_SPRITE];

public:
	int x, y;

	F_Sprite(u8* gfx, int framesCount)
	{
		//oam = main ? &oamMain : &oamSub;
		//id = main ? spriteIdMain++ : spriteIdSub++;

		this->framesCount = framesCount;
		frames = (u16**)malloc(sizeof(u16*)*framesCount);
		for (int i = 0; i < framesCount; i++)
		{
			//frames[i] = oamAllocateGfx(oam, SpriteSize_32x32, SpriteColorFormat_256Color);
			dmaCopy(gfx, frames[i], 32*32);
			gfx += 32*32;
		}

		currentFrame = x = y = 0;
	}

	void SetXY(int x, int y)
	{
		this->x = x;
		this->y = y;
	}

	void AddFrame()
	{
		currentFrame++;
		if (currentFrame == framesCount)
			currentFrame = 0;
		//oamSet(oam, id, x, y, 0, 0, SpriteSize_32x32, SpriteColorFormat_256Color, frames[currentFrame], -1, false, false, false, false, false);
	}

	void Update()
	{
		//oamSet(oam, id, x, y, 0, 0, SpriteSize_32x32, SpriteColorFormat_256Color, frames[currentFrame], -1, false, false, false, false, false);
	}

private:
	int GetId()
	{
		for (int i = 0; i < MAX_SPRITE; i++)
			if (!allocSprite[i])
				return i;
		return NO_SPRITE;
	}
};

#endif