#pragma once
#include "Single.h"
#include <string>
#include <fstream>
class ClearInfoManager : public Single<ClearInfoManager>
{
	friend class Single<ClearInfoManager>;
private:
	ClearInfoManager() {};
	~ClearInfoManager() {}
	std::string const fileName = "ClearInfo.txt";
	std::ifstream inFile;
public:
	void CheckClearInfo(int num);
	void SaveClearInfo(int num);
};

