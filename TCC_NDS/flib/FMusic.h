#include "FLib.h"

#ifndef _F_MUSIC_
#define _F_MUSIC_

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

#endif
