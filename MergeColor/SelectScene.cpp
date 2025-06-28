#include "SelectScene.h"

void SelectScene::Update(Scene& eCurScene, Stage& eCurStage)
{
	Key eKey = KeyController();
	InTitleSelect eCurSelect;

	if (eKey == Key::ESC && _inTitleState == InTitleState::SELECT)
	{
		system("cls");
		_inTitleState = InTitleState::MENU;
	}

	switch (_inTitleState)
	{
	case InTitleState::MENU:
		eCurSelect = titleSystem.GetCurSelect();
		if (eCurSelect == InTitleSelect::START)
		{
			_inTitleState = InTitleState::SELECT;
			system("cls");
			Sleep(100);
		}
		else if (eCurSelect == InTitleSelect::INFO)
		{
			_inTitleState = InTitleState::INFO;
			system("cls");
			Sleep(100);
		}
		else if (eCurSelect == InTitleSelect::QUIT)
		{
			GameManager::GetInst()->isRunning = false;
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
	case InTitleState::INFO:
		if (eKey == Key::SPACE)
		{
			_inTitleState = InTitleState::MENU;
			system("cls");
			Sleep(100);
		}
		break;
	}

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
	int x = resolution.X / 2 - 3;
	y = resolution.Y / 3 + 4;
	// 스테이지 선택 위치 StageCnt 지정해줘서 스테이지 개수만큼 출력

	switch (_inTitleState)
	{
	case InTitleState::MENU:
		IsGotoxy(x, y);
		cout << "Start  ";
		IsGotoxy(x, y + 1);
		cout << "Info   ";
		IsGotoxy(x, y + 2);
		cout << "Quit   ";
		_startY += 2;
		break;
	case InTitleState::SELECT:
		for (int i = 0; i < _stageCnt; i++)
		{
			IsGotoxy(x, y + i - _stageYOffset);
			string inp = ClearInfoManager::GetInst()->CheckClearInfo(i + 1);
			if (inp == "2")
			{
				SetColor(COLOR::GREEN);
			}
			else if (inp == "1")
			{
				SetColor(COLOR::WHITE);
			}
			else
			{
				SetColor(COLOR::GRAY);
			}
			cout << "Stage" << i + 1;
			SetColor();
		}
		break;
	case InTitleState::INFO:

		IsGotoxy(resolution.X * 0.5f - 5, resolution.Y * 0.45f);
		cout << "[ 혼합 규칙 ]";


		for (int i = 0; i < 3; ++i)
		{
			IsGotoxy(resolution.X * 0.3f * (i + 1) - 15, resolution.Y * 0.5f);
			InfoUIManager::GetInst()->RenderMergeInfoUI(i);
		}

		IsGotoxy(resolution.X * 0.5f - 4, resolution.Y * 0.65f);
		cout << "[ 조작법 ]";

		IsGotoxy(resolution.X * 0.17f, resolution.Y * 0.75f);
		InfoUIManager::GetInst()->InputArrowInfoUI();
		break;
	}

}

