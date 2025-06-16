#include "Core.h"
#include "KeyController.h"
#include "Console.h"
#include "GameLogic.h"

void Core::Run()
{
	Scene curScene = Scene::TITLE;
	char gameMapData[Map_HEIGHT][Map_WIDTH] =
	{
		"0000rr",
		"p10010",
		"0o0000",
		"000b00",
		"01001g",
		"0y0000"
	};
	Block inGameBlock[Map_HEIGHT][Map_WIDTH]
	{};

	Init(gameMapData, inGameBlock);

	while (true)
	{
		Update(inGameBlock);
		IsGotoxy(0, 0);
		Render(inGameBlock);
		FrameSync(60);
	}
}

void Core::Init(char gameMap[Map_HEIGHT][Map_WIDTH], Block inGameBlock[Map_HEIGHT][Map_WIDTH])
{
	SetConsoleSettings(800, 400, false, L"Merge_Color");
	SetLockResize();
	SetCursorVisual(false, 50);

	for (int i = 0; i < Map_HEIGHT; ++i)
	{
		for (int j = 0; j < Map_WIDTH; ++j)
		{
			inGameBlock[i][j] = Block{(BlockType)gameMap[i][j], false};
		}
	}
}


void Core::Update(Block inGameBlock[Map_HEIGHT][Map_WIDTH])
{


	return;
	Key eKey = KeyController();
	static Key saveKey = Key::FAIL;

	if (!CheckEndMove(inGameBlock))
	{
		saveKey = eKey;
	}
	cout << !CheckEndMove(inGameBlock);
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
}

void Core::Render(Block inGameBlock[Map_HEIGHT][Map_WIDTH])
{
	MapRender(inGameBlock);
}
