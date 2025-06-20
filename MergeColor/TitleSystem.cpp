#include "TitleSystem.h"

Stage TitleSystem::GetCurSelectStage()
{
	COORD resolution = GetConsoleResolution();
	int x = resolution.X / 3;
	static int y = resolution.Y / 3 * 2;
	static int originy = y;
	Key eKey = KeyController();
	switch (eKey)
	{
	case Key::UP:
		if (y > originy)
		{
			IsGotoxy(x - 2, y);
			cout << " ";
			IsGotoxy(x - 2, --y);
			cout << ">";
			Sleep(100);
		}
		break;
	case Key::DOWN:
		if (y < originy + _stageCnt - 1)
		{
			IsGotoxy(x - 2, y);
			cout << " ";
			IsGotoxy(x - 2, ++y);
			cout << ">";
			Sleep(100);
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
	return Stage::FAIL;
}

void TitleSystem::EnterAnimation()
{
	COORD resolution = GetConsoleResolution();
	int delaytime = 10000;
	SpiralAnimation(resolution, delaytime);
	system("cls");
}

void TitleSystem::SpiralAnimation(COORD _resolution, int _delaytime)
{
	int coutmode = _setmode(_fileno(stdout), _O_U16TEXT);
	SetColor(COLOR::WHITE, COLOR::BLACK);
	system("cls");
	int left = 0;

	int right = _resolution.X / 2 - 1; // x좌표는 *2 해서 출력하므로 절반
	int top = 0;
	int bottom = _resolution.Y - 1;
	// left와 top값은 증가 시키고 right와 bottom값은 감소시키면서 나선형으로 출력
	while (left <= right && top <= bottom)
	{
		//상단 가로줄 왼쪽에서 오른쪽으로 이동
		for (int i = left; i <= right; ++i)
		{
			IsGotoxy(i * 2, top);
			wcout << L"██";
			FrameSync(_delaytime);
		}
		++top;
		//오른쪽 세로줄 위쪽에서 아래쪽으로 이동
		for (int i = top; i <= bottom; ++i)
		{
			IsGotoxy(right * 2, i);
			wcout << L"██";
			FrameSync(_delaytime);
		}
		--right;
		//하단 가로줄 오른쪽에서 왼쪽으로 이동
		// 혹시나 top이 bottom보다 크거나 같으면 실행하지 않도록 함
		if (top <= bottom)
		{
			for (int i = right; i >= left; --i)
			{
				IsGotoxy(i * 2, bottom);
				wcout << L"██";
				FrameSync(_delaytime);
			}
			--bottom;
		}
		//왼쪽 세로줄 아래쪽에서 위쪽으로 이동
		// 혹시나 left가 right보다 크거나 같으면 실행하지 않도록 함
		if (left <= right)
		{
			for (int i = bottom; i >= top; --i)
			{
				IsGotoxy(left * 2, i);
				wcout << L"██";
				FrameSync(_delaytime);
			}
			++left;
		}
	}
	int wcoutmode = _setmode(_fileno(stdout), coutmode);
	SetColor();
}
