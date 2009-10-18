#include "FLib.h"

F_Palette::F_Palette(PaletteType paletteType)
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

F_Palette::F_Palette(PaletteType paletteType, const void* memory)
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

u16 F_Palette::GetColor(int index)
{
	return palette[index];
}

void F_Palette::SetColor(int index, u16 color)
{
	palette[index] = color;
}

void F_Palette::Load(const void* memory)
{
	dmaCopy(memory, palette, 510);
}

u16 F_Palette::GetColor16(int paletteIndex, int colorIndex)
{
	return palette[paletteIndex*16+colorIndex];
}

void F_Palette::SetColor16(int paletteIndex, int colorIndex, u16 color)
{
	palette[paletteIndex*16+colorIndex] = color;
}

void F_Palette::Load16(int paletteIndex, u16* memory)
{
	dmaCopy(memory, &palette[paletteIndex*16], 32);
}
