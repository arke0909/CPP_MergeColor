#include "ClearInfo.h"
// init은 스테이지 정보 초기화 함수
void ClearInfo::ClearInfoInit()
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
// 들어온 번호 번째 스테이지 클리어 여부 반환 
bool ClearInfo::CheckClearInfo(int num)
{
    std::ifstream inFile(fileName);
    if (!inFile.is_open()) 
        return false;

    std::string line;
    for (int i = 0; i < num; i++) {
        if (!std::getline(inFile, line)) 
            return false;
    }

    inFile.close();
    return line == "1";
}
// 들어온 번호 번째 스테이지 클리어 여부 저장
void ClearInfo::SaveClearInfo(int num, bool isClear)
{
    std::ifstream inFile(fileName);
    if (!inFile.is_open()) return;
    
    std::string line;
    for (int i = 0; i < 10; i++) 
    {
		std::getline(inFile, line);
        if(i == num)
            line = isClear ? "1" : "0";
    }
	inFile.close();

    std::ofstream outFile(fileName);
    if (!outFile.is_open()) 
        return;

    for (int i = 0; i < 10; i++) 
    {
        if (i == num) 
            outFile << line;
        outFile << '\n';
    }
    outFile.close();
}
