#include "SelectScene.h"

void SelectScene::Update(Scene& eCurScene, Stage& eCurStage)
{
	eCurStage = titleSystem.GetCurSelectStage();
	if (eCurStage == Stage::FAIL)
		return;

	titleSystem.EnterAnimation();
	//여기다 게임시작하는 함수 넣어야함
	eCurScene = Scene::GAME;
}

void SelectScene::Render()
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
	// 스테이지 선택 위치 StageCnt 지정해줘서 스테이지 개수만큼 출력
	for (int i = 0; i < _stageCnt; i++)
	{
		IsGotoxy(x, y + i);
		cout << "Stage" << i + 1 << endl;
	}
}

