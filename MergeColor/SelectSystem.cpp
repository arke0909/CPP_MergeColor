﻿#include "SelectSystem.h"



InTitleSelect SelectSystem::GetCurSelect()
{
	COORD resolution = GetConsoleResolution();
	int x = resolution.X / 2 - 3;
	static int y = resolution.Y / 3 + 4;
	static int originy = y;
	Key eKey = KeyController();
	switch (eKey)
	{
	case Key::UP:
		if (y > originy)
		{
			IsGotoxy(x - 2, y);
			cout << " ";
			y--;
		}
		break;
	case Key::DOWN:
		if (y < originy + 2) 
		{
			IsGotoxy(x - 2, y);
			cout << " ";
			y++;
		}
		break;
	case Key::SPACE:
		int curSelect = (y - originy) + 1;
		if (curSelect > _stageCnt || curSelect < 1)
			return InTitleSelect::FAIL;
		else
		{
			IsGotoxy(x - 2, y);
			cout << " ";
			return (InTitleSelect)curSelect;
		}
	}
	IsGotoxy(x - 2, y);
	cout << ">";
	Sleep(75);
	return InTitleSelect::FAIL;
}

Stage SelectSystem::GetCurSelectStage()
{
	COORD resolution = GetConsoleResolution(); 
	int x = resolution.X / 2 - 3;
	static int y = resolution.Y / 3 + 2;
	static int originy = y;
	static bool IsStart = true;
	Key eKey = KeyController();
	switch (eKey)
	{
	case Key::UP:
		if (y > originy)
		{
			IsGotoxy(x - 2, y);
			cout << " ";
			y--;
			
		}
		break;
	case Key::DOWN:
		if (y < originy + _stageCnt - 1)
		{
			IsGotoxy(x - 2, y);
			cout << " ";
			y++;
		}
		break;
	case Key::SPACE:
		// y값에 origin값 빼서 현재 스테이지 계산
		int NextStage = (y - originy) + 1;
		// 스테이지 개수보다 크거나 작으면 실패로 반환
		if (NextStage > _stageCnt || NextStage < 1)
			return Stage::FAIL;
		if(ClearInfoManager::GetInst()->CheckClearInfo(NextStage) == "1"
			|| ClearInfoManager::GetInst()->CheckClearInfo(NextStage) == "2")
			return (Stage)NextStage;
	}
	IsGotoxy(x - 2, y);
	cout << ">";
	Sleep(75);
	return Stage::FAIL;
}
