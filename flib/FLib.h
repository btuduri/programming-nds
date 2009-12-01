#pragma once

#include <nds.h>
#include <maxmod9.h>

#include <stdio.h>
#include <string.h>

#include "soundbank.h"
#include "soundbank_bin.h"

#include "FMath.h"
#include "FSoundManager.h"
#include "FInputManager.h"
#include "FVideoManager.h"

class FLib
{
	FInputManager* inputManager;
	FVideoManager* videoManager;

public:
	FLib(bool is3D);

	FInputManager* GetInputManager();
	FVideoManager* GetVideoManager();
	void Update();
	void Wait(int time);
};