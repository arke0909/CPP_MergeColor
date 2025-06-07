#pragma once
#include "GameLogic.h"
class Core
{
public:
	void Run();
	void Init(char gameMap[Map_HEIGHT][Map_WIDTH]);
private:
	void Update(char gameMap[Map_HEIGHT][Map_WIDTH]);
	void Render(char gameMap[Map_HEIGHT][Map_WIDTH]);
};

