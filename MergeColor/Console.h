#pragma once
#include <iostream>
using std::cout;
using std::wcout;
using std::endl;
#include <string>
using std::string;
using std::wstring;
#include <windows.h>

void SetConsoleSettings(int width, int height,
	bool isFullScreen, const std::wstring& _title);
void SetLockResize();
COORD GetConsoleResolution();
BOOL IsGotoxy(int x, int y);
COORD CursorPos();
void SetCursorVisual(bool isVis, DWORD size);

enum class COLOR
{
	BLACK, BLUE, GREEN, SKYBLUE, RED,
	VOILET, YELLOW, LIGHT_GRAY, GRAY, LIGHT_BLUE,
	LIGHT_GREEN, MINT, LIGHT_RED, LIGHT_VIOLET,
	LIGHT_YELLOW, WHITE, END
};

void SetColor(COLOR textColor = COLOR::WHITE,
	COLOR bgColor = COLOR::BLACK);
void FrameSync(unsigned int frame);
void SetConsoleFont(LPCWSTR _fontname, COORD _size, UINT _weight);

