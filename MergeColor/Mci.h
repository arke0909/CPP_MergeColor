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
    //LPCWSTR path;     // 파일 경로
    std::wstring path; // 파일 경로
    int     volume;  // 볼륨 (0~100)  
    UINT    deviceId; // MCI 장치 ID (초기값 0)
};
// 초기화
bool InitAllSounds();
// 재생
void PlaySoundID(SOUNDID _id, bool _repeat = false);
// 릴리즈 
void ReleaseAllSounds();    