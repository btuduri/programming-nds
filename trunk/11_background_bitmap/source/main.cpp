#include <nds.h>

#include "ufrgs.h"
#include "inf.h"

int main(void)
{
	videoSetMode(MODE_3_2D);
	vramSetBankA(VRAM_A_MAIN_BG);
	bgInit(3, BgType_Bmp8, BgSize_B8_256x256, 0, 0);
	dmaCopy(ufrgsPal, BG_PALETTE, ufrgsPalLen);
	dmaCopy(ufrgsBitmap, BG_BMP_RAM(0), ufrgsBitmapLen);

	videoSetModeSub(MODE_5_2D);
	vramSetBankC(VRAM_C_SUB_BG);	
	bgInitSub(3, BgType_Bmp8, BgSize_B8_256x256, 0, 0);	
	dmaCopy(infPal, BG_PALETTE_SUB, infPalLen);
	dmaCopy(infBitmap, BG_BMP_RAM_SUB(0), infBitmapLen);

	return 0;
}
