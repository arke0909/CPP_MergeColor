#pragma once
#include "Single.h"
#include "Mci.h"
class SoundManager : public Single<SoundManager>
{
	friend class Single<SoundManager>;
private:
	SoundManager() {}
	~SoundManager() {}
public:
	void PlayBGM();
	void MciPlayEffect();
	void SoundPlayEffect();
};

