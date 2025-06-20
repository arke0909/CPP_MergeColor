#pragma once
#include<vector>
#include<string>
class AsciiObjects
{
private:
	std::vector<std::wstring> obj;
public:
	void Init();
	void Update();
	void Render();
};

