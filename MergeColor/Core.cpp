#include "Core.h"
#include "KeyController.h"
#include "Console.h"
#include "GameLogic.h"

void Core::Run()
{
	Scene curScene = Scene::TITLE;
	char gameMap[Map_HEIGHT][Map_WIDTH] =
	{
		"0000r0",
		"p10010",
		"0o0000",
		"000b00",
		"01001g",
		"0y0000"
	};


	Init(gameMap);

	while (true)
	{
		Update(gameMap);
		IsGotoxy(0, 0);
		Render(gameMap);
		//FrameSync(60);
	}
}

void Core::Init(char gameMap[Map_HEIGHT][Map_WIDTH])
{
	SetConsoleSettings(800, 400, false, L"Merge_Color");
	SetCursorVisual(false, 50);
}


void Core::Update(char gameMap[Map_HEIGHT][Map_WIDTH])
{
	Key eKey = KeyController();

	switch (eKey)
	{
	case Key::UP:
		MoveUpdate(gameMap, false, -1);
		break;
	case Key::DOWN:
		MoveUpdate(gameMap, false, 1);
		break;
	case Key::LEFT:
		MoveUpdate(gameMap, true, -1);
		break;
	case Key::RIGHT:
		MoveUpdate(gameMap, true, 1);
		break;
	}
}

void Core::Render(char gameMap[Map_HEIGHT][Map_WIDTH])
{
	MapRender(gameMap);
}
