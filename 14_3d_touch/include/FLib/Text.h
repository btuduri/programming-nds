#ifndef _F_TEXT_
#define _F_TEXT_

#include "FLib.h"

PrintConsole F_InitText(bool mainScreen, int layer)
{
	PrintConsole pc;
	consoleInit(&pc, layer, BgType_Text4bpp, BgSize_T_256x256, 31, 0, mainScreen, true);
	return pc;
}

#endif