#pragma once
#include "Enums.h"
#include "Console.h"

typedef struct Block
{
	BlockType blockType = BlockType::NONE;
	bool isMoving = false;

	void Render()
	{
		if (blockType == BlockType::NONE)
		{
			SetColor();
			cout << "бр";
		}
		else
		{
			switch (blockType)
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
}
Block, * PBlock;