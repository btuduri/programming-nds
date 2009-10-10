#include "FLib.h"

F_Music::F_Music(mm_word music)
{
	this->music = music;
	mmLoad(music);
}

F_Music::~F_Music()
{
	mmUnload(music);
}

void F_Music::Play()
{
	mmStart(music, MM_PLAY_LOOP);
}

void F_Music::Pause()
{
	mmPause();
}

void F_Music::Resume()
{
	mmResume();
}
