#include "FLib.h"

FPalette::FPalette(u16* palette)
{
	this->palette = palette;
}

u16 FPalette::GetColor(int index)
{
	return palette[index];
}

void FPalette::SetColor(int index, u16 color)
{
	palette[index] = color;
}

void FPalette::Load(const void* memory)
{
	dmaCopy(memory, palette, 510);
}