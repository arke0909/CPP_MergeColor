#pragma once
#include "defines.h"
template<typename T>
class Single
{
protected:
	Single() {}
	~Single() {}
public:
	static T* GetInst()
	{
		if (instance == nullptr)
			instance = new T;
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
protected:
	static T* instance;
};

