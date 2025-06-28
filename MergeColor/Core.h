#pragma once
#include "SceneManager.h"
#include "SoundManager.h"
#include "ClearInfoManager.h"
#include "Console.h"
class Core
{
public:
	void Run();
private:
	void Init();
	void Update();
	void Render();
};

