#pragma once
#include "SelectSystem.h"
#include "FadeManager.h"
#include "GameManager.h"
#include "InfoUIManager.h"
#include "Enums.h"

// StageCnt는 스테이지 개수

class  SelectScene
{
private:
	int _stageCnt = 0;
	int _stageYOffset = 2;
	int _startY = 0;
	InTitleState _inTitleState = InTitleState::MENU;
	SelectSystem titleSystem = SelectSystem(_stageCnt);

public:
	SelectScene(int stageCnt) : _stageCnt(stageCnt) {}
	void Update(Scene& eCurScene, Stage& eCurStage);
	void Render();
};