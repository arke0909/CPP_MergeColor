#pragma once
#include "KeyController.h"
#include "InGameSystemManager.h"
#include "Console.h"

typedef Block BlockMap[Map_HEIGHT][Map_WIDTH];

class GameScene
{
private:
	
	InGameState inGameState = InGameState::PLAYING;
	InGameSystemManager systemManager = InGameSystemManager();
	char _originMapData[Map_HEIGHT][Map_WIDTH]
	{};
	BlockMap _inGameMapArr[10];
	Block _inGameMap[Map_HEIGHT][Map_WIDTH];

public:
	void Init(char mapData[Map_HEIGHT][Map_WIDTH]);
	void Update();
	void Render();
};

