#include "Mci.h"
#include<mmstream.h>
#include<Digitalv.h>
#include "Console.h"
#include<vector>
#pragma comment(lib, "winmm.lib")

static std::vector<SoundEntry> SoundTable =
{
	{ L"Resource\\Sound\\BackgroundMusic.mp3", 1000, 0 },
	{ L"Resource\\Sound\\MergeEffect.wav", 100, 0 }
};

bool OpenMciDevice(LPCWSTR deviceType, LPCWSTR name, UINT& deviceid)
{
	MCI_OPEN_PARMS openParams = {};
	openParams.lpstrDeviceType = deviceType; // ex. mpegvideo, waveaudio
	openParams.lpstrElementName = name; // 파일 경로(이름)

	if (mciSendCommand(0, MCI_OPEN, MCI_OPEN_TYPE | MCI_OPEN_ELEMENT, (DWORD_PTR)&openParams) != 0)
	{
		// 오류 발생 시 false 반환
		return false;
	}

	deviceid = openParams.wDeviceID; // 할당된 장치 ID 반환
	return true;
	// 1. 디바이스 아이디
	// 2. 디바이스한테 보낼 메세지
	// -> open, pause, seek, close, play
	// 3. 메세지에 대한 플래그
	// -> repeat, notipy
	// 4. 추가 주소
	// -> 정해진 구조체 전달

	// 오픈 : 파일을 사운드 드라이버에 올려서 그 메모리를 읽어오기 위해
	// 아이디를 발급받는 것
	//MCI_OPEN_PARMS;

	//// 플레이
	//MCI_PLAY_PARMS;

	//return false;
}

void CloseMciDevice(UINT& deviceId)
{
	if (deviceId != 0)
	{
		// RAII: 자원 해제
		mciSendCommand(deviceId, MCI_CLOSE, 0, 0);
		deviceId = 0; // 중복 닫기 방지
	}
}

void PlayMciDevice(UINT deviceId, bool repeat)
{
	MCI_PLAY_PARMS playParams = {};
	DWORD_PTR playFlags = repeat ? MCI_DGV_PLAY_REPEAT : MCI_NOTIFY; // 0은 기본 재생
	if (repeat == false && deviceId != 0)
		mciSendCommand(deviceId, MCI_SEEK, MCI_SEEK_TO_START, (DWORD_PTR)&playParams);
	mciSendCommand(deviceId, MCI_PLAY, playFlags, (DWORD_PTR)&playParams);
}

bool InitAllSounds()
{
	for (auto it = SoundTable.begin(); it != SoundTable.end(); ++it)
	{
		// 경로가 비어 있으면 로드하지 않음
		if (it->path.empty())
			continue;

		// 디바이스 종류 판단         // C스타일: wcs1에서 wcs2의 첫번째 표시를 찾는다.
		//LPCWSTR devType = (wcsstr(it->path.c_str(), L".mp3") != NULL) 
		bool isMpeg = it->path.ends_with(L".mp3");
		LPCWSTR devType = isMpeg // C++20: 주어진 부분 문자열로 끝나는지 검사
			? TEXT("mpegvideo")
			: TEXT("waveaudio");

		// 열기
		if (!OpenMciDevice(devType, it->path.c_str(), it->deviceId))
			return false;

		// 볼륨 설정 mp3만 가능
		if (isMpeg)
		{
			std::wstring volumeCommand = L"setaudio " + it->path +
				L" volume to " + std::to_wstring(it->volume);
			mciSendString(volumeCommand.c_str(), NULL, NULL, NULL);
		}
	}
	return true;
	return false;
}

void PlaySoundID(SOUNDID _id, bool _repeat)
{
	// 확인 후 처리
	UINT devId = SoundTable[(int)_id].deviceId;
	if (devId == 0)
		return;
	// 정상 재생
	PlayMciDevice(devId, _repeat);
}

void PlaySoundSFX(SOUNDID _id)
{
	LPCWSTR path = SoundTable[(int)_id].path.c_str();
	PlaySound(path, NULL, SND_ASYNC);
}

void ReleaseAllSounds()
{
	for (auto& sound : SoundTable)
	{
		CloseMciDevice(sound.deviceId);
	}
}
