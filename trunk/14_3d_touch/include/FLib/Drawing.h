#ifndef _F_DRAWING_
#define _F_DRAWING_

#include "FLib.h"

void F_DrawLine(u16 *buffer, s16 x1, s16 y1, s16 x2, s16 y2, rgb color)
{
	s16 xStep = 1;
	s16 yStep = SCREEN_WIDTH;
	s16 xDiff = x2 - x1;
	s16 yDiff = y2 - y1;
	s16 errorTerm = 0;
	s16 offset = y1 * SCREEN_WIDTH + x1;
	
	if (yDiff < 0)
	{
		yDiff = -yDiff;
		yStep = -yStep;
	}
	
	if (xDiff < 0)
	{
		xDiff = -xDiff;
		xStep = -xStep;
	}
	
	if (xDiff > yDiff)
	{
		for (u16 i = 0; i < xDiff + 1; i++)
		{
			buffer[offset] = color;
			offset += xStep;
			errorTerm += yDiff;
			if (errorTerm > xDiff)
			{
				errorTerm -= xDiff;
				offset += yStep;
			}
		}
	}
	else
	{
		for (u16 i = 0; i < yDiff + 1; i++)
		{
			buffer[offset] = color;
			offset += yStep;
			errorTerm += xDiff;
			if (errorTerm > yDiff)
			{
				errorTerm -= yDiff;
				offset += xStep;
			}
		}
	}
}

#endif