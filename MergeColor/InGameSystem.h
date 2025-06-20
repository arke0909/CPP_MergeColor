#pragma once
#include "Block.h"
#include "Single.h"

const int Map_HEIGHT = 6;
const int Map_WIDTH = 7;

class InGameSystem
{
public:
	void Reset(char gameMap[Map_HEIGHT][Map_WIDTH], Block inGameBlock[Map_HEIGHT][Map_WIDTH]);
	void MoveUpdate(Block inGameBlock[Map_HEIGHT][Map_WIDTH], bool isXMove, int dir);
	bool CalcBlock(PBlock block, PBlock target);
	void MergeColor(Block& block, Block& target);
	bool CheckEndMove(Block inGameBlock[Map_HEIGHT][Map_WIDTH]);
	bool CheckEndGame(Block inGameBlock[Map_HEIGHT][Map_WIDTH]);
};

