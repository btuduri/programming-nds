#include "FLib.h"

#ifndef _F_SOUND_EFFECT_
#define _F_SOUND_EFFECT_

class F_SoundEffect
{
	mm_word soundEffect;

public:
	F_SoundEffect(mm_word soundEffect);
	~F_SoundEffect();
	void Play();
};

#endif
