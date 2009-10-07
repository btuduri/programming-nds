#include "FLib.h"

#ifndef _F_PALETTE_
#define _F_PALETTE_

enum PaletteType
{
	PaletteType_Main_Background,
	PaletteType_Sub_Background,
	PaletteType_Main_Sprite,
	PaletteType_Sub_Sprite
};

class F_Palette
{
	u16* palette;

public:
	/////////////////////////////////////////////////////////////
	// Construtor
	F_Palette(PaletteType paletteType)
	{
		switch(paletteType)
		{
			case PaletteType_Main_Background:
				palette = BG_PALETTE;
				break;
			case PaletteType_Sub_Background:
				palette = BG_PALETTE_SUB;
				break;
			case PaletteType_Main_Sprite:
				palette = SPRITE_PALETTE;
				break;
			case PaletteType_Sub_Sprite:
				palette = SPRITE_PALETTE_SUB;
				break;
		}
	}

	F_Palette(PaletteType paletteType, const void* memory)
	{
		switch(paletteType)
		{
			case PaletteType_Main_Background:
				palette = BG_PALETTE;
				break;
			case PaletteType_Sub_Background:
				palette = BG_PALETTE_SUB;
				break;
			case PaletteType_Main_Sprite:
				palette = SPRITE_PALETTE;
				break;
			case PaletteType_Sub_Sprite:
				palette = SPRITE_PALETTE_SUB;
				break;
		}

		Load(memory);
	}

	/////////////////////////////////////////////////////////////
	// 256 cores
	u16 GetColor(int index)
	{
		return palette[index];
	}

	void SetColor(int index, u16 color)
	{
		palette[index] = color;
	}

	void Load(const void* memory)
	{
		dmaCopy(memory, palette, 512);
	}

	/////////////////////////////////////////////////////////////
	// 16 cores
	u16 GetColor16(int paletteIndex, int colorIndex)
	{
		return palette[paletteIndex*16+colorIndex];
	}

	void SetColor16(int paletteIndex, int colorIndex, u16 color)
	{
		palette[paletteIndex*16+colorIndex] = color;
	}

	void Load16(int paletteIndex, u16* memory)
	{
		dmaCopy(memory, &palette[paletteIndex*16], 32);
	}
};

F_Palette* mainBgPal = new F_Palette(PaletteType_Main_Background);
F_Palette* mainSpPal = new F_Palette(PaletteType_Main_Sprite);
F_Palette* subBgPal = new F_Palette(PaletteType_Sub_Background);
F_Palette* subSpPal = new F_Palette(PaletteType_Sub_Sprite);

#endif
