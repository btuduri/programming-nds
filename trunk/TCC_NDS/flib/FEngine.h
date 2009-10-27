#pragma once

#include "FLib.h"

class FEngine
{
	bool mainEngine;
	FPalette* bgPalette;
	FPalette* spPalette;
	FConsole* console;
	FScene* scene;

public:
	FEngine(bool mainEngine);

	FPalette* GetBgPalette();
	FPalette* GetSpPalette();
	FConsole* GetConsole();
	void AddTileset(const void* tileset, int tilesetLen);
	void SetScene(FScene* scene);
	void Update();
	void Hide();
	void Show();
	void FadeIn(int time);
	void FadeOut(int time);
};
