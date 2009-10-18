#pragma once

#include "FLib.h"

class F_Music
{
	mm_word music;

public:
	F_Music(mm_word music);
	~F_Music();
	void Play();
	void Pause();
	void Resume();
};
