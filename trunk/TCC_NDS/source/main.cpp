#include "FLib.h"
#include "MainScene.h"

int main(void)
{
	FLib* flib = new FLib();
	FInputManager* im = flib->GetInputManager();
	FEngine* me = flib->GetVideoManager()->GetMainEngine();
	FEngine* se = flib->GetVideoManager()->GetSubEngine();

	me->GetBgPalette()->Load(backgroundsPal);
	me->GetSpPalette()->Load(spritesPal);
	me->AddTileset(backgroundTiles, backgroundTilesLen);

	MainScene* s = new MainScene(im);
	me->SetScene(s);

	me->FadeOut(30);
	flib->Wait(10);
	me->FadeIn(30);

	while(true)
		flib->Update();
}
