#include "FLib.h"

#ifndef _F_CONSOLE_
#define _F_CONSOLE_

class F_Console
{
	PrintConsole mainConsole;
	PrintConsole subConsole;

public:
	F_Console();

	void PrintMain();
	void PrintSub();
};

#endif