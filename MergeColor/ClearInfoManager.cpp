#include "ClearInfoManager.h"
ClearInfoManager* ClearInfoManager::instance = nullptr;

void ClearInfoManager::ClearInfoInit()
{
    std::ofstream outFile(fileName);
    if (outFile.is_open())
    {
        outFile << "1\n";
        for (int i = 0; i < 9; i++)
        {
            outFile << "0\n";
        }

        outFile.close();
    }
}

bool ClearInfoManager::CheckClearInfo(int num)
{
    std::ifstream inFile(fileName);
    std::string line;
    for (int i = 0; i < num; i++) {
        std::getline(inFile, line);
        std::cout << line << ' ';
    }

    inFile.close();
    return line == "1";

}

void ClearInfoManager::SaveClearInfo(int num)
{
    std::ifstream inFile(fileName);
    if (!inFile.is_open()) return;
    
    std::string line;
    for (int i = 1; i <= 10; i++) 
    {
		std::getline(inFile, line);
        if(i == num)
            line = "1";
    }
	inFile.close();

    std::ofstream outFile(fileName);
    if (!outFile.is_open()) 
        return;

    for (int i = 1; i <= 10; i++) 
    {
        if (i == num) 
            outFile << line;
        outFile << '\n';
    }
    outFile.close();
}
