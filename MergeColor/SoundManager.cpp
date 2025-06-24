#include "SoundManager.h"
#include "Mci.h"
SoundManager* SoundManager::instance = nullptr;
void SoundManager::PlayBGM()
{
	InitAllSounds();
	PlaySoundID(SOUNDID::BGM, true);
}

void SoundManager::PlayEffect()
{

}
