#ifndef _F_SOUND_
#define _F_SOUND_

#include "FLib.h"
#include <maxmod9.h>

#include "soundbank.h"
#include "soundbank_bin.h"

void F_InitSound()
{
	mmInitDefaultMem((mm_addr)soundbank_bin);
}

#endif