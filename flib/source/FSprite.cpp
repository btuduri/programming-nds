#include "FLib.h"

FSprite::FSprite(u8* gfx, int width, int height)
{
	this->gfx = gfx;
	size = width * height;
	x = y = 0;
	middle_x = width >> 1;
	middle_y = height >> 1;
	this->width = width;
	visible = false;

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

///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////

void FSprite::Load(bool main, int id)
{
	mainEngine = main;
	// Inicializa Sprite
	OamState *oam = main ? &oamMain : &oamSub;
	se = &(oam->oamMemory[id]);

	// Carrega frame para a memória
	frame = oamAllocateGfx(oam, ss, SpriteColorFormat_256Color);
	dmaCopy(gfx, frame, size);

	// Inicializa atributos do Sprite
	oamSet(oam, id, x, y, 0, 0, ss, SpriteColorFormat_256Color, frame, 0, false, false, false, false, false);
	visible = true;
}

///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////

void FSprite::SetXY(int x, int y)
{
	this->x = x - middle_x;
	this->y = y - middle_y;
	if (visible)
	{
		se->x = this->x;
		se->y = this->y;
	}
}

///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////

void FSprite::SetXYCorner(int x, int y)
{
	this->x = x;
	this->y = y;
	if (visible)
	{
		se->x = x;
		se->y = y;
	}
}

///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////

void FSprite::Center()
{
	x = 128 - middle_x;
	y = 96 - middle_y;
	if (visible)
	{
		se->x = x;
		se->y = y;
	}
}

///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////

void FSprite::Show()
{
	visible = true;
	se->x = x;
	se->y = y;
}

///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////

void FSprite::Hide()
{
	visible = false;
	se->x = 0 - width;
}

///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////

void FSprite::Remove()
{
	OamState *oam = mainEngine ? &oamMain : &oamSub;
	oamFreeGfx(oam, frame);
}

///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////

void FSprite::SetFrame(int frame)
{
	dmaCopy(gfx + frame * size, this->frame, size);
}

///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////

void FSprite::SetRotateId(int id)
{
	se->rotationIndex = id;
}

///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////

void FSprite::Rotate(int angle)
{
	OamState *oam = mainEngine ? &oamMain : &oamSub;
	oamRotateScale(oam, se->rotationIndex, angle, 1<<8, 1<<8);
}
