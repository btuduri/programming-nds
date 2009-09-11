#ifndef _F_LIB_
#define _F_LIB_

#include <nds.h>
#include "3D.h"
#include "Drawing.h"
#include "Keys.h"
#include "Math.h"
#include "Sound.h"
#include "Text.h"

void F_Init()
{

}

void F_WaitVblank()
{
	glFlush(0);
	bgUpdate();

	F_UpdateKeys();
	swiWaitForVBlank();
}

#endif