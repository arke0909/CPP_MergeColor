#include "AsciiObjects.h"
#include <io.h>
#include <fcntl.h>

void AsciiObjects::Init()
{
	COORD resolution = GetConsoleResolution();
	height = resolution.Y * 0.45f;
	clearAscii =
	{
		L"  ██████╗██╗     ███████╗ █████╗ ██████╗     ██╗                                                ",
		L" ██╔════╝██║     ██╔════╝██╔══██╗██╔══██╗    ██║                                                ",
		L" ██║     ██║     █████╗  ███████║██████╔╝    ██║                                                ",
		L" ██║     ██║     ██╔══╝  ██╔══██║██╔══██╗    ╚═╝                                                ",
		L" ╚██████╗███████╗███████╗██║  ██║██║  ██║    ██╗                                                ",
		L"  ╚═════╝╚══════╝╚══════╝╚═╝  ╚═╝╚═╝  ╚═╝    ╚═╝                                                "
	};
	failAscii =
	{
		L" ███████╗ █████╗ ██╗██╗                                                                          ",
		L" ██╔════╝██╔══██╗██║██║                                                                          ",
		L" █████╗  ███████║██║██║                                                                          ",
		L" ██╔══╝  ██╔══██║██║██║                                                                          ",
		L" ██║     ██║  ██║██║███████╗██╗██╗                                                               ",
		L" ╚═╝     ╚═╝  ╚═╝╚═╝╚══════╝╚═╝╚═╝                                                               "

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
	int coutmode = _setmode(_fileno(stdout), _O_U16TEXT);
	switch (CurGameState)
	{
	case InGameState::CLEAR:
		for (int i = 0; i < clearAscii.size(); ++i)
		{
			IsGotoxy(0, i + height);
			std::wcout << clearAscii[i];
		}
		break;
	case InGameState::FAIL:
		for (int i = 0; i < failAscii.size(); ++i)
		{
			IsGotoxy(0, i + height);
			std::wcout << failAscii[i];
		}
		break;
	}
	int wcoutmode = _setmode(_fileno(stdout), coutmode);
	Sleep(10);
}