#pragma once
#include "defines.h"
class Single
{
private:
	Single() {}
public:
	static Single* GetInst()
	{
		if (instance == nullptr)
			instance = new Single;
		return instance;
	}
	static void DestroyInstance()
	{
		SAFE_DELETE(instance);
		if (instance != nullptr)
		{
			delete instance;
			instance = nullptr;
		}
	}
private:
	static Single* instance;
public:
	bool canInput = true;
};

