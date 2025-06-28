#pragma once
#include "Single.h"
class GameManager : public Single<GameManager>
{
	friend class Single<GameManager>;
private:
	GameManager() {}
	   ~GameManager() {}
public:
	bool isRunning = true;
};

