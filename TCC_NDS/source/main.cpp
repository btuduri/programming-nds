#include "FLib.h"
#include "MainScene.h"

int main(void)
{
	FLib* flib = new FLib();
	FEngine* me = flib->GetVideoManager()->GetMainEngine();
	FEngine* se = flib->GetVideoManager()->GetSubEngine();
	
	MainScene* s1 = new MainScene();
	me->SetScene(s1);

	MainScene* s2 = new MainScene();
	se->SetScene(s2);

	while(true)
		flib->Update();
}
