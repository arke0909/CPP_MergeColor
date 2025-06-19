#include "Core.h"
#include "KeyController.h"
#include "Console.h"
#include "GameScene.h"

void Core::Run()
{
	Scene curScene = Scene::TITLE;
	char gameMapData[Map_HEIGHT][Map_WIDTH] =
	{
		"r1000r",
"010111",
"010000",
"000010",
"111010",
"r0001r"
	};
	

	Init(gameMapData);

	while (true)
	{
		Update(gameMapData, inGameBlock);
		IsGotoxy(0, 0);
		Render(inGameBlock);
		FrameSync(60);
	}
}

void Core::Init(char gameMap[Map_HEIGHT][Map_WIDTH])
{
	SetConsoleSettings(800, 400, false, L"Merge_Color");
	SetLockResize();
	SetCursorVisual(false, 50);

	Reset(gameMap, inGameBlock);
}


void Core::Update(char gameMap[Map_HEIGHT][Map_WIDTH], Block inGameBlock[Map_HEIGHT][Map_WIDTH])
{
	static Key saveKey = Key::FAIL;

	bool isMoveEnd = !CheckEndMove(inGameBlock);

	if (isMoveEnd)
	{
		Key eKey = KeyController();
		saveKey = eKey;
	}

	cout << isMoveEnd;
	switch (saveKey)
	{
	case Key::UP:
		MoveUpdate(inGameBlock, false, -1);
		break;
	case Key::DOWN:
		MoveUpdate(inGameBlock, false, 1);
		break;
	case Key::LEFT:
		MoveUpdate(inGameBlock, true, -1);
		break;
	case Key::RIGHT:
		MoveUpdate(inGameBlock, true, 1);
		break;
	}

	if ((GetAsyncKeyState('R') & 0x8000) && isMoveEnd)
	{
		Reset(gameMap, inGameBlock);
	}
}

void Core::Render(Block inGameBlock[Map_HEIGHT][Map_WIDTH])
{
	MapRender(inGameBlock);
}
