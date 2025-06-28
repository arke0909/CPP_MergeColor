#pragma once
#include "KeyController.h"
#include "ClearInfo.h"
#include "Console.h"
using std::max;
using std::min;
using std::clock;
#undef max;
#undef min;

class TitleSystem
{
private:
	int _stageCnt = 0;
public:
	TitleSystem(int stageCnt) : _stageCnt(stageCnt) {}

	InTitleSelect GetCurSelect();
	// 키 입력 받아서 선택된 스테이지 반환
	Stage GetCurSelectStage();
};
