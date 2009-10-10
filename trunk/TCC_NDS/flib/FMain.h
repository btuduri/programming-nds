#include "FLib.h"

#ifndef _F_MAIN_
#define _F_MAIN_

class F_Main
{
	F_InputManager inputManager;
	F_Screen* mainScreen;
	F_Screen* subScreen;
	F_Palette* mainBgPal;
	F_Palette* mainSpPal;
	F_Palette* subBgPal;
	F_Palette* subSpPal;

public:
	F_Main();

	F_Screen* GetMainScreen();
	F_Screen* GetSubScreen();
	F_Palette* GetMainBgPal();
	F_Palette* GetMainSpPal();
	F_Palette* GetSubBgPal();
	F_Palette* GetSubSpPal();
	F_InputManager* GetInputManager();

	void F_Init2D();
	void F_Init3D();
	void F_Update();
};

#endif
