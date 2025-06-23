#pragma once
#include<vector>
#include<string>
class AsciiObjects
{
private:
	std::vector<std::wstring> obj;
	int width;
	int height;
public:
	void Init(InGameState CurGameState);
	void Update();
	void Render();
};

