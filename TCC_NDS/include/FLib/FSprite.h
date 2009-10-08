#include "FLib.h"

#ifndef _F_SPRITE_
#define _F_SPRITE_

#define ANIM_LOOP 0
#define ANIM_UPDOWN 1
#define ANIM_ONESHOT ANIM_LOOP, 1
#define ANIM_INFINITE ANIM_LOOP, -1

/*
	Sprites 32x32 256 cores
*/
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

	F_Sprite(u8* gfx, int width, int height, int framesCount)
	{
		this->gfx = gfx;
		this->framesCount = framesCount;
		currentFrame = 0;
		size = width * height;

		if (width == 8)
		{
			if (height == 8)
				ss = SpriteSize_8x8;
			else if (height == 16)
				ss = SpriteSize_8x16;
			else if (height == 32)
				ss = SpriteSize_8x32;
		}
		else if (width == 16)
		{
			if (height == 8)
				ss = SpriteSize_16x8;
			else if (height == 16)
				ss = SpriteSize_16x16;
			else if (height == 32)
				ss = SpriteSize_16x32;
		}
		else if (width == 32)
		{
			if (height == 8)
				ss = SpriteSize_32x8;
			else if (height == 16)
				ss = SpriteSize_32x16;
			else if (height == 32)
				ss = SpriteSize_32x32;
			else if (height == 64)
				ss = SpriteSize_32x64;
		}
		else if (width == 64)
		{
			if (height == 32)
				ss = SpriteSize_64x32;
			else if (height == 64)
				ss = SpriteSize_64x64;
		}
	}

	void Load(bool main, int id)
	{
		// Inicializa Sprite
		OamState *oam = main ? &oamMain : &oamSub;
		se = &(oam->oamMemory[id]);

		// Carrega frames para a memória
		frames = (u16**)malloc(sizeof(u16*)*framesCount);
		for (int i = 0; i < framesCount; i++)
		{
			frames[i] = oamAllocateGfx(oam, ss, SpriteColorFormat_256Color);
			dmaCopy(gfx, frames[i], size);
			gfx += size;
		}

		// Inicializa atributos do Sprite
		oamSet(oam, id, 0, 0, 0, 0, ss, SpriteColorFormat_256Color, frames[0], 0, false, false, false, false, false);
	}

	void SetXY(int x, int y)
	{
		se->x = x;
		se->y = y;
	}

	void Center()
	{
		se->x = 112;
		se->y = 80;
	}

	void AddFrame()
	{
		currentFrame++;
		if (currentFrame == framesCount)
			currentFrame = 0;
		se->gfxIndex = oamGfxPtrToOffset(frames[currentFrame]);
	}
};

#endif