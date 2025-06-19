#pragma once
#include "GameLogic.h"

class SystemManager
{
public:
	void Reset(char gameMap[Map_HEIGHT][Map_WIDTH], Block inGameBlock[Map_HEIGHT][Map_WIDTH])
	{
		for (int i = 0; i < Map_HEIGHT; ++i)
		{
			for (int j = 0; j < Map_WIDTH; ++j)
			{
				inGameBlock[i][j] = Block{ (BlockType)gameMap[i][j], false };
			}
		}
	}
	void MergeColor(Block& block, Block& target)
	{
		if (block.blockType == target.blockType)
		{
			block.blockType = BlockType::NONE;
			target.blockType = BlockType::NONE;
		}
		else if (block.blockType == BlockType::RED && target.blockType == BlockType::YELLOW ||
			block.blockType == BlockType::YELLOW && target.blockType == BlockType::RED)
		{
			block.blockType = BlockType::NONE;
			target.blockType = BlockType::ORENGE;
		}
		else if (block.blockType == BlockType::RED && target.blockType == BlockType::BLUE ||
			block.blockType == BlockType::BLUE && target.blockType == BlockType::RED)
		{
			block.blockType = BlockType::NONE;
			target.blockType = BlockType::PUPLE;
		}
		else if (block.blockType == BlockType::BLUE && target.blockType == BlockType::YELLOW ||
			block.blockType == BlockType::YELLOW && target.blockType == BlockType::BLUE)
		{
			block.blockType = BlockType::NONE;
			target.blockType = BlockType::GREEN;
		}

		block.isMoving = false;
		target.isMoving = false;
	}
};

