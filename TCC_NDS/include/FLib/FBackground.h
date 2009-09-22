#include "FLib.h"

#ifndef _F_BACKGROUND_
#define _F_BACKGROUND_

class F_Background
{
	int id;
	int layer;

	u16 *tilemap;
	int map_base;
	int width, height;
	bool half_screen_x;
	bool half_screen_y;
	
	int x, y;
	int limit_x, limit_y;
	int screen_x, screen_y;
	bool infinite_scroll_x, infinite_scroll_y;

public:
	F_Background(u16 *tilemap, int width, int height)
	{
		this->tilemap = tilemap;
		this->width = width;
		this->height = height;
		
		map_base = 0;
		half_screen_x = true;
		half_screen_y = true;

		x = y = 0;
		screen_x = screen_y = 0;
		infinite_scroll_x = infinite_scroll_y = false;
		limit_x = width * 256 - 256;
		limit_y = height * 256 - 256;
	}

	void Load(int layer)
	{
		this->layer = layer;

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

		id = bgInit(layer, BgType_Text8bpp, size, layer * 4, 2);

		// Teste
		dmaCopy(&tilemap[Offset(map_base)], BG_MAP_RAM(layer*4), 2048);
		dmaCopy(&tilemap[Offset(map_base+1)], BG_MAP_RAM(layer*4+1), 2048);
		dmaCopy(&tilemap[Offset(map_base+width)], BG_MAP_RAM(layer*4+2), 2048);
		dmaCopy(&tilemap[Offset(map_base+width+1)], BG_MAP_RAM(layer*4+3), 2048);
	}

	void Scroll(int offset_x, int offset_y)
	{
		ScrollX(offset_x);
		ScrollY(offset_y);
	}

	void ScrollX(int offset_x)
	{
		// Incrementa coordenadas
		x += offset_x;
		screen_x += offset_x;

		// Ajusta tela no limite
		if (!infinite_scroll_x)
		{
			if (x > limit_x)
			{
				x = limit_x;
				if (screen_x > 512)
					screen_x = 512;
				else if (screen_x > 256)
					screen_x = 256;
			}
			else if (x < 0)
				x = screen_x = 0;
		}

		// Copia novos maps se necessário
		if (screen_x > 512)
		{
			map_base++;
			half_screen_x = true;
			screen_x -= 512;
			if (half_screen_y)
			{
				dmaCopy(&tilemap[Offset(map_base + 1)], BG_MAP_RAM(layer * 4 + 1), 2048);
				if (height > 1)
					dmaCopy(&tilemap[Offset(map_base + width + 1)], BG_MAP_RAM(layer * 4 + 3), 2048);
			}
			else
			{
				dmaCopy(&tilemap[Offset(map_base + width + 1)], BG_MAP_RAM(layer * 4 + 1), 2048);
				if (height > 1)
					dmaCopy(&tilemap[Offset(map_base + 1)], BG_MAP_RAM(layer * 4 + 3), 2048);
			}
		}
		else if (screen_x > 256 && half_screen_x)
		{
			map_base++;
			half_screen_x = false;
			if (half_screen_y)
			{
				dmaCopy(&tilemap[Offset(map_base + 1)], BG_MAP_RAM(layer * 4), 2048);
				if (height > 1)
					dmaCopy(&tilemap[Offset(map_base + width + 1)], BG_MAP_RAM(layer * 4 + 2), 2048);
			}
			else
			{
				dmaCopy(&tilemap[Offset(map_base + width + 1)], BG_MAP_RAM(layer * 4), 2048);
				if (height > 1)
					dmaCopy(&tilemap[Offset(map_base + 1)], BG_MAP_RAM(layer * 4 + 2), 2048);
			}
		}
		else if (screen_x < 0)
		{
			map_base--;
			half_screen_x = false;
			screen_x += 512;
			if (half_screen_y)
			{
				dmaCopy(&tilemap[Offset(map_base)], BG_MAP_RAM(layer * 4 + 1), 2048);
				if (height > 1)
					dmaCopy(&tilemap[Offset(map_base + width)], BG_MAP_RAM(layer * 4 + 3), 2048);
			}
			else
			{
				dmaCopy(&tilemap[Offset(map_base + width)], BG_MAP_RAM(layer * 4 + 1), 2048);
				if (height > 1)
					dmaCopy(&tilemap[Offset(map_base)], BG_MAP_RAM(layer * 4 + 3), 2048);
			}
		}
		else if (screen_x < 256 && !half_screen_x)
		{
			map_base--;
			half_screen_x = true;
			if (half_screen_y)
			{
				dmaCopy(&tilemap[Offset(map_base)], BG_MAP_RAM(layer * 4), 2048);
				if (height > 1)
					dmaCopy(&tilemap[Offset(map_base + width)], BG_MAP_RAM(layer * 4 + 2), 2048);
			}
			else
			{
				dmaCopy(&tilemap[Offset(map_base + width)], BG_MAP_RAM(layer * 4), 2048);
				if (height > 1)
					dmaCopy(&tilemap[Offset(map_base)], BG_MAP_RAM(layer * 4 + 2), 2048);
			}
		}

		bgSetScroll(id, screen_x, screen_y);
	}

