#pragma once
#include "Enums.h"
#include "Console.h"

COLOR TransitionColor(BlockType blockType);
BlockType CalcBlockType(BlockType block, BlockType target);

typedef struct Block
{
	BlockType blockType = BlockType::NONE;
	bool isMoving = false;

	void Render();
}
Block, * PBlock;