#ifndef _F_LIB_
#define _F_LIB_

#include <nds.h>
#include <maxmod9.h>
#include <stdio.h>

#include "soundbank.h"
#include "soundbank_bin.h"
#include "FMath.h"

#include "FBackground.h"
#include "FSprite.h"
#include "FScreen.h"

#include "FMusic.h"
#include "FSoundEffect.h"

#include "FInputManager.h"

void F_Init2D()
{
	// Inicializa Som
	mmInitDefaultMem((mm_addr)soundbank_bin);

	// Inicializa Gráfico
	videoSetMode(MODE_0_2D);
	videoSetModeSub(MODE_0_2D);

	// Inicializa Sprites
	oamInit(&oamMain, SpriteMapping_1D_32, false);
	oamInit(&oamSub, SpriteMapping_1D_32, false);
}

void F_Init3D()
{
	// Inicializa Som
	mmInitDefaultMem((mm_addr)soundbank_bin);

	// Inicializa Gráfico
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

void F_Update()
{
	swiWaitForVBlank();

	bgUpdate();
	oamUpdate(&oamMain);
	//oamUpdate(&oamSub);
	
	glFlush(0);	
	im.Update();
}

#endif