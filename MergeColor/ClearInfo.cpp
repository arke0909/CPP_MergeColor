#include "ClearInfoManager.h"
ClearInfoManager* ClearInfoManager::instance = nullptr;

// init�� �������� ���� �ʱ�ȭ�� �����Ҷ� ���� �ϸ� �ȵǰ� Ȥ�ó� �ʱ�ȭ ���Ѿ��Ҷ� ����
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

// check�� �������� �� �״�� �ְ� save�� -1 ���ְ� �־����

// ���� ��ȣ ��° �������� Ŭ���� ���� ��ȯ
// �Ű������� �������� ��ȣ ������ ��ȯ
bool ClearInfoManager::CheckClearInfo(int num)
{
    std::ifstream inFile(fileName);
    std::string line;
    for (int i = 0; i < num; i++) {
        std::getline(inFile, line);
    }

    inFile.close();
    return line == "1";

}
// ���� ��ȣ ��° �������� Ŭ���� ���� ����
// num�� ������������ -1 �־��ָ��
void ClearInfoManager::SaveClearInfo(int num, bool isClear = true)
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
