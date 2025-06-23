#include "AsciiObjects.h"
#include "Console.h"
#include "Enums.h"
#include <io.h>
#include <fcntl.h>
#include<vector>
#include<string>
void AsciiObjects::Init(InGameState CurGameState)
{
	COORD resolution = GetConsoleResolution();
	width = resolution.X / 2;
	height = resolution.Y / 2;
	switch (CurGameState)
	{
	case InGameState::CLEAR:
		obj =
		{
			 L" ██████╗██╗     ███████╗ █████╗ ██████╗     ██╗        ",
	L"██╔════╝██║     ██╔════╝██╔══██╗██╔══██╗    ██║        ",
	L"██║     ██║     █████╗  ███████║██████╔╝    ██║        ",
	L"██║     ██║     ██╔══╝  ██╔══██║██╔══██╗    ╚═╝        ",
	L"╚██████╗███████╗███████╗██║  ██║██║  ██║    ██╗        ",
	L" ╚═════╝╚══════╝╚══════╝╚═╝  ╚═╝╚═╝  ╚═╝    ╚═╝        "
		};
		break;
	case InGameState::FAIL:
		obj =
		{
			L"███████╗ █████╗ ██╗██╗	        ",
			L"██╔════╝██╔══██╗██║██║	        ",
			L"█████╗  ███████║██║██║	        ",
			L"██╔══╝  ██╔══██║██║██║	        ",
			L"██║     ██║  ██║██║███████╗       ",
			L"╚═╝     ╚═╝  ╚═╝╚═╝╚══════╝       "
		};
		break;
	}
}
void AsciiObjects::Update()
{
	for (std::wstring& line : obj)
	{
		std::rotate(line.begin(), line.begin() + 1, line.end());
	}
}
void AsciiObjects::Render()
{
	int coutmode = _setmode(_fileno(stdout), _O_U16TEXT);
	for (int i = 0; i < obj.size(); ++i)
	{
		IsGotoxy(width, i + height);
		std::wcout << obj[i];
	}
	int wcoutmode = _setmode(_fileno(stdout), coutmode);
	Sleep(10);
}