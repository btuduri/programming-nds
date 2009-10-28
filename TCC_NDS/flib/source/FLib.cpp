#include "FLib.h"

FLib::FLib()
{
	mmInitDefaultMem((mm_addr)soundbank_bin);
	inputManager = new FInputManager();
	videoManager = new FVideoManager(inputManager);
}

FInputManager* FLib::GetInputManager()
{
	return inputManager;
}

FVideoManager* FLib::GetVideoManager()
{
	return videoManager;
}

void FLib::Update()
{
	swiWaitForVBlank();

	inputManager->Update();
	videoManager->Update();
}

void FLib::Wait(int time)
{
	while (time-- > 0)
		swiWaitForVBlank();
}
