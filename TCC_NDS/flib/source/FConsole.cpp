#include <cstdarg>
#include "FLib.h"

FConsole::FConsole(bool mainEngine, bool is3D)
{
	this->mainEngine = mainEngine;
	consoleInit(&printConsole, (mainEngine && is3D) ? 1 : 0, BgType_Text4bpp, BgSize_T_256x256, 4, 2, mainEngine, true);
}

///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////

void FConsole::Print(const char* text)
{
	//va_list args;
	consoleSelect(&printConsole);
	printf(text);//, args);
}

///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////

void FConsole::Type(const char* text, int time)
{
	//va_list args;
	consoleSelect(&printConsole);
	consoleClear();	
	
	//char* newText;
	//sprintf(newText, text, args);
	int textLen = strlen(text);//newText);
	char* textTemp = (char*)malloc(sizeof(char)*textLen);
	for (int textSize = 0; textSize < textLen; textSize++)
	{
		textTemp[textSize] = text[textSize]; //newText[textSize];
		textTemp[textSize+1] = '\0';

		printConsole.cursorX = 0;
		printConsole.cursorY = 0;
		printf(textTemp);

		for (int wait = 0; wait < time; wait++)
			swiWaitForVBlank();
	}

	//free(newText);
	free(textTemp);
}

///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////

void FConsole::Clear()
{
	consoleSelect(&printConsole);
	consoleClear();
}

///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////

void FConsole::ClearScreen()
{
	consoleSelect(&printConsole);
	int x = printConsole.windowX;
	int y = printConsole.windowY;
	int width = printConsole.windowWidth;
	int height = printConsole.windowHeight;

	printConsole.windowX = 0;
	printConsole.windowY = 0;
	printConsole.windowWidth = 32;
	printConsole.windowHeight = 32;
	
	consoleClear();

	printConsole.windowX = x;
	printConsole.windowY = y;
	printConsole.windowWidth = width;
	printConsole.windowHeight = height;
}

///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////

void FConsole::SetColor(u16 color)
{
	if (mainEngine)
		BG_PALETTE[255] = color;
	else
		BG_PALETTE_SUB[255] = color;
}

///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////

void FConsole::SetCursorXY(int x, int y)
{
	printConsole.cursorX = x;
	printConsole.cursorY = y;
}

///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////

void FConsole::SetWindow(int x, int y, int width, int height)
{
	printConsole.cursorX = 0;
	printConsole.cursorY = 0;
	printConsole.windowX = x;
	printConsole.windowY = y;
	printConsole.windowWidth = width;
	printConsole.windowHeight = height;
}
