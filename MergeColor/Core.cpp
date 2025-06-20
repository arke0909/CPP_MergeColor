#include "Core.h"
#include "SceneManager.h"
#include "Console.h"

void Core::Run()
{
	Init();

	while (true)
	{
		Update();
		IsGotoxy(0, 0);
		Render();
		FrameSync(60);
	}
}

void Core::Init()
{
	SetConsoleSettings(800, 600, false, L"Merge_Color");
	SetLockResize();
	SetCursorVisual(false, 50);
	SceneManager::GetInst()->Init();
}


void Core::Update() 
{
	SceneManager::GetInst()->Update();
}

void Core::Render() 
{
	SceneManager::GetInst()->Render();
}
