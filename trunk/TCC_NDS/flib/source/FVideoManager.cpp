#include "FLib.h"

FVideoManager::FVideoManager(FInputManager* im)
{
	this->im = im;
	// Inicializa Gr�fico
	videoSetMode(MODE_0_2D);
	videoSetModeSub(MODE_0_2D);

	// Inicializa Mem�ria
	vramSetBankA(VRAM_A_MAIN_BG);
	vramSetBankB(VRAM_B_MAIN_SPRITE_0x06400000);
	vramSetBankC(VRAM_C_SUB_BG);
	vramSetBankD(VRAM_D_SUB_SPRITE);

	// Inicializa Sprites
	oamInit(&oamMain, SpriteMapping_1D_32, false);
	oamInit(&oamSub, SpriteMapping_1D_32, false);

	this->mainEngine = new FEngine(true, im, this);
	this->subEngine = new FEngine(false, im, this);
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
	// Inicializa Gr�fico
	videoSetMode(MODE_0_3D);
	oamInit(&oamMain, SpriteMapping_1D_32, false);

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

void FVideoManager::Hide()
{
	setBrightness(3, -16);
}

void FVideoManager::Show()
{
	setBrightness(3, 0);
}

void FVideoManager::FadeIn(int time)
{
	for (int i = -16; i <= 0; i++)
	{
		setBrightness(3, i);
		for (int j = 0; j < time; j++)
			swiWaitForVBlank();
	}
}

void FVideoManager::FadeOut(int time)
{
	for (int i = 0; i >= -16; i--)
	{
		setBrightness(3, i);
		for (int j = 0; j < time; j++)
			swiWaitForVBlank();
	}
}

void FVideoManager::SwapScreens()
{
	lcdSwap();
}
