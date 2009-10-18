#pragma once

#include "FLib.h"

class F_SoundEffect
{
	mm_word soundEffect;

public:
	F_SoundEffect(mm_word soundEffect);
	~F_SoundEffect();
	void Play();
};
