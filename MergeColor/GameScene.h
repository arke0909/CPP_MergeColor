#pragma once
#include "KeyController.h"
#include "InGameSystem.h"
#include "Console.h"


class GameScene
{
private:
	
	InGameState inGameState = InGameState::PLAYING;
	InGameSystem systemManager = InGameSystem();
	char _originMapData[Map_HEIGHT][Map_WIDTH]
	{};
	Block _inGameMap[Map_HEIGHT][Map_WIDTH];

public:
	void Init(char mapData[Map_HEIGHT][Map_WIDTH]);
	void Update();
	void Render();
};

