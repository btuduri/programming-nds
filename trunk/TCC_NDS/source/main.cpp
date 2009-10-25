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

	FConsole *sc = se->GetConsole();
	sc->SetWindow(5, 5, 16, 3);
	sc->Print("Hello world diretamente da engine secundaria...", 20);
	
	while(true)
		flib->Update();
}
