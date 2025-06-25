#include "GameScene.h"
#include <iomanip>

void GameScene::Update(Scene &curScene, GameData gameData)
{
	if (_dataId != gameData.dataId)
	{
		_isClear = false;
		_dataId = gameData.dataId;
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

	switch (_inGameState)
	{
	case InGameState::PLAYING:
		PlayingUpdate();
		break;
	default:
		NonPlayingUpdate(curScene);
		break;

	}
}

void GameScene::Render()
{
	switch (_inGameState)
	{
	case InGameState::PLAYING:
		PlayingRender();
		break;
	default:
		NonPlayingRender();
		break;
	}

	SetColor();
}

void GameScene::PlayingUpdate()
{
	if (_isFail)
		_inGameState = InGameState::FAIL;
	else if (_isClear)
		_inGameState = InGameState::CLEAR;

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

	if ((GetAsyncKeyState('R') & 0x8000) && isMoveEnd)
	{
		_gameSystem.Reset(_originMapData, _inGameMap
			, _gameSystem.time);
	}

	_time = _gameSystem.Timer();
	_isClear = _gameSystem.CheckClearGame(_inGameMap);
	_isFail = _gameSystem.CheckFailGame();
}

void GameScene::PlayingRender()
{
	COORD resolution = GetConsoleResolution();

	cout.precision(2);
	IsGotoxy(resolution.X * 0.5f - 3, resolution.Y * 0.15f);
	cout << std::setw(5) << std::setfill('0') << std::fixed;
	cout << _time;

	for (int i = 0; i < 3; ++i)
	{
		IsGotoxy(resolution.X * 0.3f * (i + 1) - 15, resolution.Y * 0.25f);
		BlockType a = colorInfo[i].first;
		BlockType b = colorInfo[i].second;
		_gameSystem.RenderMergeInfoUI(a, b);
	}
	

	IsGotoxy(resolution.X * 0.17f, resolution.Y * 0.35f);
	cout << "← : 좌로 이동\t→ : 우로 이동\t↑ : 위로 이동\t↓ : 아래로 이동";

	float x = (resolution.X * 0.5f) - ((Map_WIDTH - 1) / 2) * 2;
	float y = (resolution.Y * 0.3f) + Map_HEIGHT / 2;
	for (int i = 0; i < Map_HEIGHT; ++i)
	{
		IsGotoxy(x, y + i);
		for (int j = 0; j < Map_WIDTH - 1; ++j)
		{
			_inGameMap[i][j].Render();
		}

		cout << '\n';
	}
}

void GameScene::NonPlayingUpdate(Scene &curScene)
{
	_asciiObjects.Update(_inGameState);

	static int x = 0;

	Key eKey = KeyController();
	Select curSelect;

	switch (_inGameState)
	{
	case InGameState::CLEAR:
		curSelect = _gameSystem.GetCurrentSelectWhenClear(curScene);
		break;
	case InGameState::FAIL:
		curSelect = _gameSystem.GetCurrentSelectWhenFail(curScene);
		break;
	}

}

void GameScene::NonPlayingRender()
{
	_asciiObjects.Render(_inGameState);

	switch (_inGameState)
	{
	case InGameState::CLEAR:
		break;
	case InGameState::FAIL:
		break;
	}
}
