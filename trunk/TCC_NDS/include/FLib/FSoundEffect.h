#include "FLib.h"

#ifndef _F_SOUND_EFFECT_
#define _F_SOUND_EFFECT_

class F_SoundEffect
{
	mm_word soundEffect;

public:
	F_SoundEffect(mm_word soundEffect)
	{
		this->soundEffect = soundEffect;
		mmLoadEffect(soundEffect);
	}

	~F_SoundEffect()
	{
		mmUnloadEffect(soundEffect);
	}

	void Play()
	{
		mmEffect(soundEffect);
	}
};

#endif
