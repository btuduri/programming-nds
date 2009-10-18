#include "FLib.h"

F_Console::F_Console(bool mainEngine)
{
	this->mainEngine = mainEngine;
	consoleInit(&printConsole, mainEngine ? 1 : 0, BgType_Text4bpp, BgSize_T_256x256, 4, 2, mainEngine, true);
}

void F_Console::Print(const char* text)
{
	consoleSelect(&printConsole);
	printf(text);
}

void F_Console::Print(const char* text, int time)
{
	consoleSelect(&printConsole);
	consoleClear();	
	
	int textLen = strlen(text);
	char* textTemp = (char*)malloc(sizeof(char)*textLen);
	for (int textSize = 0; textSize < textLen; textSize++)
	{
		textTemp[textSize] = text[textSize];
		textTemp[textSize+1] = '\0';

		printConsole.cursorX = 0;
		printConsole.cursorY = 0;
		printf(textTemp);

		for (int wait = 0; wait < time; wait++)
			swiWaitForVBlank();
	}
}

void F_Console::Clear()
{
	consoleSelect(&printConsole);
	consoleClear();
}

void F_Console::ClearScreen()
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

void F_Console::SetColor(u16 color)
{
	if (mainEngine)
		BG_PALETTE[255] = color;
	else
		BG_PALETTE_SUB[255] = color;
}

void F_Console::SetCursorXY(int x, int y)
{
	printConsole.cursorX = x;
	printConsole.cursorY = y;
}

void F_Console::SetWindow(int x, int y, int width, int height)
{
	printConsole.cursorX = 0;
	printConsole.cursorY = 0;
	printConsole.windowX = x;
	printConsole.windowY = y;
	printConsole.windowWidth = width;
	printConsole.windowHeight = height;
}

int F_Console::GetCursorX()
{
	return printConsole.cursorX;
}

int F_Console::GetCursorY()
{
	return printConsole.cursorY;
}

int F_Console::GetWindowWidth()
{
	return printConsole.windowWidth;
}

int F_Console::GetWindowHeight()
{
	return printConsole.windowHeight;
}
