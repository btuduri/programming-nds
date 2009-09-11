#include "Flib/FLib.h"
#include <stdio.h>

int main(void)
{
	videoSetMode(MODE_0_2D);	
	videoSetModeSub(MODE_0_2D);

	vramSetBankA(VRAM_A_MAIN_BG);
	vramSetBankC(VRAM_C_SUB_BG);

	PrintConsole bot = F_InitText(false, 0);
	PrintConsole top = F_InitText(true, 0);

	consoleSetWindow(&bot, 10, 5, 20, 10);

	while(true)
	{
		consoleSelect(&top);
		consoleClear();
		printf("Please, touch the screen!\n\n");
		printf("X: %d, Y: %d\n\n", F_Touch.X, F_Touch.Y);

		
		consoleSelect(&bot);		
		consoleClear();
		printf("Hello World...");

		F_WaitVblank();
	}
}
