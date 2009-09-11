#include <nds.h>
#include <stdio.h>

int main(void)
{
	int i, j;
	
	/* Ajusta modo console (nao usado em jogos) */
	consoleDemoInit();
	
	printf("Alo, mundo!\n\n");
	printf("Thiago Auler dos Santos\n\n");
	printf("Imprimindo barras verticais RGB!");
	
	/* Imprimir na posicao \x1b[linha;colunaH */
	printf("\x1b[10;5HPrint Posicionado!!!");
	
	/* Imprime na tela diretamente da memoria */
	videoSetMode(MODE_FB0);
	vramSetBankA(VRAM_A_LCD);

	for (i = 0; i < SCREEN_HEIGHT; i++)
	{
		for (j = 0; j < 85; j++) VRAM_A[i * SCREEN_WIDTH + j] = RGB15(31, 0, 0);
		for (j = 85; j < 170; j++) VRAM_A[i * SCREEN_WIDTH + j] = RGB15(0, 31, 0);
		for (j = 170; j < 256; j++) VRAM_A[i * SCREEN_WIDTH + j] = RGB15(0, 0, 31);
	}	
	
	return 0;
}
