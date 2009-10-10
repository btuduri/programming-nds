#include "FLib.h"

F_SoundEffect::F_SoundEffect(mm_word soundEffect)
{
	this->soundEffect = soundEffect;
	mmLoadEffect(soundEffect);
}

F_SoundEffect::~F_SoundEffect()
{
	mmUnloadEffect(soundEffect);
}

void F_SoundEffect::Play()
{
	mmEffect(soundEffect);
}
