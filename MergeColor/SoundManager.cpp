#include "SoundManager.h"

SoundManager* SoundManager::instance = nullptr;
void SoundManager::PlayBGM()
{
	InitAllSounds();
	PlaySoundID(SOUNDID::BGM, true);
}

void SoundManager::MciPlayEffect()
{
	PlaySoundID(SOUNDID::MERGE, false);
}

void SoundManager::SoundPlayEffect()
{
	PlaySoundSFX(SOUNDID::MERGE);
}
