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
	F_Palette(PaletteType paletteType);
	F_Palette(PaletteType paletteType, const void* memory);
	u16 GetColor(int index);
	void SetColor(int index, u16 color);
	void Load(const void* memory);
	u16 GetColor16(int paletteIndex, int colorIndex);
	void SetColor16(int paletteIndex, int colorIndex, u16 color);
	void Load16(int paletteIndex, u16* memory);
};

#endif
