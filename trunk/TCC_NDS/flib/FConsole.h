#include "FLib.h"

#ifndef _F_CONSOLE_
#define _F_CONSOLE_

class F_Console
{
	PrintConsole printConsole;

public:
	F_Console(bool mainEngine);

	void Print(const char* text);
	void Print(const char* text, int time);
	void SetCursorXY(int x, int y);
	void SetWindow(int x, int y, int width, int height);
	int GetCursorX();
	int GetCursorY();
	int GetWindowWidth();
	int GetWindowHeight();
};

#endif