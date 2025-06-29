#include "InGameSystem.h"
#include "SoundManager.h"

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
	BlockType calcBlockType = CalcBlockType(block.blockType, target.blockType);

	block.isMoving = false;
	target.isMoving = false;

	if (calcBlockType != target.blockType)
	{
		SoundManager::GetInst()->SoundPlayEffect();
		block.blockType = BlockType::NONE;
		target.blockType = calcBlockType;
	}
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

InGameSelect InGameSystem::GetCurrentSelectWhenClear()
{
	COORD resolution = GetConsoleResolution();
	int center = resolution.X * 0.5f;

	Key eKey = KeyController();

	SetColor(COLOR::YELLOW);
	IsGotoxy(center, resolution.Y * 0.75f);
	cout << "<EXIT>";
	SetColor();

	if (eKey == Key::SPACE)
	{
		return InGameSelect::EXIT;
	}

	return InGameSelect::FAIL;
}

InGameSelect InGameSystem::GetCurrentSelectWhenFail()
{
	COORD resolution = GetConsoleResolution();
	int offset = 10;
	int center = resolution.X * 0.5f;
	int exitX = center - offset;
	int retryX = center + offset;
	static int select = (int)InGameSelect::EXIT;

	Key eKey = KeyController();


	switch (eKey)
	{
	case Key::LEFT:
		select = max(0, --select);
		break;
	case Key::RIGHT:
		select = min((int)InGameSelect::RETRY, ++select);
		break;
	case Key::SPACE:

		if (select == (int)InGameSelect::EXIT)
			return InGameSelect::EXIT;
		else if (select == (int)InGameSelect::RETRY)
		{
			select = (int)InGameSelect::EXIT;
			return InGameSelect::RETRY;
		}
		break;
	}

	switch (select)
	{
	case (int)InGameSelect::EXIT:
		SetColor(COLOR::YELLOW);
		IsGotoxy(exitX, resolution.Y * 0.75f);
		cout << "<EXIT>";
		SetColor();
		IsGotoxy(retryX, resolution.Y * 0.75f);
		cout << " RETRY ";
		break;
	case (int)InGameSelect::RETRY:
		SetColor();
		IsGotoxy(exitX, resolution.Y * 0.75f);
		cout << " EXIT ";
		SetColor(COLOR::YELLOW);
		IsGotoxy(retryX, resolution.Y * 0.75f);
		cout << "<RETRY>";
		break;
	}

	SetColor();

	return InGameSelect::FAIL;
}



