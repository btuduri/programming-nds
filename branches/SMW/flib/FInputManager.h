#pragma once

#include "FLib.h"

struct FPadState { bool Pressed, Released, Held; };
struct FPad { FPadState Up, Down, Left, Right, A, B, X, Y, L, R, Start, Select; };
struct FStylusState { bool Pressed, Released, Held; u16 X, Y; };

struct FInputManager
{
	bool Lid;
	FPad Pad;
	FStylusState Stylus;

	void Update();
};
