#pragma once
#include<windows.h>
#include<string>

bool OpenMciDevice(LPCWSTR deviceType, LPCWSTR name,
    UINT& deviced);
void CloseMciDevice(UINT& deviceId);
void PlayMciDevice(UINT deviced, bool repeat = false);

enum class SOUNDID
{
    BGM, MERGE, MOVE
};

struct SoundEntry
{
    //LPCWSTR path;     // ���� ���
    std::wstring path; // ���� ���
    int     volume;  // ���� (0~100)  
    UINT    deviceId; // MCI ��ġ ID (�ʱⰪ 0)
};
// �ʱ�ȭ
bool InitAllSounds();
// ���
void PlaySoundID(SOUNDID _id, bool _repeat = false);
// ������ 
void ReleaseAllSounds();    