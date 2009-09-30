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

	int currentFrame;
	int animationFrame;
	int framesPerAnimation;

	SpriteEntry *se;

public:

	F_Sprite(u8* gfx, int framesCount)
	{
		this->gfx = gfx;
		this->framesCount = framesCount;
		currentFrame = 0;
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
			frames[i] = oamAllocateGfx(oam, SpriteSize_32x32, SpriteColorFormat_256Color);
			dmaCopy(gfx, frames[i], 1024);
			gfx += 1024;
		}

		// Inicializa atributos do Sprite
		oamSet(oam, id, 0, 0, 0, 0, SpriteSize_32x32, SpriteColorFormat_256Color, frames[0], 0, false, false, false, false, false);
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