#include "FLib.h"

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
