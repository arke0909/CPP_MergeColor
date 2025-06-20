#pragma once
#include "TitleSystem.h"

// StageCnt는 스테이지 개수

class  SelectScene
{
private:
	int _stageCnt = 10;
	TitleSystem titleSystem = TitleSystem(_stageCnt);

public:
	void Update(Scene& eCurScene, Stage& eCurStage);
	void Render();
};