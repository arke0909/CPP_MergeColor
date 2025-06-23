#pragma once
#include "Block.h"
#include "Single.h"

const int Map_HEIGHT = 6;
const int Map_WIDTH = 7;

typedef char Map[Map_HEIGHT][Map_WIDTH];

class InGameSystem
{
public:
	float time = 0;
	float currentTime = 0;
	float startTime = 0;
public:
	void Reset(Map gameMap, Block inGameBlock[Map_HEIGHT][Map_WIDTH], float time);
	void MoveUpdate(Block inGameBlock[Map_HEIGHT][Map_WIDTH], bool isXMove, int dir);
	bool CalcBlock(PBlock block, PBlock target);
	void MergeColor(Block& block, Block& target);
	BlockType CalcBlockType(BlockType block, BlockType target);
	bool CheckEndMove(Block inGameBlock[Map_HEIGHT][Map_WIDTH]);
	bool CheckClearGame(Block inGameBlock[Map_HEIGHT][Map_WIDTH]);
	float Timer();
	bool CheckFailGame();
	void RenderMergeInfoUI(BlockType a, BlockType b);
};

