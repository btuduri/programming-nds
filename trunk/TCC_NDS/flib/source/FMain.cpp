#include "FLib.h"

F_Main::F_Main()
{
	mainScreen = new F_Screen(true);
	subScreen  = new F_Screen(false);
	mainBgPal  = new F_Palette(PaletteType_Main_Background);
	mainSpPal  = new F_Palette(PaletteType_Main_Sprite);
	subBgPal   = new F_Palette(PaletteType_Sub_Background);
	subSpPal   = new F_Palette(PaletteType_Sub_Sprite);
}

F_Screen* F_Main::GetMainScreen()
{
	return mainScreen;
}

F_Screen* F_Main::GetSubScreen()
{
	return subScreen;
}

F_Palette* F_Main::GetMainBgPal()
{
	return mainBgPal;
}

F_Palette* F_Main::GetMainSpPal()
{
	return mainSpPal;
}

F_Palette* F_Main::GetSubBgPal()
{
	return subBgPal;
}

F_Palette* F_Main::GetSubSpPal()
{
	return subSpPal;
}

F_InputManager* F_Main::GetInputManager()
{
	return &inputManager;
}

void F_Main::F_Init2D()
{
	// Inicializa Som
	mmInitDefaultMem((mm_addr)soundbank_bin);

	// Inicializa Gr�fico
	videoSetMode(MODE_0_2D);
	videoSetModeSub(MODE_0_2D);

	// Inicializa Mem�ria
	vramSetMainBanks(VRAM_A_MAIN_BG, VRAM_B_MAIN_SPRITE_0x06400000, VRAM_C_SUB_BG, VRAM_D_SUB_SPRITE);

	// Inicializa Sprites
	oamInit(&oamMain, SpriteMapping_1D_32, false);
	oamInit(&oamSub, SpriteMapping_1D_32, false);
}

void F_Main::F_Init3D()
{
	// Inicializa Som
	mmInitDefaultMem((mm_addr)soundbank_bin);

	// Inicializa Gr�fico
	videoSetMode(MODE_0_3D);
	//videoSetModeSub(MODE_0_2D);

	// Inicializa Sprites
	oamInit(&oamMain, SpriteMapping_1D_32, false);
	//oamInit(&oamSub, SpriteMapping_1D_32, false);

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

void F_Main::F_Update()
{
	swiWaitForVBlank();

	bgUpdate();
	oamUpdate(&oamMain);
	//oamUpdate(&oamSub);
	
	glFlush(0);

	inputManager.Update();
}