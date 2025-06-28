#pragma once
#include "TitleSystem.h"
#include "FadeManager.h"

// StageCnt는 스테이지 개수

class  SelectScene
{
private:
	int _stageCnt = 0;
	InTitleState _inTitleState = InTitleState::MENU;
	TitleSystem titleSystem = TitleSystem(_stageCnt);

public:
	SelectScene(int stageCnt) : _stageCnt(stageCnt) {}
	void Update(Scene& eCurScene, Stage& eCurStage);
	void Render();
};