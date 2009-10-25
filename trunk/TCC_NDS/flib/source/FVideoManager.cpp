#include "FLib.h"

// FPalette
/////////////////////////////////////////////////////////////////

FPalette::FPalette(u16* palette)
{
	this->palette = palette;
}

u16 FPalette::GetColor(int index)
{
	return palette[index];
}

void FPalette::SetColor(int index, u16 color)
{
	palette[index] = color;
}

void FPalette::Load(const void* memory)
{
	dmaCopy(memory, palette, 510);
}

// FEngine
/////////////////////////////////////////////////////////////////

FEngine::FEngine(bool mainEngine)
{
	this->mainEngine = mainEngine;
	console = new FConsole(mainEngine);
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

FPalette* FEngine::GetBgPalette()
{
	return bgPalette;
}

FPalette* FEngine::GetSpPalette()
{
	return spPalette;
}

FConsole* FEngine::GetConsole()
{
	return console;
}

void FEngine::AddTileset(const void* tileset, int tilesetLen)
{
	if (mainEngine)
		dmaCopy(tileset, BG_TILE_RAM(3), tilesetLen);
	else
		dmaCopy(tileset, BG_TILE_RAM_SUB(3), tilesetLen);
}

void FEngine::SetScene(FScene* scene)
{
	this->scene = scene;
	scene->Load(mainEngine);
}

void FEngine::Update()
{
	if (scene)
		scene->Update();
}

// FVideoManager
/////////////////////////////////////////////////////////////////

FVideoManager::FVideoManager()
{
	// Inicializa Gráfico
	videoSetMode(MODE_0_2D);
	videoSetModeSub(MODE_0_2D);

	// Inicializa Memória
	vramSetBankA(VRAM_A_MAIN_BG);
	vramSetBankB(VRAM_B_MAIN_SPRITE_0x06400000);
	vramSetBankC(VRAM_C_SUB_BG);
	vramSetBankD(VRAM_D_SUB_SPRITE);

	// Inicializa Sprites
	oamInit(&oamMain, SpriteMapping_1D_32, false);
	oamInit(&oamSub, SpriteMapping_1D_32, false);

	this->mainEngine = new FEngine(true);
	this->subEngine = new FEngine(false);
}

FEngine* FVideoManager::GetMainEngine()
{
	return mainEngine;
}

FEngine* FVideoManager::GetSubEngine()
{
	return subEngine;
}

void FVideoManager::Enable3D()
{
	// Inicializa Gráfico
	videoSetMode(MODE_0_3D);

	// Inicializa Opengl
	glInit();
	glClearColor(0, 0, 0, 0);
	glPolyFmt(POLY_ALPHA(31) | POLY_CULL_NONE);
	glViewport(0, 0, 255, 191);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(70, 256.0 / 192.0, 0.1, 100);	
	glMatrixMode(GL_MODELVIEW);
}

void FVideoManager::Update()
{
	mainEngine->Update();
	subEngine->Update();

	bgUpdate();
	
	oamUpdate(&oamMain);
	oamUpdate(&oamSub);
	
	glFlush(0);
}
