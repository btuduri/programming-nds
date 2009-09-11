#include <PA9.h>
#include <maxmod9.h>

#include "soundbank.h"
#include "soundbank_bin.h"
#include "all_gfx.h"

enum StateName
{
	INITIAL_CREDITS,
	INTRODUCTION,
	MAIN_MENU,
	OPTIONS,
	LOAD_SAVE,
	GAME_LOOP,
	GAME_OVER,
	ENDING
};

struct State
{
	fp callback;
};

void teste()
{
	PA_Print(0, "All your base belong to us!\n\n");
}

void teste2()
{
	PA_Print(0, "Agora sim, agora tá bom!\n\n");
}


int main(int argc, char **argv)
{
	PA_Init();
	PA_InitVBL();

	mmInitDefaultMem((mm_addr)soundbank_bin);
	mmLoad(MOD_MUSIC);
	mmStart(MOD_MUSIC, MM_PLAY_LOOP);
	
	PA_InitText(0, 0);
	PA_Print(0, "Hello World!\n------------\n\n");
	
	
	State currentState[2];
	currentState[INITIAL_CREDITS].callback = teste;
	currentState[INITIAL_CREDITS].callback();
	currentState[INTRODUCTION].callback = teste2;
	currentState[INTRODUCTION].callback();
	
	PA_InitCustomText(1, 0, newfont);
	PA_InitTextBorders(1, 0, 16, 31, 24);
	
	while (true)
	{
		PA_ClearTextBg(1);
		PA_SimpleBoxText(1, "Estou aqui!", 30);
		
		PA_WaitForVBL();
	}
}
