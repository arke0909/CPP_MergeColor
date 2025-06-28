#pragma once
#include "single.h"
#include <string>
#include <fstream>
#include <vector>
class ClearInfoManager : public Single<ClearInfoManager>
{
private:
	std::string const fileName = "ClearInfo.txt";
public:
	ClearInfoManager() {};
    void ClearInfoInit();
	bool CheckClearInfo(int num);
	void SaveClearInfo(int num, bool isClear);
};

