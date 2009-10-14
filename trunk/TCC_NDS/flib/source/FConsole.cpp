#include "FLib.h"

F_Console::F_Console()
{
	consoleInit(&mainConsole, 1, BgType_Text4bpp, BgSize_T_256x256, 4, 2, true, true);
	consoleInit(&subConsole, 0, BgType_Text4bpp, BgSize_T_256x256, 4, 2, false, true);
}

void F_Console::PrintMain()
{
	consoleSelect(&mainConsole);
	printf("Hello world on the main screen!");
}

void F_Console::PrintSub()
{
	consoleSelect(&subConsole);
	printf("Hello world on the sub screen!");
}

