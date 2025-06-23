#include "AsciiObjects.h"
#include "Console.h"
#include <io.h>
#include <fcntl.h>
#include<vector>
#include<string>
void AsciiObjects::Init()
{
	obj = {
		" _____   _        ______               _____     _    ",
		"/ ____| | |      |  ____|     /\\      |  __ \\   | |   ",
		"| |     | |      | |__       /  \\     | |__) |  | |   ",
		"| |     | |      |  __|     / /\\ \\    |  _  /   | |   ",
		"| |____ | |____  | |____   / ____ \\   | | \\ \\   |_|   ",
		"\\_____| |______| |______| /_/    \\_\\  |_|  \\_\\  (_)   "
	};
}
void AsciiObjects::Update()
{
	for (std::string& line : obj)
	{
		std::rotate(line.begin(), line.begin() + 1, line.end());
	}
}
void AsciiObjects::Render()
{
	for (int i = 0; i < obj.size(); ++i)
	{
		IsGotoxy(0, i);
		std::cout << obj[i];
	}
	Sleep(10);
}