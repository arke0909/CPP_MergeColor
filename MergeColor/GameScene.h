#pragma once
#include "KeyController.h"
#include "InGameSystemManager.h"

class GameScene
{
private:
	
	InGameState inGameState = InGameState::PLAYING;
	InGameSystemManager* systemManager;
	char _originMapData[Map_HEIGHT][Map_WIDTH]
	{ "r1000r",
	"010111",
	"010000",
	"000010",
	"111010",
	"r0001r" };
	Block _inGameMap[Map_HEIGHT][Map_WIDTH]
	{};

public:
	void Init(char mapData[Map_HEIGHT][Map_WIDTH])
	{
		systemManager = InGameSystemManager::GetInst();

		for (int i = 0; i < Map_HEIGHT; ++i)
		{
			for (int j = 0; j < Map_WIDTH; ++j)
			{
				_originMapData[i][j] = mapData[i][j];
			}
		}
		systemManager->Reset(_originMapData, _inGameMap);
	}
	void Update()
	{
		static Key saveKey = Key::FAIL;
		int dir = 1;
		bool isXMove = true;

		bool isMoveEnd = !systemManager->CheckEndMove(_inGameMap);

		if (isMoveEnd)
		{
			Key eKey = KeyController();
			saveKey = eKey;
		}

		switch (saveKey)
		{
		case Key::UP:
			dir = -1;
			isXMove = false;
			break;
		case Key::DOWN:
			dir = 1;
			isXMove = false;
			break;
		case Key::LEFT:
			dir = -1;
			isXMove = true;
			break;
		case Key::RIGHT:
			dir = 1;
			isXMove = true;
			break;
		}

		systemManager->MoveUpdate(_inGameMap, isXMove, dir);

		if ((GetAsyncKeyState('R') & 0x8000) && isMoveEnd)
		{
			systemManager->Reset(_originMapData, _inGameMap);
		}
	}
	void Render() 
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
};

