#pragma once
#include<vector>
#include<string>
class AsciiObjects
{
private:
	std::vector<std::string> obj;
public:
	void Init();
	void Update();
	void Render();
};

