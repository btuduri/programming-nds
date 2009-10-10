#include "FLib.h"

u64 F_Distance(s32 x1, s32 y1, s32 x2, s32 y2)
{
	s64 h = x1 - x2;
	s64 v = y1 - y2;
	return(h*h + v*v);
}

u16 F_AdjustAngle(u16 angle, s16 anglerot, s32 startx, s32 starty, s32 targetx, s32 targety)
{
	u64 distances[3];
	
	startx = startx << 8;
	starty = starty << 8;
	targetx = targetx << 8;
	targety = targety << 8;

	u16 tempangle = (angle - anglerot) & 511;

	distances[0] = F_Distance(startx + F_Cosine(tempangle), starty - F_Sine(tempangle), targetx, targety);
	tempangle += anglerot;
	tempangle &= 511;
	distances[1] = F_Distance(startx + F_Cosine(tempangle), starty - F_Sine(tempangle), targetx, targety);
	tempangle += anglerot;
	tempangle &= 511;
	distances[2] = F_Distance(startx + F_Cosine(tempangle), starty - F_Sine(tempangle), targetx, targety);

	if (distances[0] < distances[1])  angle -= anglerot;
	else if (distances[2] < distances[1])  angle += anglerot;

	return (angle&511);
}

u16 F_GetAngle(s32 startx, s32 starty, s32 targetx, s32 targety)
{
	u16 angle = 0;
	u16 anglerot = 180;

	while(anglerot > 5)
	{
		angle = F_AdjustAngle(angle, anglerot, startx, starty, targetx, targety);
		anglerot = (anglerot - ((3 * anglerot) >> 3));
	}

	anglerot = 4;
	angle = F_AdjustAngle(angle, anglerot, startx, starty, targetx, targety);
	anglerot = 2;
	angle = F_AdjustAngle(angle, anglerot, startx, starty, targetx, targety);
	anglerot = 1;
	angle = F_AdjustAngle(angle, anglerot, startx, starty, targetx, targety);

	return angle;
}

s16 F_CatmullRom(s16 p0, s16 p1, s16 p2, s16 p3, float t)
{
	return (s16)((p1 << 1) + (p2 - p0) * t + ((p0 << 1) - 5 * p1 + (p2 << 2) - p3) * t * t + (3 * p1 + p3 - p0 - 3 * p2) * t * t * t) >> 1;
}
