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
	F_Console* mainConsole;
	F_Console* subConsole;

public:
	F_Main();

	F_Screen* GetMainScreen();
	F_Screen* GetSubScreen();
	F_Palette* GetMainBgPal();
	F_Palette* GetMainSpPal();
	F_Palette* GetSubBgPal();
	F_Palette* GetSubSpPal();
	F_InputManager* GetInputManager();
	F_Console* GetMainConsole();
	F_Console* GetSubConsole();

	void Init3D();
	void Update();
};

#endif
