#include <nds.h>
#include <filesystem.h>
#include <maxmod9.h>

#include <stdio.h>
#include "soundbank.h"
#include "soundbank_bin.h"

FILE *music;

mm_word read_music(mm_word length, mm_addr dest, mm_stream_formats format)
{
	s16* output = (s16*)dest;
    for(int len = length ; len > 0; len-- )
    {
		// Left and Right
		fread(output, sizeof(s16), 2, music);
		output += 2;
    }
	
	if (feof(music))
		rewind(music);
		
    return length;
}


int main(void)
{
	consoleDemoInit();
	nitroFSInit();
	mmInitDefaultMem((mm_addr)soundbank_bin);
	
	mm_stream ms;
	ms.sampling_rate = 8000;
	ms.buffer_length = 2048;
	ms.callback = read_music;
	ms.format = MM_STREAM_16BIT_STEREO;
	ms.timer = MM_TIMER0;
	ms.manual = false;
	
	mmStreamOpen(&ms);
	
	mmLoadEffect(SFX_BOOM);	
	
	music = fopen("/music.raw", "rb");
		
	while (true)
	{
		scanKeys();
		
		if (keysDown() & KEY_A)
			mmEffect(SFX_BOOM);
			
		consoleClear();
		printf("A - BOOM\n\n");
				
		swiWaitForVBlank();
	}
	
	
	return 0;
}
