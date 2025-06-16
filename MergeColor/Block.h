#pragma once
#include "Enums.h"
#include "GameLogic.h"
typedef struct Block
{
	BlockType blockType = BlockType::NONE;
	bool isMoving = false;
	bool isMerged = false;
}
Block, * PBlock;

typedef struct BlockMap
{
	Block inGameBlock[Map_HEIGHT][Map_WIDTH]
	{};

	void Init()
	{

	}
	void Update()
	{

	}
	void Render()
	{

	}
};