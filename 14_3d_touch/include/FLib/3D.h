#ifndef _F_3D_
#define _F_3D_

#include "FLib.h"

void F_Init3D()
{
	videoSetMode(MODE_0_3D);
	glInit();
	glClearColor(0, 0, 0, 31);
	glPolyFmt(POLY_ALPHA(31) | POLY_CULL_NONE);
	glViewport(0, 0, 255, 191);
}

#endif