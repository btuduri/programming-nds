#include <nds.h>
#include <stdio.h>

volatile int speed = 2;
volatile int size  = 35;
volatile int color = RGB15(31, 31, 31);
volatile int bgColor = RGB15(0, 0, 0);
volatile int x = 0;
volatile int y = 0;
volatile int old_x = 0;
volatile int old_y = 0;

void clearScreen()
{
	for (int i = 0; i < SCREEN_WIDTH * SCREEN_HEIGHT; i++)
		VRAM_A[i] = bgColor;
}

void drawSquare(int x, int y, uint16 color)
{
	int p = y * SCREEN_WIDTH + x;
	
	for (int i = 0; i < size; i++)
	{
		int q = p + SCREEN_WIDTH * i;
		for (int j = 0; j < size; j++)
			VRAM_A[q++] = color;
	}
}

int main(void)
{
	videoSetMode(MODE_FB0);
	vramSetBankA(VRAM_A_LCD);
	
	consoleDemoInit();
	bool closed = false;
	
	while (true)
	{
		/* Espera a interrupcao VBLANK ocorrer */
		swiWaitForVBlank();
		
		drawSquare(old_x, old_y, bgColor);
		drawSquare(x, y, color);
		
		old_x = x;
		old_y = y;
		
		/* Leitura dos botoes pressionados */
		scanKeys();
		int heldKeys     = keysHeld();
		int pressedKeys  = keysDown();
		int releasedKeys = keysUp();
		
		/* Direcionais */
		if (heldKeys &  KEY_UP)
		{
			y -= speed;
			if (y < 0) y = 0;
		}
		if (heldKeys &  KEY_DOWN)
		{
			y += speed;
			if (y + size > SCREEN_HEIGHT) y = SCREEN_HEIGHT - size;
		}
		if (heldKeys &  KEY_LEFT)
		{
			x -= speed;
			if (x < 0) x = 0;
		}
		if (heldKeys &  KEY_RIGHT)
		{
			x += speed;
			if (x + size > SCREEN_WIDTH) x = SCREEN_WIDTH - size;
		}
		
		/* A_B_X_Y_L_R */
		if (pressedKeys & KEY_A)
			color = RGB15(31, 0, 0);
		if (pressedKeys & KEY_B)
			color = RGB15(0, 31, 0);
		if (pressedKeys & KEY_X)
			color = RGB15(0, 0, 31);
		if (pressedKeys & KEY_Y)
			color = RGB15(31, 31, 0);
		if (pressedKeys & KEY_L)
			color = RGB15(31, 0, 31);
		if (pressedKeys & KEY_R)
			color = RGB15(0, 31, 31);
		
		if (releasedKeys)
			color = RGB15(31, 31, 31);
		
		/* Touch */
		if (pressedKeys & KEY_TOUCH)
			bgColor = RGB15(31, 31, 31);
		if (releasedKeys & KEY_TOUCH)
		{
			bgColor = RGB15(0, 0, 0);
			clearScreen();
		}
		
		if (pressedKeys & KEY_LID)
		{
			bgColor = RGB15(0, 0, 31);
			closed = true;
			clearScreen();
		}
		
		/* Imprime mensagens de teste */	
		consoleClear();
		printf("UP: %i\n", heldKeys & KEY_UP);
		printf("DOWN: %i\n", heldKeys & KEY_DOWN);
		printf("LEFT: %i\n", heldKeys & KEY_LEFT);
		printf("RIGHT: %i\n", heldKeys & KEY_RIGHT);
		
		printf("A: %i\n", heldKeys & KEY_A);
		printf("B: %i\n", heldKeys & KEY_B);
		printf("X: %i\n", heldKeys & KEY_X);
		printf("Y: %i\n", heldKeys & KEY_Y);
		
		printf("L: %i\n", heldKeys & KEY_L);
		printf("R: %i\n", heldKeys & KEY_R);
		printf("START: %i\n", heldKeys & KEY_START);
		printf("SELECT: %i\n", heldKeys & KEY_SELECT);
		
		printf("TOUCH: %i\n", heldKeys & KEY_TOUCH);
		printf("LID: %i\n", pressedKeys & KEY_LID);
		
		if (closed) printf("\n\nVoce ja fechou o DS!");
	}
		
	return 0;
}
