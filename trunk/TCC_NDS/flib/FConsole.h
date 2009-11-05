#pragma once

#include "FLib.h"

class FConsole
{
	PrintConsole printConsole;
	bool mainEngine;

public:
	FConsole(bool mainEngine, bool is3D);

	void Print(const char* text, ...);
	void Type(const char* text, int time, ...);
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
