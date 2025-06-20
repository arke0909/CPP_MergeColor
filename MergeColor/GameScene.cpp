#include "GameScene.h"

void GameScene::Init(char mapData[Map_HEIGHT][Map_WIDTH])
{
	for (int i = 0; i < Map_HEIGHT; ++i)
	{
		for (int j = 0; j < Map_WIDTH; ++j)
		{
			_originMapData[i][j] = mapData[i][j];
		}
	}
	systemManager.Reset(_originMapData, _inGameMap);
}

void GameScene::Update()
{
	static Key saveKey = Key::FAIL;

	bool isMoveEnd = !systemManager.CheckEndMove(_inGameMap);

	if (isMoveEnd)
	{
		Key eKey = KeyController();
		saveKey = eKey;
	}

	switch (saveKey)
	{
	case Key::UP:
		systemManager.MoveUpdate(_inGameMap, false, -1);
		break;
	case Key::DOWN:
		systemManager.MoveUpdate(_inGameMap, false, 1);
		break;
	case Key::LEFT:
		systemManager.MoveUpdate(_inGameMap, true, -1);
		break;
	case Key::RIGHT:
		systemManager.MoveUpdate(_inGameMap, true, 1);
		break;
	}


	if ((GetAsyncKeyState('R') & 0x8000) && isMoveEnd)
	{
		systemManager.Reset(_originMapData, _inGameMap);
	}
}

void GameScene::Render()
{
	for (int i = 0; i < Map_HEIGHT; ++i)
	{
		for (int j = 0; j < Map_WIDTH - 1; ++j)
		{
			_inGameMap[i][j].Render();
		}

		cout << '\n';
	}
	SetColor();
}
