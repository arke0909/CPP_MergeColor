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
