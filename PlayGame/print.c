#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Console.h"

/*
┌───────────────┐
│   c언어 콘솔창 게임 만들기   │
└───────────────┘
*/
#define MAX 30

struct ST_ENEMY {
	int x = 0;
	int y = 0;
	bool enemy = false;
};

int main(void) {
	int x = 14, y = 28;
	int dox = 0, doy = 0; bool bullet = false;
	
	ST_ENEMY stEnemt[MAX];

	srand(time(NULL)); //프로그램 난수발생 방지.
	SetConsoleSize(30, 30); //프로그램 사이즈 선정.

	while (1) {
		Clear();

		if(GetAsyncKeyState(VK_LEFT) & 0x8000) { x--; if (x < 0) x = 0;}
		if(GetAsyncKeyState(VK_RIGHT) & 0x8000) { x++; if (x > 28) x = 28;}
		// 사용자의 x좌표 설정

		if (GetAsyncKeyState(VK_SPACE) & 0x8000) {if (!bullet) { dox = x; doy = y-1; bullet = true; }}
		if (bullet) { GotoXY(dox, doy); printf("↑"); doy--; if (doy < 0) bullet = false; }
		// 사용자의 공격 화살표 지정

		for (int i = 0; i < MAX; i++) {
			if (!stEnemt[i].enemy) { stEnemt[i].x = (rand() % 15) * 2; stEnemt[i].y = 0; stEnemt[i].enemy = true; break; } }
		    // (rand()%15) *2 0~15의 라인을 2개 만들기 - 스위칭회로
		for (int i = 0; i < MAX; i++) {
			if(stEnemt[i].enemy){GotoXY(stEnemt[i].x, stEnemt[i].y); printf("☆"); stEnemt[i].y++;
			if (stEnemt[i].y > y) { stEnemt[i].enemy= false; }}}
		    // 해당 별을 출하는 처리문
		// 사용자와 만나는 별 만나기 기능

		GotoXY(x, y); // 사용자 시작 문자
		printf("▲"); // 사용자 문자 출력
		Sleep(50);    // 함수 지연함수
		Setcursor(0); // 커서 지우기
	}
	system("pause");
	return 0;
}
