#include "ClearInfoManager.h"

ClearInfoManager* ClearInfoManager::instance = nullptr;

void ClearInfoManager::CheckClearInfo(int num)
{
	if(!inFile)
		std::ifstream inFile(fileName);

}

void ClearInfoManager::SaveClearInfo(int num)
{
	if (!inFile)
		std::ifstream inFile(fileName);
}
