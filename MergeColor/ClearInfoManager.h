#pragma once
#include "Single.h"
#include <string>
#include <fstream>
#include <vector>
class ClearInfoManager : public Single<ClearInfoManager>
{
	friend class Single<ClearInfoManager>;
private:
	std::string const fileName = "ClearInfo.txt";
	ClearInfo() {}
	~ClearInfo() {}
public:
    void ClearInfoInit();
	bool CheckClearInfo(int num);
	void SaveClearInfo(int num, bool isClear);
};

