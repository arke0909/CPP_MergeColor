#pragma once
#include "Single.h"
#include "Console.h"
#include<fcntl.h>
#include<io.h>

class FadeManager : public Single<FadeManager>
{
	friend class Single<FadeManager>;
public:
	void EnterAnimation();
private:
	FadeManager() {};
	~FadeManager() {};
	void SpiralAnimation(COORD _resolution, int _delaytime);
};

