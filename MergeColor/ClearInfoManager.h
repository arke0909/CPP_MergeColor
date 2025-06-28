#pragma once
#include "Single.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>

class ClearInfoManager : public Single<ClearInfoManager>
{
	friend class Single<ClearInfoManager>;
private:
	std::string const fileName = "ClearInfo.txt";
	ClearInfoManager() {}
	~ClearInfoManager() {}
public:
    void ClearInfoInit();
	std::string CheckClearInfo(int num);
	void SaveClearInfo(int num);
};

