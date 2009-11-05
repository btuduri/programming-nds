#include "FLib.h"
#include "MainScene.h"

int main(void)
{
	FLib* flib = new FLib(false);
	
	flib->GetVideoManager()->Hide();
	flib->GetVideoManager()->GetMainEngine()->SetScene(new MainScene());
	flib->GetVideoManager()->GetSubEngine()->SetScene(new MainScene());
	flib->GetVideoManager()->FadeIn(20);

	flib->GetVideoManager()->GetMainEngine()->GetConsole()->Type("Thiago Auler dos Santos\n", 5);
	flib->GetVideoManager()->GetMainEngine()->GetConsole()->Type("Thiago Auler dos Santos\n", 5);
	flib->GetVideoManager()->GetSubEngine()->GetConsole()->Type("Thiago Auler dos Santos\n", 5);
	flib->GetVideoManager()->GetSubEngine()->GetConsole()->Type("Thiago Auler dos Santos\n", 5);

	while(true)
		flib->Update();
}
