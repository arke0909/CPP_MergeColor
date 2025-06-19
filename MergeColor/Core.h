#pragma once
#include "GameLogic.h"
class Core
{
public:
	void Run();
private:
	void Init(char gameMap[Map_HEIGHT][Map_WIDTH]);
	void Update(char gameMap[Map_HEIGHT][Map_WIDTH], Block inGameBlock[Map_HEIGHT][Map_WIDTH]);
	void Render(Block inGameBlock[Map_HEIGHT][Map_WIDTH]);
};

