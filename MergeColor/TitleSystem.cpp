#include "TitleSystem.h"

Stage TitleSystem::GetCurSelectStage()
{
	COORD resolution = GetConsoleResolution(); 
	int x = resolution.X / 3 + 10;
	static int y = resolution.Y / 3 + 4;
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
		return (Stage)NextStage;
	}
	IsGotoxy(x - 2, y);
	cout << ">";
	Sleep(75);
	return Stage::FAIL;
}
