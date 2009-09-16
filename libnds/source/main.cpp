#include "FLib/FLib.h"
#include "man.h"
#include "woman.h"

int main(void)
{
	videoSetMode(MODE_0_2D);
	videoSetModeSub(MODE_0_2D);
	vramSetBankA(VRAM_A_MAIN_SPRITE);
	vramSetBankD(VRAM_D_SUB_SPRITE);
	dmaCopy(manPal, SPRITE_PALETTE, 512);
	dmaCopy(womanPal, SPRITE_PALETTE_SUB, 512);
	oamInit(&oamMain, SpriteMapping_1D_128, false);
	oamInit(&oamSub, SpriteMapping_1D_128, false);

	F_Sprite *s0 = new F_Sprite(true, (u8*)manTiles, 12);
	F_Sprite *s1 = new F_Sprite(false, (u8*)womanTiles, 12);
	F_Sprite *s2 = new F_Sprite(true, (u8*)manTiles, 12);
	F_Sprite *s3 = new F_Sprite(false, (u8*)womanTiles, 12);
	s2->SetXY(0, 31);
	s3->SetXY(0, 31);
	F_Sprite *s4 = new F_Sprite(true, (u8*)manTiles, 12);
	F_Sprite *s5 = new F_Sprite(false, (u8*)womanTiles, 12);
	s4->SetXY(31, 0);
	s5->SetXY(31, 0);
	F_Sprite *s6 = new F_Sprite(true, (u8*)manTiles, 12);
	F_Sprite *s7 = new F_Sprite(false, (u8*)womanTiles, 12);
	s6->SetXY(31, 31);
	s7->SetXY(31, 31);

	while(true)
	{
		scanKeys();
		if (keysDown() & KEY_RIGHT)
		{
			s0->AddFrame();
			s1->AddFrame();
			s2->AddFrame();
			s3->AddFrame();
			s4->AddFrame();
			s5->AddFrame();
			s6->AddFrame();
			s7->AddFrame();
		}
		oamUpdate(&oamMain);
		oamUpdate(&oamSub);
		swiWaitForVBlank();
	}
}
