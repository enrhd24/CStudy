#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Console.h"

/*
┌───────────────┐
│   c언어 콘솔창 게임 만들기   │
└───────────────┘
*/


int main(void) {
	int x = 15, y = 25;
	int dox = 0, doy = 0; bool bullet = false;
	int upx = 0, upy = 0; bool enemy = false;

	srand(time(NULL)); //프로그램 난수발생 방지.
	SetConsoleSize(30, 30);

	while (1) {
		Clear();

		if(GetAsyncKeyState(VK_LEFT) & 0x8000) { x--; if (x < 5) x = 5;}
		if(GetAsyncKeyState(VK_RIGHT) & 0x8000) { x++; if (x > 25) x = 25;}
		// 사용자의 x좌표 설정

		if (GetAsyncKeyState(VK_SPACE) & 0x8000) {if (!bullet) { dox = x; doy = y-1; bullet = true; }}
		if (bullet) { GotoXY(dox, doy); printf("↑"); doy--; if (doy < 0) bullet = false; }
		// 사용자의 공격 화살표 지정

		if (!enemy) { upx = (rand() % 15) * 2; upy = 0; enemy = true; }
		if (enemy) { GotoXY(upx, upy); printf("☆"); upy++; if (upy > y) { enemy = false; } }
		// 사용자와 만나는 별 만나기 기능

		GotoXY(x, y); // 사용자 시작 문자
		printf("▲"); // 사용자 문자 출력
		Sleep(50);    // 함수 지연함수
		Setcursor(0); // 커서 지우기
	}
	system("pause");
	return 0;
}
