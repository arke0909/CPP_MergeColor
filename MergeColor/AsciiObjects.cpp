#include "AsciiObjects.h"
#include "Console.h"
#include "Enums.h"
#include <io.h>
#include <fcntl.h>
void AsciiObjects::Init()
{
	COORD resolution = GetConsoleResolution();
	width = resolution.X / 2;
	height = resolution.Y / 2;
	clearAscii =
	{
		L" ██████╗██╗     ███████╗ █████╗ ██████╗     ██╗\t\t",
		L"██╔════╝██║     ██╔════╝██╔══██╗██╔══██╗    ██║\t\t",
		L"██║     ██║     █████╗  ███████║██████╔╝    ██║\t\t",
		L"██║     ██║     ██╔══╝  ██╔══██║██╔══██╗    ╚═╝\t\t",
		L"╚██████╗███████╗███████╗██║  ██║██║  ██║    ██╗\t\t",
		L" ╚═════╝╚══════╝╚══════╝╚═╝  ╚═╝╚═╝  ╚═╝    ╚═╝\t\t"
	};
	failAscii =
	{
		L"███████╗ █████╗ ██╗██╗	 \t\t",
		L"██╔════╝██╔══██╗██║██║	 \t\t",
		L"█████╗  ███████║██║██║	 \t\t",
		L"██╔══╝  ██╔══██║██║██║	 \t\t",
		L"██║     ██║  ██║██║███████╗\t\t",
		L"╚═╝     ╚═╝  ╚═╝╚═╝╚══════╝\t\t"
	};
}
void AsciiObjects::Update(InGameState CurGameState)
{
	switch (CurGameState)
	{
	case InGameState::CLEAR:
		for (std::wstring& line : clearAscii)
		{
			std::rotate(line.begin(), line.begin() + 1, line.end());
		}
		break;
	case InGameState::FAIL:
		for (std::wstring& line : failAscii)
		{
			std::rotate(line.begin(), line.begin() + 1, line.end());
		}
		break;
	}

}
void AsciiObjects::Render(InGameState CurGameState)
{
	switch (CurGameState)
	{
	case InGameState::CLEAR:
		int coutmode = _setmode(_fileno(stdout), _O_U16TEXT);
		for (int i = 0; i < clearAscii.size(); ++i)
		{
			IsGotoxy(width, i + height);
			std::wcout << clearAscii[i];
		}
		int wcoutmode = _setmode(_fileno(stdout), coutmode);
		Sleep(10);
		break;
	case InGameState::FAIL:
		int coutmode = _setmode(_fileno(stdout), _O_U16TEXT);
		for (int i = 0; i < failAscii.size(); ++i)
		{
			IsGotoxy(width, i + height);
			std::wcout << failAscii[i];
		}
		int wcoutmode = _setmode(_fileno(stdout), coutmode);
		Sleep(10);
		break;
	}
}