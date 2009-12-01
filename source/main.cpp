#include "main.h"

RunState state;

int main(void)
{
	FLib* flib = new FLib(false);	
	flib->GetVideoManager()->Hide();

	state = MARIO;

	while(true)
	{
		switch (state)
		{
		case INTRO:
			flib->GetVideoManager()->GetMainEngine()->SetScene(new IntroScene());
			flib->GetVideoManager()->GetSubEngine()->SetScene(new IntroSceneSub());
			flib->GetVideoManager()->FadeIn(5);
			state = RUNNING;
			break;
		case MARIO:
			flib->GetVideoManager()->GetMainEngine()->SetScene(new MarioScene());
			flib->GetVideoManager()->GetSubEngine()->SetScene(new MarioSceneSub());
			flib->GetVideoManager()->FadeIn(5);
			state = RUNNING;
			break;
		case RUNNING:
			flib->Update();
			break;
		}
	}
}