	void ScrollY(int offset_y)
	{
		// Incrementa coordenadas
		y += offset_y;
		screen_y += offset_y;

		// Ajusta tela no limite
		if (!infinite_scroll_y)
		{
			if (y > limit_y)
			{
				y = limit_y;
				if (screen_y > 512)
					screen_y = 512;
				else if (screen_y > 256)
					screen_y = 256;
			}
			else if (y < 0)
				y = screen_y = 0;
		}

		// Copia novos maps se necessário
		if (screen_y > 512)
		{
			map_base += width;
			half_screen_y = true;
			screen_y -= 512;
			dmaCopy(&tilemap[Offset(map_base + width)], BG_MAP_RAM(layer * 4 + 2), 2048);
			if (width > 1)
				dmaCopy(&tilemap[Offset(map_base + width + 1)], BG_MAP_RAM(layer * 4 + 3), 2048);
		}
		else if (screen_y > 256 && half_screen_y)
		{
			map_base += width;
			half_screen_y = false;
			if (half_screen_x)
			{
				dmaCopy(&tilemap[Offset(map_base + width)], BG_MAP_RAM(layer * 4), 2048);
				if (width > 1)
					dmaCopy(&tilemap[Offset(map_base + width + 1)], BG_MAP_RAM(layer * 4 + 1), 2048);
			}
			else
			{
				dmaCopy(&tilemap[Offset(map_base + width + 1)], BG_MAP_RAM(layer * 4), 2048);
				if (width > 1)
					dmaCopy(&tilemap[Offset(map_base + width)], BG_MAP_RAM(layer * 4 + 1), 2048);
			}
		}
		else if (screen_y < 0)
		{
			map_base -= width;
			half_screen_y = false;
			screen_y += 512;
			if (half_screen_x)
			{
				dmaCopy(&tilemap[Offset(map_base)], BG_MAP_RAM(layer * 4 + 2), 2048);
				if (width > 1)
					dmaCopy(&tilemap[Offset(map_base + 1)], BG_MAP_RAM(layer * 4 + 3), 2048);
			}
			else
			{
				dmaCopy(&tilemap[Offset(map_base + 1)], BG_MAP_RAM(layer * 4 + 2), 2048);
				if (width > 1)
					dmaCopy(&tilemap[Offset(map_base)], BG_MAP_RAM(layer * 4 + 3), 2048);
			}
		}
		else if (screen_y < 256 && !half_screen_y)
		{
			map_base -= width;
			half_screen_y = true;
			if (half_screen_x)
			{
				dmaCopy(&tilemap[Offset(map_base)], BG_MAP_RAM(layer * 4), 2048);
				if (width > 1)
					dmaCopy(&tilemap[Offset(map_base + 1)], BG_MAP_RAM(layer * 4 + 1), 2048);
			}
			else
			{
				dmaCopy(&tilemap[Offset(map_base + 1)], BG_MAP_RAM(layer * 4), 2048);
				if (width > 1)
					dmaCopy(&tilemap[Offset(map_base)], BG_MAP_RAM(layer * 4 + 1), 2048);
			}
		}

		bgSetScroll(id, screen_x, screen_y);
	}

	void SetInfiniteScroll(bool infinite_scroll_x, bool infinite_scroll_y)
	{
		this->infinite_scroll_x = infinite_scroll_x;
		this->infinite_scroll_y = infinite_scroll_y;
	}

private:
	int Offset(int i)
	{
		return i * 1024;
	}
};

#endif