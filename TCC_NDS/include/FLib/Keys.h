#ifndef _F_KEYS_
#define _F_KEYS_

#include "FLib.h"

struct F_KeyState { bool Pressed, Released, Held; };
struct F_Keys { F_KeyState Up, Down, Left, Right, A, B, X, Y, L, R, Start, Select; };
struct F_LidState { bool Closed; };
struct F_TouchState { bool Pressed, Released, Held; u16 X, Y; };

F_Keys F_Pad;
F_LidState F_Lid;
F_TouchState F_Touch;

void F_UpdateKeys()
{
	scanKeys();
	int h = keysHeld();
	int u = keysUp();
	int d = keysDown();
	touchPosition tp;
	touchRead(&tp);

	F_Pad.Up.Held     = h & KEY_UP;
	F_Pad.Up.Pressed  = d & KEY_UP;
	F_Pad.Up.Released = u & KEY_UP;

	F_Pad.Down.Held     = h & KEY_DOWN;
	F_Pad.Down.Pressed  = d & KEY_DOWN;
	F_Pad.Down.Released = u & KEY_DOWN;

	F_Pad.Left.Held     = h & KEY_LEFT;
	F_Pad.Left.Pressed  = d & KEY_LEFT;
	F_Pad.Left.Released = u & KEY_LEFT;

	F_Pad.Right.Held     = h & KEY_RIGHT;
	F_Pad.Right.Pressed  = d & KEY_RIGHT;
	F_Pad.Right.Released = u & KEY_RIGHT;

	F_Pad.A.Held     = h & KEY_A;
	F_Pad.A.Pressed  = d & KEY_A;
	F_Pad.A.Released = u & KEY_A;

	F_Pad.B.Held     = h & KEY_B;
	F_Pad.B.Pressed  = d & KEY_B;
	F_Pad.B.Released = u & KEY_B;

	F_Pad.X.Held     = h & KEY_X;
	F_Pad.X.Pressed  = d & KEY_X;
	F_Pad.X.Released = u & KEY_X;

	F_Pad.Y.Held     = h & KEY_Y;
	F_Pad.Y.Pressed  = d & KEY_Y;
	F_Pad.Y.Released = u & KEY_Y;

	F_Pad.L.Held     = h & KEY_L;
	F_Pad.L.Pressed  = d & KEY_L;
	F_Pad.L.Released = u & KEY_L;

	F_Pad.R.Held     = h & KEY_R;
	F_Pad.R.Pressed  = d & KEY_R;
	F_Pad.R.Released = u & KEY_R;

	F_Pad.Start.Held     = h & KEY_START;
	F_Pad.Start.Pressed  = d & KEY_START;
	F_Pad.Start.Released = u & KEY_START;

	F_Pad.Select.Held     = h & KEY_SELECT;
	F_Pad.Select.Pressed  = d & KEY_SELECT;
	F_Pad.Select.Released = u & KEY_SELECT;

	F_Lid.Closed = d & KEY_LID;
	
	F_Touch.Held     = h & KEY_TOUCH;
	F_Touch.Pressed  = d & KEY_TOUCH;
	F_Touch.Released = u & KEY_TOUCH;
	F_Touch.X = tp.px;
	F_Touch.Y = tp.py;
}

#endif