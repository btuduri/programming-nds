#pragma once

#include "FLib.h"

class F_Console
{
	PrintConsole printConsole;
	bool mainEngine;

public:
	F_Console(bool mainEngine);

	void Print(const char* text);
	void Print(const char* text, int time);
	void Clear();
	void ClearScreen();

	void SetColor(u16 color);
	void SetCursorXY(int x, int y);
	void SetWindow(int x, int y, int width, int height);

	int GetCursorX();
	int GetCursorY();
	int GetWindowWidth();
	int GetWindowHeight();
};
