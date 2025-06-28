#pragma once
#include <vector>
#include "AsciiObjects.h"
#include "InGameSystem.h"
#include "FadeManager.h"
#include "ClearInfoManager.h"
#include "Console.h"

using std::pair;

typedef struct GameDataStruct 
{
	int dataId = 0;
	float timer = 10;
	Map mapData; 
} GameData, * PGameData; 

class GameScene
{
private:
	int _dataId = 0;
	float _time = 0.f;
	bool _isClear = false;
	bool _isFail = false;
	//bool _isPause = false;
	InGameState _inGameState = InGameState::PLAYING;
	InGameSystem _gameSystem = InGameSystem();
	AsciiObjects _asciiObjects = AsciiObjects();
	Map _originMapData;
	Block _inGameMap[Map_HEIGHT][Map_WIDTH];

	pair<BlockType, BlockType> colorInfo[3]
	{
		{BlockType::RED, BlockType::YELLOW},
		{BlockType::RED, BlockType::BLUE},
		{BlockType::YELLOW, BlockType::BLUE},
	};

public:
	void Update(Scene &curScene, GameData mapData);
	void Render();
private:
	void PlayingUpdate();
	void PlayingRender();
	void NonPlayingUpdate(Scene &curScene);
	void NonPlayingRender();
};

