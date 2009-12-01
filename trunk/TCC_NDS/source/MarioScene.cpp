#include "main.h"

int scene = 0;

void MarioScene::Load()
{
	engine->GetBgPalette()->Load(marioPal);
	engine->GetSpPalette()->Load(spritesPal);
	engine->AddTileset(marioTiles, marioTilesLen);

	bg3 = new FBackground(mario_bg3Map, 2, 1);
	bg2 = new FBackground(mario_bg2Map, 2, 1);
	AddBackground(3, bg3, 0, 0);
	AddBackground(2, bg2, 0, 0);

	mario = new FSprite((u8*)mario_spTiles, 32, 32);
	AddSprite(mario);
	mario->SetXY(128, 145);

	timer = 0;
	frame = 0;
	parallax = 0;
}

void MarioScene::Update()
{
	bg3->InfiniteScroll(parallax + 1, 0);
	bg2->InfiniteScroll(2, 0);

	if (++timer == 6)
	{
		timer = 0;
		if (++frame == 3)
			frame = 0;
		mario->SetFrame(frame);
	}

	if (im->Pad.A.Pressed)
	{
		switch (scene)
		{
		case 0:
			bg3->Hide();
			bg2->Hide();
			break;
		case 1:
			bg3->Show();
			bg2->Show();
			mario->Hide();
			break;
		case 2:
			bg2->Hide();
			break;
		case 3:
			bg3->Hide();
			bg2->Show();
			break;
		case 4:
			parallax = 0;
			bg3->Show();
			mario->Show();
			break;
		case 5:
			parallax = 1;
			break;
		}
	}
}

void MarioSceneSub::Load()
{
	engine->GetConsole()->SetWindow(3, 3, 27, 2);
	engine->GetConsole()->Print("Cena de \"Super Mario World\"");
	engine->GetConsole()->Print("===========================");

	engine->GetConsole()->SetWindow(3, 8, 27, 10);
}

void MarioSceneSub::Update()
{
	if (im->Pad.A.Pressed)
	{
		switch (scene)
		{
		case 0:
			engine->GetConsole()->Print("Uma cena e' composta por:\n\n");
			engine->GetConsole()->Print("   - SPRITES\n");
			break;
		case 1:
			engine->GetConsole()->Clear();
			engine->GetConsole()->Print("Uma cena e' composta por:\n\n");
			engine->GetConsole()->Print("   - BACKGROUNDS\n");
			break;
		case 2:
			engine->GetConsole()->Clear();
			engine->GetConsole()->Print("Background \"2\"\n");
			engine->GetConsole()->Print("           ===\n\n\n");
			engine->GetConsole()->Print("Deslocamento de 1 pixel\npor quadro");
			break;
		case 3:
			engine->GetConsole()->Clear();
			engine->GetConsole()->Print("Background \"1\"\n");
			engine->GetConsole()->Print("           ===\n\n\n");
			engine->GetConsole()->Print("Deslocamento de 2 pixel\npor quadro");
			break;
		case 4:
			engine->GetConsole()->Clear();
			engine->GetConsole()->Print("Cena Completa\n");
			engine->GetConsole()->Print("=============\n\n\n\n");
			engine->GetConsole()->Print(" - Efeito paralax");
			break;
		case 5:
			engine->GetConsole()->Clear();
			engine->GetConsole()->Print("Cena Completa\n");
			engine->GetConsole()->Print("=============\n\n\n\n");
			engine->GetConsole()->Print(" - Sem efeito paralax");
			break;
		}

		scene++;
		if (scene == 6)
			scene = 4;
	}
}
