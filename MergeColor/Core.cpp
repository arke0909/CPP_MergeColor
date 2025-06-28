#include "Core.h"
#include "GameManager.h"

void Core::Run()
{
	Init();

	while (GameManager::GetInst()->isRunning)
	{
		Update();
		IsGotoxy(0, 0);
		Render();
		FrameSync(60);
	}
	system("cls");
}

void Core::Init()
{
	SetConsoleSettings(800, 400, false, L"Merge_Color");
	SetLockResize();
	SetCursorVisual(false, 50);
	SceneManager::GetInst()->Init();
	SoundManager::GetInst()->PlayBGM();
}


void Core::Update() 
{
	SceneManager::GetInst()->Update();
}

void Core::Render() 
{
	SceneManager::GetInst()->Render();
}
