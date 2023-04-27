#pragma once
#include <windows.h>

void Clear(void);
void GotoXY(int _x, int _y);
void SetTitle(char * _szConsoleName);
void SetColor(unsigned char _BgColor, unsigned char _TextColor);
void Setcursor(BOOL _bShow);
void SetConsoleSize(int _col, int _lines);