#include <PA9.h>
#include <maxmod9.h>

#include "all_gfx.h"
#include "soundbank.h"
#include "soundbank_bin.h"

int main(int argc, char **argv)
{
	PA_Init();
	PA_InitVBL();

	mmInitDefaultMem((mm_addr)soundbank_bin);
	mmLoad(MOD_MUSIC);
	mmStart(MOD_MUSIC, MM_PLAY_LOOP);
	
	PA_InitText(1, 2);
	PA_OutputSimpleText(1, 1, 2, "Hello World!");

	int x = 10;
	int y = 10;
	int dx = 1;
	int dy = 1;
	PA_LoadSpritePal(0, 0, (void *)cyborg_Pal);
	PA_CreateSprite(0, 2, (void *)cyborg_Sprite, OBJ_SIZE_32X32, COLORS_256, 0, 0, 0);
	PA_CreateSprite(0, 1, (void *)cyborg_Sprite, OBJ_SIZE_32X32, COLORS_256, 0, 16, 0);
	PA_CreateSprite(0, 0, (void *)cyborg_Sprite, OBJ_SIZE_32X32, COLORS_256, 0, 32, 0);

	//PA_SetSpriteRotEnable(0, 0, 0);
	//PA_SetRotsetNoZoom(0, 0, 90);
	//PA_SetRotsetNoAngle(0, 0, 128, 128);
	//PA_SetRotset(0, 0, 90, 128, 128);
	//PA_SetSpriteDblsize(0, 0, 1);

	PA_SetSpriteMode(0, 0, 1);
	PA_EnableSpecialFx(0, SFX_ALPHA, 0, SFX_BG0 | SFX_BG1 | SFX_BG2 | SFX_BG3 | SFX_BD);
	PA_SetSFXAlpha(0, 7, 15);

	PA_StartSpriteAnimEx(0, 0, 0, 2, 5, ANIM_UPDOWN, -1);
	PA_StartSpriteAnimEx(0, 1, 3, 5, 5, ANIM_UPDOWN, -1);
	PA_StartSpriteAnimEx(0, 2, 6, 8, 5, ANIM_UPDOWN, -1);

	//u16 angle = 0;
	//u16 zoom = 2048;

	while (true)
	{
		/*if (!PA_MoveSprite(0))
		{
			dx = dx ? !(++x > SCREEN_WIDTH - 16) : (--x < 0);
			dy = dy ? !(++y > SCREEN_HEIGHT - 32) : (--y < 0);
			PA_SetSpriteXY(0, 0, x, y);
		}
		else
		{
			x = PA_GetSpriteX(0, 0);
			y = PA_GetSpriteY(0, 0);
		}*/

		/*++angle;
		--zoom;
		angle &= 511;
		zoom &= 511;
		PA_SetRotsetNoZoom(0, 0, angle);
		PA_SetRotset(0, 0, angle, zoom, zoom);*/

		PA_WaitForVBL();
	}
	
	return 0;
}
