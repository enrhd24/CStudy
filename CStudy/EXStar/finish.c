#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Console.h"

/*
┌───────────────┐
│   c언어 콘솔창 게임 만들기   │
└───────────────┘
 1. 함수화 처리
 2. 충동 처리      - player 이동은 +2 칸씩 이동 처리
 3. 게임 종료 처리 - 생성된 별만 다 내려오면 게임 종료

*/
void Spawn(void);
int EnemyProcess(void);
void InputProcess(void);
void Update(void);
void Score(void);
void Init(void);

#define MAX 30
int score = 0;

struct ST_OBJECT {
	int x = 0;
	int y = 0;
	bool Active = false;
};

ST_OBJECT st_object[MAX];
ST_OBJECT st_objects;

int main(void) {
	int state = 1;
	Init();

	while (1) {
		Clear();

		if (st_objects.Active) {
			Spawn(); //별 생성
			InputProcess(); //input 처리
		}

		state = EnemyProcess(); //별 처리

		//player 출력
		Update();
		Score();
		Sleep(50);
		if (state == 0) break;


	}
		system("pause");
		return 0;
	
}



//별의 개수를 출력해주는 함수
void Spawn(void){
	for (int i = 0; i < MAX; i++) {
		if (st_object[i].Active) {
			st_object[i].x = (rand() % 15) * 2;
			st_object[i].y = 0;
			st_object[i].Active = true;
			break;}}} 


// 키보드를 입력받을 함수
void InputProcess(void){
	if (GetAsyncKeyState(VK_LEFT) & 0x8000) {st_objects.x -= 2;if (st_objects.x < 0)st_objects.x = 0;}
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {st_objects.x += 2;if (st_objects.x > 28)st_objects.x = 28;}
}

// 점수를 출력하는 함수 [전역변수 사용]
void Score(void) {
	if (st_object->Active)score++;
	GotoXY(0, 0);
	printf("Score : %d", score);
}

// 키보드 입력시 변화시켜주는 문자 함수 
void Update(void){
	if (st_object->Active) {
		GotoXY(st_objects.x, st_objects.y);
		printf("▲");
	}
	else {
		GotoXY(st_objects.x, st_objects.y);
		printf(" ");}}

// 충돌 처리 함수
int EnemyProcess(void) {
	int cnt = 0;
	for (int i = 0; i < MAX; i++) {
		if (st_object->Active) {
			cnt++;
			GotoXY(st_object[i].x, st_object[i].y);
			printf("☆");
			st_object[i].y++;

			if (st_object[i].y == st_objects.y)st_object->Active = false;
			if (st_object[i].y > st_objects.y)st_object->Active = false;
		}
	}
	return cnt;
}

void Init(void) {
	st_objects.x = 14;
	st_objects.y = 28;
	st_objects.Active = true;

	srand(time(NULL));
	SetConsoleSize(30, 30);
}
