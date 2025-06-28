#pragma once
#include <vector>
#include "Single.h"
#include "Block.h"
using std::pair;

class InfoUIManager : public Single<InfoUIManager>
{
public:	
	pair<BlockType, BlockType> colorInfo[3]
	{
		{BlockType::RED, BlockType::YELLOW},
		{BlockType::RED, BlockType::BLUE},
		{BlockType::YELLOW, BlockType::BLUE},
	};
	void RenderMergeInfoUI(int colorMixId);
	void InputArrowInfoUI();
};

