#include "main.h"

void IntroScene::Load()
{
	engine->GetBgPalette()->Load(introPal);
	engine->AddTileset(introTiles, introTilesLen);
	AddBackground(3, new FBackground(ufrgsMap, 1, 1), 0, 0);
}

void IntroScene::Update()
{
	if (im->Pad.A.Pressed)
	{ }
}

void IntroSceneSub::Load()
{
	engine->GetBgPalette()->Load(introPal);
	engine->AddTileset(introTiles, introTilesLen);
	AddBackground(3, new FBackground(infMap, 1, 1), 0, 0);
}

void IntroSceneSub::Update()
{
	if (im->Pad.A.Pressed)
	{ }
}
