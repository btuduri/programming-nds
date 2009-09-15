#include "FLib/FLib.h"

int main(void)
{
	F_Main *fMain = new F_Main();
	fMain->Initialize();
	F_Music *fMusic = new F_Music(MOD_MUSIC);
	fMusic->Play();

	while(true);
}
