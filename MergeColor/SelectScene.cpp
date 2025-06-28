#include "SelectScene.h"
#include "ClearInfoManager.h"

void SelectScene::Update(Scene& eCurScene, Stage& eCurStage)
{
	Key eKey = KeyController();
	InTitleSelect eCurSelect;
	switch (_inTitleState)
	{
	case InTitleState::MENU:
		eCurSelect = titleSystem.GetCurSelect();
		if (eCurSelect == InTitleSelect::START)
		{
			_inTitleState = InTitleState::SELECT;
			Sleep(100);
		}
		break;
	case InTitleState::SELECT:
		eCurStage = titleSystem.GetCurSelectStage();
		if (eCurStage == Stage::FAIL)
			return;
		cout << (int)eCurStage;
		FadeManager::GetInst()->EnterAnimation();
		eCurScene = Scene::GAME;
		break;
	}

	if (eKey == Key::ESC)
		_inTitleState = InTitleState::MENU;
}

void SelectScene::Render()
{
	COORD resolution = GetConsoleResolution();
	int y = resolution.Y / 3 - 7;
	IsGotoxy(0, y);
	int coutmode = _setmode(_fileno(stdout), _O_U16TEXT);
	wcout << L"   ███╗   ███╗███████╗██████╗  ██████╗ ███████╗     ██████╗ ██████╗ ██╗      ██████╗ ██████╗ " << endl;
	wcout << L"   ████╗ ████║██╔════╝██╔══██╗██╔════╝ ██╔════╝    ██╔════╝██╔═══██╗██║     ██╔═══██╗██╔══██╗" << endl;
	wcout << L"   ██╔████╔██║█████╗  ██████╔╝██║  ███╗█████╗      ██║     ██║   ██║██║     ██║   ██║██████╔╝" << endl;
	wcout << L"   ██║╚██╔╝██║██╔══╝  ██╔══██╗██║   ██║██╔══╝      ██║     ██║   ██║██║     ██║   ██║██╔══██╗" << endl;
	wcout << L"   ██║ ╚═╝ ██║███████╗██║  ██║╚██████╔╝███████╗    ╚██████╗╚██████╔╝███████╗╚██████╔╝██║  ██║" << endl;
	wcout << L"   ╚═╝     ╚═╝╚══════╝╚═╝  ╚═╝ ╚═════╝ ╚══════╝     ╚═════╝ ╚═════╝ ╚══════╝ ╚═════╝ ╚═╝  ╚═╝" << endl;
	int wcoutmode = _setmode(_fileno(stdout), coutmode);
	int x = resolution.X / 3 + 10;
	y = resolution.Y / 3 + 4;
	// 스테이지 선택 위치 StageCnt 지정해줘서 스테이지 개수만큼 출력

	switch (_inTitleState)
	{
	case InTitleState::MENU:
		IsGotoxy(x, y);
		cout << "Start";
		IsGotoxy(x, y + 1);
		cout << "Quit";
		break;
	case InTitleState::SELECT:
		for (int i = 0; i < _stageCnt; i++)
		{
			IsGotoxy(x, y + i - 2);
			cout << "Stage" << i + 1 << endl;
		}
		break;
	}

}

