#include "FLib.h"

#ifndef _F_MUSIC_
#define _F_MUSIC_

class F_Music
{
	mm_word music;

public:
	F_Music(mm_word music)
	{
		this->music = music;
		mmLoad(music);
	}

	~F_Music()
	{
		mmUnload(music);
	}

	void Play()
	{
		mmStart(music, MM_PLAY_LOOP);
	}

	void Pause()
	{
		mmPause();
	}

	void Resume()
	{
		mmResume();
	}
};

#endif
