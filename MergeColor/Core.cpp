#include "Core.h"
#include "SceneManager.h"
#include "Console.h"

void Core::Run()
{
	char gameMapData[Map_HEIGHT][Map_WIDTH] =
	{
	"r1000r",
	"010111",
	"010000",
	"000010",
	"111010",
	"r0001r"
	};
	
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
	SetConsoleSettings(800, 400, false, L"Merge_Color");
	SetLockResize();
	SetCursorVisual(false, 50);
}


void Core::Update() 
{
	SceneManager::GetInst()->Update();
}

void Core::Render() 
{
	SceneManager::GetInst()->Render();
}
