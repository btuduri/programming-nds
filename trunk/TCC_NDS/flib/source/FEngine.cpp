#include "FLib.h"

FEngine::FEngine(bool mainEngine, FInputManager* im, FVideoManager* vm, bool is3D)
{
	this->im = im;
	this->vm = vm;
	this->mainEngine = mainEngine;
	console = new FConsole(mainEngine, is3D);
	if (mainEngine)
	{
		bgPalette = new FPalette(BG_PALETTE);
		spPalette = new FPalette(SPRITE_PALETTE);
	}
	else
	{
		bgPalette = new FPalette(BG_PALETTE_SUB);
		spPalette = new FPalette(SPRITE_PALETTE_SUB);
	}
}

///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////

FPalette* FEngine::GetBgPalette()
{
	return bgPalette;
}

///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////

FPalette* FEngine::GetSpPalette()
{
	return spPalette;
}

///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////

FConsole* FEngine::GetConsole()
{
	return console;
}

///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////

void FEngine::AddTileset(const void* tileset, int tilesetLen)
{
	if (mainEngine)
		dmaCopy(tileset, BG_TILE_RAM(3), tilesetLen);
	else
		dmaCopy(tileset, BG_TILE_RAM_SUB(3), tilesetLen);
}

///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////

void FEngine::SetScene(FScene* scene)
{
	//if (this->scene)
	//	delete this->scene;
	this->scene = scene;
	scene->Load(mainEngine, this, im, vm);
	scene->Load();
	oamUpdate(mainEngine ? &oamMain : &oamSub);
	bgUpdate();
}

///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////

void FEngine::Update()
{
	if (scene)
		scene->Update();
}

///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////

void FEngine::Hide()
{
	setBrightness(mainEngine ? 1 : 2, -16);
}

///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////

void FEngine::Show()
{
	setBrightness(mainEngine ? 1 : 2, 0);
}

///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////

void FEngine::FadeIn(int time)
{
	for (int i = -16; i <= 0; i++)
	{
		setBrightness(mainEngine ? 1 : 2, i);
		for (int j = 0; j < time; j++)
			swiWaitForVBlank();
	}
}

///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////

void FEngine::FadeOut(int time)
{
	for (int i = 0; i >= -16; i--)
	{
		setBrightness(mainEngine ? 1 : 2, i);
		for (int j = 0; j < time; j++)
			swiWaitForVBlank();
	}
}