#include "SelectScene.h"
#include<io.h>
#include<fcntl.h>
#include "Console.h"
#include "KeyController.h"

void SlectSceneInit(Scene& _eCurScene, Stage& _eCurStage)
{
	_eCurStage = Stage::NONE;
	SlectSceneUpdate(_eCurScene);
	if (_eCurScene != Scene::TITLE)
		return;
	SlectSceneRender();
	Sleep(60);
}

void SlectSceneUpdate(Scene& _eCurScene, Stage& _eCurStage)
{
	if (_eCurScene != Scene::SELECT)
		return;
	_eCurStage = GetCurSelectStage();
	if (_eCurStage == Stage::FAIL)
		return;
	_eCurScene = Scene::GAME;
	EnterAnimation();
	//여기다 게임시작하는 함수 넣어야함
}

void SlectSceneRender()
{
	COORD resolution = GetConsoleResolution();
	int y = resolution.Y / 3;
	IsGotoxy(0, y);
	int coutmode = _setmode(_fileno(stdout), _O_U16TEXT);
	wcout << L"███╗   ███╗███████╗██████╗  ██████╗ ███████╗     ██████╗ ██████╗ ██╗      ██████╗ ██████╗ " << endl;
	wcout << L"████╗ ████║██╔════╝██╔══██╗██╔════╝ ██╔════╝    ██╔════╝██╔═══██╗██║     ██╔═══██╗██╔══██╗" << endl;
	wcout << L"██╔████╔██║█████╗  ██████╔╝██║  ███╗█████╗      ██║     ██║   ██║██║     ██║   ██║██████╔╝" << endl;
	wcout << L"██║╚██╔╝██║██╔══╝  ██╔══██╗██║   ██║██╔══╝      ██║     ██║   ██║██║     ██║   ██║██╔══██╗" << endl;
	wcout << L"██║ ╚═╝ ██║███████╗██║  ██║╚██████╔╝███████╗    ╚██████╗╚██████╔╝███████╗╚██████╔╝██║  ██║" << endl;
	wcout << L"╚═╝     ╚═╝╚══════╝╚═╝  ╚═╝ ╚═════╝ ╚══════╝     ╚═════╝ ╚═════╝ ╚══════╝ ╚═════╝ ╚═╝  ╚═╝" << endl;

	int wcoutmode = _setmode(_fileno(stdout), coutmode);
	int x = resolution.X / 3;
	y = resolution.Y / 3 * 2;
	for(int i = 0; i < StageCnt; i++)
	{
		IsGotoxy(x, y + i);
		cout << "Stage" << i + 1 << endl;
	}
}

Stage GetCurSelectStage()
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
		if (y < originy + 2)
		{
			IsGotoxy(x - 2, y);
			cout << " ";
			IsGotoxy(x - 2, ++y);
			cout << ">";
			Sleep(100);
			// 1 
		}
		break;
	case Key::SPACE:
		int NextStage = (y - originy) + 1;
		if (NextStage > StageCnt || NextStage < 1)
			return Stage::FAIL;
		return (Stage)NextStage;
	}
	return Stage::FAIL;
}

void EnterAnimation()
{
	COORD resolution = GetConsoleResolution();
	int delaytime = 50;
	SpiralAnimation(resolution, delaytime);
	system("cls");
}
void SpiralAnimation(COORD _resolution, int _delaytime)
{
	SetColor(COLOR::BLACK, COLOR::WHITE);
	system("cls");
	int left = 0;
	int right = _resolution.X / 2 - 1;
	int top = 0;
	int bottom = _resolution.Y - 1;

	while (left <= right && top <= bottom)
	{
		for (int i = left; i <= right; ++i)
		{
			IsGotoxy(i * 2, top);
			cout << "  ";
			Sleep(_delaytime);
		}
		++top;

		for (int i = top; i <= bottom; ++i)
		{
			IsGotoxy(right * 2, i);
			cout << "  ";
			Sleep(_delaytime);
		}
		--right;

		if (top <= bottom)
		{
			for (int i = right; i >= left; --i)
			{
				IsGotoxy(i * 2, bottom);
				cout << "  ";
				Sleep(_delaytime);
			}
			--bottom;
		}

		if (left <= right)
		{
			for (int i = bottom; i >= top; --i)
			{
				IsGotoxy(left * 2, i);
				cout << "  ";
				Sleep(_delaytime);
			}
			++left;
		}
	}

	SetColor();
}