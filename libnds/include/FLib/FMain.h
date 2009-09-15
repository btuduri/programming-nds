#include "FLib.h"

#ifndef _F_MAIN_
#define _F_MAIN_

class F_Main
{
public:
	void Initialize()
	{
		consoleDemoInit();
		mmInitDefaultMem((mm_addr)soundbank_bin);
	}

	void MainLoop()
	{
	}
};

#endif
