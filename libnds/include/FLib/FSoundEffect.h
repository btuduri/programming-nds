#include "FLib.h"

#ifndef _F_SOUND_EFFECT_
#define _F_SOUND_EFFECT_

int sfxLoaded[MSL_NSAMPS];

class F_SoundEffect
{
	mm_word soundEffect;

public:
	F_SoundEffect(mm_word soundEffect)
	{
		this->soundEffect = soundEffect;
		if (sfxLoaded[soundEffect]++ == 0)
			mmLoadEffect(soundEffect);
	}

	~F_SoundEffect()
	{
		if (sfxLoaded[soundEffect]-- == 1)
			mmUnloadEffect(soundEffect);
	}

	void Play()
	{
		mmEffect(soundEffect);
	}
};

#endif
