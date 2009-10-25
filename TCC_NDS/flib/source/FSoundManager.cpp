#include "FLib.h"

FMusic::FMusic(mm_word music)
{
	this->music = music;
	mmLoad(music);
}

FMusic::~FMusic()
{
	mmUnload(music);
}

void FMusic::Play()
{
	mmStart(music, MM_PLAY_LOOP);
}

void FMusic::Pause()
{
	mmPause();
}

void FMusic::Resume()
{
	mmResume();
}

FSoundEffect::FSoundEffect(mm_word soundEffect)
{
	this->soundEffect = soundEffect;
	mmLoadEffect(soundEffect);
}

FSoundEffect::~FSoundEffect()
{
	mmUnloadEffect(soundEffect);
}

void FSoundEffect::Play()
{
	mmEffect(soundEffect);
}
