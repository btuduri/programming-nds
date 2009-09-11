#include <nds.h>

void drawLine(int x1, int y1, int x2, int y2)
{
	int yStep = SCREEN_WIDTH;
	int xStep = 1;
	int xDiff = x2 - x1;
	int yDiff = y2 - y1;
	int errorTerm = 0;
	int offset = y1 * SCREEN_WIDTH + x1;
	int i;
	
	if (yDiff < 0)
	{
		yDiff = -yDiff;
		yStep = -yStep;
	}
	
	if (xDiff < 0)
	{
		xDiff = -xDiff;
		xStep = -xStep;
	}
	
	if (xDiff > yDiff)
	{
		for (i = 0; i < xDiff + 1; i++)
		{
			VRAM_A[offset] = RGB15(31, 31, 31);
			offset += xStep;
			errorTerm += yDiff;
			if (errorTerm > xDiff)
			{
				errorTerm -= xDiff;
				offset += yStep;
			}
		}
	}
	else
	{
		for (i = 0; i < yDiff + 1; i++)
		{
			VRAM_A[offset] = RGB15(31, 31, 31);
			offset += yStep;
			errorTerm += xDiff;
			if (errorTerm > yDiff)
			{
				errorTerm -= yDiff;
				offset += xStep;
			}
		}
	}
}


int main(void)
{
	touchPosition touch;

	videoSetMode(MODE_FB0);
	vramSetBankA(VRAM_A_LCD);
	
	lcdMainOnBottom();
	
	int old_x;
	int old_y;
	
	while(true)
	{
		swiWaitForVBlank();
		
		scanKeys();
		
		if (keysDown() & KEY_TOUCH)
		{
			touch = touchReadXY();
			old_x = touch.px;
			old_y = touch.py;
		}
		
		if (keysHeld() & KEY_TOUCH)
		{
			touch = touchReadXY();
			VRAM_A[touch.px + touch.py * SCREEN_WIDTH] = RGB15(31, 31, 31);
			drawLine(touch.px, touch.py, old_x, old_y);
			old_x = touch.px;
			old_y = touch.py;
		}
		
		if (keysUp() & ~KEY_TOUCH)
			for (int i = 0; i < SCREEN_HEIGHT * SCREEN_WIDTH; i++)
				VRAM_A[i] = RGB15(0, 0, 0);
	}
}
