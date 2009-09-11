#include <nds.h>
#include <maxmod9.h>
#include <stdio.h>

#include "soundbank.h"
#include "soundbank_bin.h"

void draw(int x, int y, uint16 color)
{
	int p = y * SCREEN_WIDTH + x;
	int width  = 35;
	int height = 35;
	
	for (int i = 0; i < height; i++)
	{
		int q = p + SCREEN_WIDTH * i;
		for (int j = 0; j < width; j++)
			VRAM_A[q++] = color;
	}
}

volatile int x = 0;
volatile int y = 0;
volatile int old_x = 0;
volatile int old_y = 0;

int main()
{
	videoSetMode(MODE_FB0);
	vramSetBankA(VRAM_A_LCD);

	/* Carrega banco de sons para a memoria */
	mmInitDefaultMem((mm_addr)soundbank_bin);
	mmLoadEffect(SFX_BOOM);
	mmLoad(MOD_0);
	//mmLoad(MOD_120z);
	mmStart(MOD_0, MM_PLAY_LOOP);
	
	bool add_x = true;
	bool add_y = true;

	while (true)
	{
		draw(old_x, old_y, RGB15(0, 0, 0));
		draw(x, y, RGB15(31, 31, 31));
	
		if (!add_x && x <= 0)
		{
			add_x = true;
			mmEffect(SFX_BOOM);
		}
		else if (add_x && (x + 35) >= SCREEN_WIDTH)
		{
			add_x = false;
			mmEffect(SFX_BOOM);
		}
		
		if (!add_y && y <= 0)
		{
			add_y = true;
			mmEffect(SFX_BOOM);
		}
		else if (add_y && (y + 35) >= SCREEN_HEIGHT)
		{
			add_y = false;
			mmEffect(SFX_BOOM);
		}
	
		old_x = add_x ? x++ : x--;
		old_y = add_y ? y++ : y--;
		
		/* Espera a interrupcao VBLANK ocorrer */
		swiWaitForVBlank();
	}
	
	mmUnloadEffect(SFX_BOOM);
}
