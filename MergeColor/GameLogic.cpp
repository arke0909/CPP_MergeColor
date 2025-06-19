#include "GameLogic.h"
#include "Console.h"
using std::cout;


void MoveUpdate(Block inGameBlock[Map_HEIGHT][Map_WIDTH], bool isXMove, int dir)
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

				if (block->blockType == BlockType::NONE ||
					block->blockType == BlockType::OBSTAC || !block->isMoving)
				{
					block->isMoving = false;
					continue;
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

				if (block->blockType == BlockType::NONE ||
					block->blockType == BlockType::OBSTAC || !block->isMoving)
				{
					block->isMoving = false;
					continue;
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
			}
		}
	}
}

bool CheckEndMove(Block inGameBlock[Map_HEIGHT][Map_WIDTH])
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

bool CheckEndGame(Block inGameBlock[Map_HEIGHT][Map_WIDTH])
{
	bool end = false;

	for (int i = 0; i < Map_HEIGHT; ++i)
	{
		if (end) break;

		for (int j = 0; j < Map_WIDTH; ++j)
		{
			if (inGameBlock[i][j].blockType != BlockType::NONE 
				&& inGameBlock[i][j].blockType != BlockType::OBSTAC)
			{
				end = true;
				break;
			}
		}
	}

	return end;
}


void MapRender(Block inGameBlock[Map_HEIGHT][Map_WIDTH])
{
	for (int i = 0; i < Map_HEIGHT; ++i)
	{
		for (int j = 0; j < Map_WIDTH - 1; ++j)
		{
			if (inGameBlock[i][j].blockType == BlockType::NONE)
			{
				SetColor();
				cout << "бр";
			}
			else
			{
				switch (inGameBlock[i][j].blockType)
				{
				case BlockType::OBSTAC:
					SetColor();
					break;
				case BlockType::RED:
					SetColor(COLOR::RED);
					break;
				case BlockType::ORENGE:
					SetColor(COLOR::LIGHT_RED);
					break;
				case BlockType::YELLOW:
					SetColor(COLOR::YELLOW);
					break;
				case BlockType::GREEN:
					SetColor(COLOR::GREEN);
					break;
				case BlockType::BLUE:
					SetColor(COLOR::BLUE);
					break;
				case BlockType::PUPLE:
					SetColor(COLOR::LIGHT_VIOLET);
					break;
				}
				cout << "бс";
			}
		}

		cout << '\n';
	}
	SetColor(); 
}
