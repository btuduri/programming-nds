#pragma once

#include "FLib.h"

class FMusic
{
	mm_word music;

public:
	FMusic(mm_word music);
	~FMusic();
	void Play();
	void Pause();
	void Resume();
};

class FSoundEffect
{
	mm_word soundEffect;

public:
	FSoundEffect(mm_word soundEffect);
	~FSoundEffect();
	void Play();
};
