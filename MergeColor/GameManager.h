#pragma once
#include "Single.h"
class GameManager : public Single<GameManager>
{
public:
	bool isRunning = true;
};

