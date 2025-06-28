#include "Block.h"

void Block::Render()

{
	if (blockType == BlockType::NONE)
	{
		SetColor();
		cout << "бр";
	}
	else
	{
		SetColor(TransitionColor(blockType));
		cout << "бс";
	}
}

COLOR TransitionColor(BlockType blockType)
{
	switch (blockType)
	{
	case BlockType::OBSTAC:
		return COLOR::WHITE;
	case BlockType::RED:
		return COLOR::RED;
	case BlockType::ORENGE:
		return COLOR::LIGHT_RED;
	case BlockType::YELLOW:
		return COLOR::YELLOW;
	case BlockType::GREEN:
		return COLOR::GREEN;
	case BlockType::BLUE:
		return COLOR::BLUE;
	case BlockType::PUPLE:
		return COLOR::LIGHT_VIOLET;
	}
}

BlockType CalcBlockType(BlockType block, BlockType target)
{

	if (block == target)
		return BlockType::NONE;
	else if (block == BlockType::RED && target == BlockType::YELLOW ||
		block == BlockType::YELLOW && target == BlockType::RED)
		return BlockType::ORENGE;
	else if (block == BlockType::RED && target == BlockType::BLUE ||
		block == BlockType::BLUE && target == BlockType::RED)
		return BlockType::PUPLE;
	else if (block == BlockType::BLUE && target == BlockType::YELLOW ||
		block == BlockType::YELLOW && target == BlockType::BLUE)
		return BlockType::GREEN;

	return target;
}
