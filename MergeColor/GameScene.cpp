#include "GameScene.h"
#include <iomanip>

void GameScene::Update(GameData gameData)
{
	if (dataId != gameData.dataId)
	{
		isClear = false;
		dataId = gameData.dataId;
		_inGameState = InGameState::PLAYING;

		for (int i = 0; i < Map_HEIGHT; ++i)
		{
			for (int j = 0; j < Map_WIDTH; ++j)
			{
				_originMapData[i][j] = gameData.mapData[i][j];
			}
		}
		_gameSystem.Reset(_originMapData, _inGameMap,
			gameData.timer); 
	}

	time = _gameSystem.Timer();
	isClear = _gameSystem.CheckClearGame(_inGameMap);

	static Key saveKey = Key::FAIL;

	bool isMoveEnd = !_gameSystem.CheckEndMove(_inGameMap);

	if (isMoveEnd)
	{
		Key eKey = KeyController();
		saveKey = eKey;
	}

	switch (saveKey)
	{
	case Key::UP:
		_gameSystem.MoveUpdate(_inGameMap, false, -1);
		break;
	case Key::DOWN:
		_gameSystem.MoveUpdate(_inGameMap, false, 1);
		break;
	case Key::LEFT:
		_gameSystem.MoveUpdate(_inGameMap, true, -1);
		break;
	case Key::RIGHT:
		_gameSystem.MoveUpdate(_inGameMap, true, 1);
		break;
	}

	if ((GetAsyncKeyState('R') & 0x8000) && isMoveEnd
		&& !isClear)
	{
		_gameSystem.Reset(_originMapData, _inGameMap
			, _gameSystem.time);
	}
}

void GameScene::Render()
{
	cout.precision(2);
	if (isClear)
	{
		_inGameState = InGameState::CLEAR;
	}
	else
	{
		cout << std::setw(5) << std::setfill('0') << std::fixed;
		cout << time;
	}
	COORD resolution = GetConsoleResolution();
	float x = (resolution.X * 0.5f) - (Map_WIDTH - 1) / 2;
	float y = (resolution.Y * 0.5f) - Map_HEIGHT / 2;
	for (int i = 0; i < Map_HEIGHT; ++i)
	{
		IsGotoxy(x, y + i);
		for (int j = 0; j < Map_WIDTH - 1; ++j)
		{
			_inGameMap[i][j].Render();
		}

		cout << '\n';
	}
	SetColor();
}