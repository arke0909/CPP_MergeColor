#pragma once
#include "GameLogic.h"
class Core
{
public:
	void Run();
	void Init(char gameMap[Map_HEIGHT][Map_WIDTH], Block inGameBlock[Map_HEIGHT][Map_WIDTH]);
private:
	void Update(Block inGameBlock[Map_HEIGHT][Map_WIDTH]);
	void Render(Block inGameBlock[Map_HEIGHT][Map_WIDTH]);
//	Block inGameBlock[Map_HEIGHT][Map_WIDTH];
	Block m_block;
};

