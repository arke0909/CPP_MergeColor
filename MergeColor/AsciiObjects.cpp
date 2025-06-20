#include "AsciiObjects.h"
#include "Console.h"
#include <io.h>
#include <fcntl.h>
#include<vector>
#include<string>
void AsciiObjects::Init()
{
	obj.push_back(L"	 ██████╗██╗     ███████╗ █████╗ ██████╗ ██╗██╗		");
	obj.push_back(L"	██╔════╝██║     ██╔════╝██╔══██╗██╔══██╗██║██║		");
	obj.push_back(L"	██║     ██║     █████╗  ███████║██████╔╝██║██║		");
	obj.push_back(L"	██║     ██║     ██╔══╝  ██╔══██║██╔══██╗╚═╝╚═╝		");
	obj.push_back(L"	╚██████╗███████╗███████╗██║  ██║██║  ██║██╗██╗		");
	obj.push_back(L"	 ╚═════╝╚══════╝╚══════╝╚═╝  ╚═╝╚═╝  ╚═╝╚═╝╚═╝		");

}
void AsciiObjects::Update()
{
	for(int i = 0; i < obj.size(); i++)
	{
		std::rotate(obj[i].begin(), obj[i].begin() + 1, obj[i].end());
	}
}
void AsciiObjects::Render()
{
	int coutmode = _setmode(_fileno(stdout), _O_U16TEXT);
	SetColor();
	for(int i = 0; i < obj.size(); ++i)
	{
		IsGotoxy(0, obj.size() + i);
		std::wcout << obj[i];
	}
	int wcoutmode = _setmode(_fileno(stdout), coutmode);
}