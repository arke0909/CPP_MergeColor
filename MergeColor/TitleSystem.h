#pragma once
#include<io.h>
#include<fcntl.h>
#include "KeyController.h"
#include "Console.h"

class TitleSystem
{
private:
	int _stageCnt = 0;
public:
	TitleSystem(int stageCnt) : _stageCnt(stageCnt) {}

	// 키 입력 받아서 선택된 스테이지 반환
	Stage GetCurSelectStage();
	// 애니메이션 다 실행시켜주는 함수
	void EnterAnimation();
	void SpiralAnimation(COORD _resolution, int _delaytime);
};
