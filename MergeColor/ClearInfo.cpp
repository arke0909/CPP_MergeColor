#include "ClearInfo.h"
ClearInfo* ClearInfo::instance = nullptr;

// init은 스테이지 정보 초기화라 시작할때 실행 하면 안되고 혹시나 초기화 시켜야할때 실행
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

// check는 스테이지 값 그대로 넣고 save는 -1 해주고 넣어야함

// 들어온 번호 번째 스테이지 클리어 여부 반환
// 매개변수에 스테이지 번호 넣으면 반환
bool ClearInfo::CheckClearInfo(int num)
{
    std::ifstream inFile(fileName);
    std::string line;
    for (int i = 0; i < num; i++) {
        std::getline(inFile, line);
    }

    inFile.close();
    return line == "1";

}
// 들어온 번호 번째 스테이지 클리어 여부 저장
// num에 현제스테이지 -1 넣어주면됌
void ClearInfo::SaveClearInfo(int num, bool isClear = true)
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
