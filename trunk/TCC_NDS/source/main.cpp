#include "FLib/FLib.h"
#include "background.h"
#include "man.h"

int main(void)
{
	videoSetMode(MODE_0_2D);
	vramSetBankA(VRAM_A_MAIN_BG_0x06000000);
	vramSetBankB(VRAM_B_MAIN_SPRITE_0x06400000);
	oamInit(&oamMain, SpriteMapping_1D_32, false);

	mmInitDefaultMem((mm_addr)soundbank_bin);
	consoleDemoInit();

	F_Screen *screen = new F_Screen((u8*)backgroundTiles, backgroundTilesLen, (u16*)backgroundPal, (u16*)manPal);
	F_Background *bg = new F_Background((u16*)backgroundMap, 4, 4);
	F_Sprite *sprite = new F_Sprite((u8*)manTiles, 12);
		
	//F_Music *m = new F_Music(MOD_MUSIC);	
	//s->SetMusic(m);
	
	screen->AddBackground(0, bg, 0, 0);
	screen->AddSprite(sprite);

	sprite->Center();
	
	while(true)
	{
		scanKeys();
		if (keysHeld() & KEY_RIGHT)
		{
			bg->Scroll(4, 0);
		}
		else if (keysHeld() & KEY_LEFT)
		{
			bg->Scroll(-4, 0);
		}

		if (keysHeld() & KEY_UP)
		{
			bg->Scroll(0, -4);
		}
		else if (keysHeld() & KEY_DOWN)
		{
			bg->Scroll(0, 4);
		}

		if (keysDown() & KEY_A)
		{
			sprite->AddFrame();
		}
		
		bgUpdate();
		oamUpdate(&oamMain);
		swiWaitForVBlank();
	}
}
