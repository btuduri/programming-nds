#pragma once

#include "FLib.h"

class FPalette
{
	u16* palette;

public:
	FPalette(u16* palette);

	u16 GetColor(int index);
	void SetColor(int index, u16 color);
	void Load(const void* memory);
};
