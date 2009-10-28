#pragma once

#include "FLib.h"

class FVideoManager;

class FEngine
{
	bool mainEngine;
	FPalette* bgPalette;
	FPalette* spPalette;
	FConsole* console;
	FScene* scene;
	FInputManager* im;
	FVideoManager* vm;

public:
	FEngine(bool mainEngine, FInputManager* im, FVideoManager* vm);

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
