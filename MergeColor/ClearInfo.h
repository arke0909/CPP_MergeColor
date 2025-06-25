#pragma once
#include <string>
#include <fstream>
#include <vector>
class ClearInfo
{
private:
	std::string const fileName = "ClearInfo.txt";
public:
	ClearInfo() {};
    void ClearInfoInit();
	bool CheckClearInfo(int num);
	void SaveClearInfo(int num, bool isClear);
};

