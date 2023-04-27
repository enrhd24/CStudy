// 초기화 : 게임에 필요한 데이터 초기화
// 데이터 갱신 : 입력장치에 의한 데이터 갱신
// 화면출력 : 실제 게임이미지 화면에 그리기
// 해제 : 메모리 해제

#include <stdio.h>
#include <conio.h>
#include <Windows.h>

void Init();
void GotoXY(short x, short y);
int ReadyGame(int x, int y);
void Setcursor(BOOL Show);
void Clear(void);

#define MAGIC_KEY 224
#define SPACE 32

enum KEYBOARD{
    UP = 72,
    LEFT = 75,
    RIGHT = 77,
    DOWN = 80
};


int main(){
  
    Init(); // 초기화
   int b_x = 20;

    while(1){ 
        Clear();
        int x = 40; int y = 20;
        
        if(GetAsyncKeyState(VK_LEFT) & 0x8000) { b_x--; if (b_x < 0) b_x = 0;}
		if(GetAsyncKeyState(VK_RIGHT) & 0x8000) { b_x++; if (b_x > 40) b_x = 40; }

        GotoXY(b_x,y);
        printf("A");
        Sleep(5); 
        Setcursor(0); 
    }
    return 0;
}

void Init(){system("mode con cols=56 lines=20 | title GAMETITLE");}

void GotoXY(short x, short y) {
	COORD pos = { x, y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

int ReadyGame(int b_x, int y){
   
}


void Clear(void){
    system("cls");
}

void Setcursor(BOOL Show){
    CONSOLE_CURSOR_INFO curInfo;
    GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
    curInfo.bVisible = Show;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
}


