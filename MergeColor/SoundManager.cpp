#include "SoundManager.h"

SoundManager* SoundManager::instance = nullptr;
void SoundManager::PlayBGM()
{
	InitAllSounds();
	PlaySoundID(SOUNDID::BGM, true);
}

void SoundManager::PlayEffect()
{
	PlaySoundID(SOUNDID::MERGE, false);
}
