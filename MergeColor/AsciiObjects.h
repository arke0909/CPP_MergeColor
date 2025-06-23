#pragma once
#include<vector>
class AsciiObjects
{
private:
	std::vector<std::wstring> clearAscii;
	std::vector<std::wstring> failAscii;
	int width;
	int height;
public:
	AsciiObjects() 
	{
		Init();
	}

	void Init();
	void Update(InGameState CurGameState);
	void Render(InGameState CurGameState);
};

