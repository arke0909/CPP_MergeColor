#include "InGameSystem.h"
using std::max;
using std::clock;
#undef max;
void InGameSystem::Reset(Map gameMap, Block inGameBlock[Map_HEIGHT][Map_WIDTH], float time)
{
	this->time = currentTime = time;
	startTime = clock();
	for (int i = 0; i < Map_HEIGHT; ++i)
	{
		for (int j = 0; j < Map_WIDTH - 1; ++j)
		{
			inGameBlock[i][j] = Block{ (BlockType)gameMap[i][j], false };
		}
	}
}

void InGameSystem::MoveUpdate(Block inGameBlock[Map_HEIGHT][Map_WIDTH], bool isXMove, int dir)
{
	if (isXMove)
	{
		int start = dir == -1 ? 1 : Map_WIDTH - 3;
		int end = dir == -1 ? Map_WIDTH - 1 : -1;

		for (int i = start; i != end; i -= dir)
		{
			for (int j = 0; j < Map_HEIGHT; j++)
			{
				PBlock block = &inGameBlock[j][i];
				int next = i + dir;
				PBlock target = &inGameBlock[j][next];

				block->isMoving = !(next < 0 || next >= Map_WIDTH - 1)
					&& target->blockType != BlockType::OBSTAC;

				if (!CalcBlock(block, target)) continue;
			}
		}
	}
	else
	{
		int start = dir == -1 ? 1 : Map_HEIGHT - 2;
		int end = dir == -1 ? Map_HEIGHT : -1;

		for (int i = start; i != end; i -= dir)
		{
			for (int j = 0; j < Map_WIDTH - 1; j++)
			{
				PBlock block = &inGameBlock[i][j];
				int next = i + dir;
				PBlock target = &inGameBlock[next][j];

				block->isMoving = !(next < 0 || next >= Map_HEIGHT)
					&& target->blockType != BlockType::OBSTAC;

				if (!CalcBlock(block, target)) continue;
			}
		}
	}
}

bool InGameSystem::CalcBlock(PBlock block, PBlock target)
{
	if (block->blockType == BlockType::NONE ||
		block->blockType == BlockType::OBSTAC || !block->isMoving)
	{
		block->isMoving = false;
		return false;
	}

	if (target->blockType == BlockType::NONE
		&& block->isMoving)
	{
		target->blockType = block->blockType;
		block->blockType = BlockType::NONE;
	}
	else if (block->isMoving)
	{
		MergeColor(*block, *target);
	}
	else
	{
		block->isMoving = false;
	}

	return true;
}

void InGameSystem::MergeColor(Block& block, Block& target)
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

bool InGameSystem::CheckEndMove(Block inGameBlock[Map_HEIGHT][Map_WIDTH])
{
	bool moving = false;

	for (int i = 0; i < Map_HEIGHT; ++i)
	{
		for (int j = 0; j < Map_WIDTH; ++j)
		{
			if (inGameBlock[i][j].isMoving)
				moving = true;
		}
	}

	return moving;
}

bool InGameSystem::CheckClearGame(Block inGameBlock[Map_HEIGHT][Map_WIDTH])
{
	bool end = true;

	for (int i = 0; i < Map_HEIGHT; ++i)
	{
		if (!end) break;

		for (int j = 0; j < Map_WIDTH - 1; ++j)
		{
			if (inGameBlock[i][j].blockType != BlockType::NONE
				&& inGameBlock[i][j].blockType != BlockType::OBSTAC)
			{
				end = false;
				break;
			}
		}
	}
	return end;
}

float InGameSystem::Timer()
{
	float checkTime = clock();
	float gap = (checkTime - startTime) / CLOCKS_PER_SEC;
	currentTime = time - gap;
	currentTime = max(0.f, currentTime);
	return currentTime;
}

bool InGameSystem::CheckFailGame()
{
	return currentTime <= 0;
}



