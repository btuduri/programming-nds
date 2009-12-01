#pragma once

#include "FLib.h"
#include "backgrounds.h"
#include "sprites.h"

enum RunState
{
	INTRO, MARIO, RUNNING
};

extern RunState state;

#include "IntroScene.h"
#include "MarioScene.h"
#include "MainScene.h"
