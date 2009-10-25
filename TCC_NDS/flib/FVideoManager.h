#pragma once

#include "FLib.h"
#include "FBackground.h"
#include "FSprite.h"
#include "FConsole.h"
#include "FScene.h"

// FPalette
/////////////////////////////////////////////////////////////////

class FPalette
{
	u16* palette;

public:
	FPalette(u16* palette);

	u16 GetColor(int index);
	void SetColor(int index, u16 color);
	void Load(const void* memory);
};

// FEngine
/////////////////////////////////////////////////////////////////

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
};

// FVideoManager
/////////////////////////////////////////////////////////////////

class FVideoManager
{
	FEngine* mainEngine;
	FEngine* subEngine;

public:
	FVideoManager();

	FEngine* GetMainEngine();
	FEngine* GetSubEngine();
	void Enable3D();
	void Update();
};
	