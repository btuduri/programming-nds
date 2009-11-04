#include "FLib.h"

FBackground::FBackground(const void* tilemap, int width, int height, bool is16c)
{
	this->width = width;
	this->height = height;
	this->tilemap = (u16*)tilemap;
	this->is16c = is16c;

	screen_x = screen_y = 0;
	limit_x = width * 256 - 256;
	limit_y = height * 256 - 256 + 64;
	alternate_x = alternate_y = false;
}

///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////

FBackground::~FBackground()
{
	bgHide(id);
}

///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////

void FBackground::Load(bool mainEngine, int layer, int init_x, int init_y)
{
	// Inicializa variáveis
	// --------------------
	ram_base = layer * 4;
	this->layer = layer;
	this->mainEngine = mainEngine;

	x = init_x;
	y = init_y;
	screen_x = x % 256;
	screen_y = y % 256;

	// Ajusta tela no limite
	// ---------------------
	bool adjust_x = false;

	if (width == 1 || x < 0)
		x = screen_x = 0;
	else if (x > limit_x)
	{
		x = limit_x;
		screen_x = 256;
		adjust_x = true;
	}

	if (y < 0)
		y = screen_y = 0;
	else if (y > limit_y)
	{
		y = limit_y;
		screen_y = 64;
	}
			
	// Inicializa background
	// ---------------------
	BgSize size;
	if (width == 1)
		if (height == 1)
			size = BgSize_T_256x256;
		else
			size = BgSize_T_256x512;
	else
		if (height == 1)
			size = BgSize_T_512x256;
		else
			size = BgSize_T_512x512;

	if (mainEngine)
		id = bgInit(layer, is16c ? BgType_Text4bpp : BgType_Text8bpp, size, ram_base, 3);
	else
		id = bgInitSub(layer, is16c ? BgType_Text4bpp : BgType_Text8bpp, size, ram_base, 3);

	// Copia mapas de memória
	// ----------------------
	map_base = ((y / 256) * width) + (x / 256);
	if (adjust_x) map_base--;

	dmaCopy(&tilemap[Offset(map_base)], BgMapRam(ram_base), 2048);
	dmaCopy(&tilemap[Offset(map_base + 1)], BgMapRam(ram_base + 1), 2048);
	dmaCopy(&tilemap[Offset(map_base + width)], BgMapRam(ram_base + 2), 2048);
	dmaCopy(&tilemap[Offset(map_base + width + 1)], BgMapRam(ram_base + 3), 2048);

	bgSetScroll(id, screen_x, screen_y);
}

///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////

void FBackground::Scroll(int offset_x, int offset_y)
{
	// Incrementa coordenadas
	// ----------------------
	x += offset_x;
	y += offset_y;
	screen_x += offset_x;		
	screen_y += offset_y;

	// Ajusta tela no limite
	// ---------------------
	if (x > limit_x)
	{
		x = limit_x;
		screen_x = 256;
	}
	else if (x < 0)
		x = screen_x = 0;

	if (y > limit_y)
	{
		y = limit_y;
		screen_y = 64;
	}
	else if (y < 0)
		y = screen_y = 0;
	
	// Copia mapas de memória
	// ----------------------
	if (screen_x > 256)
	{
		screen_x -= 256;
		map_base++;
		dmaCopy(&tilemap[Offset(map_base + (alternate_y * width) + 1)], BgMapRam(ram_base + alternate_x), 2048);
		dmaCopy(&tilemap[Offset(map_base + (!alternate_y * width) + 1)], BgMapRam(ram_base + 2 + alternate_x), 2048);
		alternate_x = !alternate_x;
	}
	else if (screen_x < 0)
	{
		screen_x += 256;
		map_base--;
		alternate_x = !alternate_x;
		dmaCopy(&tilemap[Offset(map_base + (alternate_y * width))], BgMapRam(ram_base + alternate_x), 2048);
		dmaCopy(&tilemap[Offset(map_base + (!alternate_y * width))], BgMapRam(ram_base + 2 + alternate_x), 2048);
	}
	
	if (screen_y > 256)
	{
		screen_y -= 256;
		map_base += width;
		dmaCopy(&tilemap[Offset(map_base + width + alternate_x)], BgMapRam(ram_base + (2 * alternate_y)), 2048);
		dmaCopy(&tilemap[Offset(map_base + width + !alternate_x)], BgMapRam(ram_base + (2 * alternate_y) + 1), 2048);
		alternate_y = !alternate_y;
	}
	else if (screen_y < 0)
	{
		screen_y += 256;
		map_base -= width;
		alternate_y = !alternate_y;
		dmaCopy(&tilemap[Offset(map_base + alternate_x)], BgMapRam(ram_base + (2 * alternate_y)), 2048);
		dmaCopy(&tilemap[Offset(map_base + !alternate_x)], BgMapRam(ram_base + (2 * alternate_y) + 1), 2048);
	}

	// Efetua o scroll
	// ---------------
	bgSetScroll(id, (alternate_x * 256) + screen_x, (alternate_y * 256) + screen_y);
}

///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////

void FBackground::InfiniteScroll(int offset_x, int offset_y)
{
	screen_x += offset_x;
	screen_y += offset_y;
	bgSetScroll(id, screen_x, screen_y);
}
