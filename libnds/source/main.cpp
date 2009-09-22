#include "FLib/FLib.h"
#include "background.h"

int main(void)
{
	videoSetMode(MODE_0_2D);
	vramSetBankA(VRAM_A_MAIN_BG);

	mmInitDefaultMem((mm_addr)soundbank_bin);

	consoleDemoInit();

	F_Stage *s = new F_Stage((u8*)backgroundTiles, backgroundTilesLen, (u16*)backgroundPal, backgroundPalLen);
	F_Background *b = new F_Background((u16*)backgroundMap, 4, 4);
	F_Music *m = new F_Music(MOD_MUSIC);
	
	s->SetMusic(m);
	s->AddBackground(0, b, 4);

	while(true)
	{
		scanKeys();
		if (keysHeld() & KEY_RIGHT)
		{
			b->ScrollX(4);
		}
		else if (keysHeld() & KEY_LEFT)
		{
			b->ScrollX(-4);
		}

		if (keysHeld() & KEY_UP)
		{
			b->Scroll(0, -4);
		}
		else if (keysHeld() & KEY_DOWN)
		{
			b->Scroll(0, 4);
		}		
		
		bgUpdate();
		swiWaitForVBlank();
	}
}
