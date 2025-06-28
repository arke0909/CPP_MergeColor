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

std::string ClearInfoManager::CheckClearInfo(int num)
{
    std::ifstream inFile(fileName);
    std::string line;
    for (int i = 0; i < num; i++) {
        std::getline(inFile, line);
    }

    inFile.close();
    return line;

}

void ClearInfoManager::SaveClearInfo(int num)
{
    if (num == 10)
        return;
    std::ifstream inFile(fileName);
    if (!inFile.is_open()) return;

    std::string lines[10];
    for (int i = 0; i < 10; i++)
    {
        if (!std::getline(inFile, lines[i]))
        {
            lines[i] = "0";
        }
    }
    inFile.close();

    std::ofstream outFile(fileName);
    if (!outFile.is_open())
        return;

    for (int i = 0; i < 10; i++)
    {
        if (i == num)
            outFile << "2" << '\n';
        else if (i == num + 1)
            outFile << "1" << '\n';
        else
            outFile << lines[i] << '\n';
    }
    outFile.close();
}
