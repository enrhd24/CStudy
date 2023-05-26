#include <windows.h>
#include <stdio.h>
#include <conio.h>

<<<<<<< HEAD
/*
=======
void gotoxy(int x, int y);
void game_control(void);
void draw_check(int height, int width);
void CursorView();
void intro();

#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define SPACEBAR 32

>>>>>>> 00d41e211739998ed8123ee18b9a9146a0f54ee7
struct Point{
    int x, y;
};

struct Point Shape[7][4][4] = {
     { {0,0,1,0,2,0,-1,0}, {0,0,0,1,0,-1,0,-2}, {0,0,1,0,2,0,-1,0}, {0,0,0,1,0,-1,0,-2} },
     { {0,0,1,0,0,1,1,1}, {0,0,1,0,0,1,1,1}, {0,0,1,0,0,1,1,1}, {0,0,1,0,0,1,1,1} },
     { {0,0,-1,0,0,-1,1,-1}, {0,0,0,1,-1,0,-1,-1}, {0,0,-1,0,0,-1,1,-1}, {0,0,0,1,-1,0,-1,-1} },
     { {0,0,-1,-1,0,-1,1,0}, {0,0,-1,0,-1,1,0,-1}, {0,0,-1,-1,0,-1,1,0}, {0,0,-1,0,-1,1,0,-1} },
     { {0,0,-1,0,1,0,-1,-1}, {0,0,0,-1,0,1,-1,1}, {0,0,-1,0,1,0,1,1}, {0,0,0,-1,0,1,1,-1} },
     { {0,0,1,0,-1,0,1,-1}, {0,0,0,1,0,-1,-1,-1}, {0,0,1,0,-1,0,-1,1}, {0,0,0,-1,0,1,1,1} },
     { {0,0,-1,0,1,0,0,1}, {0,0,0,-1,0,1,1,0}, {0,0,-1,0,1,0,0,-1}, {0,0,-1,0,0,-1,0,1} },
};
*/

char Shape[][4][8] = 
{
	 { {0,0,1,0,2,0,-1,0}, {0,0,0,1,0,-1,0,-2}, {0,0,1,0,2,0,-1,0}, {0,0,0,1,0,-1,0,-2} },
     { {0,0,1,0,0,1,1,1}, {0,0,1,0,0,1,1,1}, {0,0,1,0,0,1,1,1}, {0,0,1,0,0,1,1,1} },
     { {0,0,-1,0,0,-1,1,-1}, {0,0,0,1,-1,0,-1,-1}, {0,0,-1,0,0,-1,1,-1}, {0,0,0,1,-1,0,-1,-1} },
     { {0,0,-1,-1,0,-1,1,0}, {0,0,-1,0,-1,1,0,-1}, {0,0,-1,-1,0,-1,1,0}, {0,0,-1,0,-1,1,0,-1} },
     { {0,0,-1,0,1,0,-1,-1}, {0,0,0,-1,0,1,-1,1}, {0,0,-1,0,1,0,1,1}, {0,0,0,-1,0,1,1,-1} },
     { {0,0,1,0,-1,0,1,-1}, {0,0,0,1,0,-1,-1,-1}, {0,0,1,0,-1,0,-1,1}, {0,0,0,-1,0,1,1,1} },
     { {0,0,-1,0,1,0,0,1}, {0,0,0,-1,0,1,1,0}, {0,0,-1,0,1,0,0,-1}, {0,0,-1,0,0,-1,0,1} },
};

void gotoxy(int x, int y);
void game_control(void);
void draw_check(int height, int width);
void CursorView();
void intro();
   
void ShowBlock(char Shape[][4]);		
void SetCurrentCursorPos(int x, int y);		
COORD GetCurrentCursorPos(void);		

#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define SPACEBAR 32


int main(){
    intro();
    system("cls");
    game_control();
    return 0;
}

void CursorView(){
    CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.dwSize = 1;
	cursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

void intro(){
    printf("Let's start Tertris");
    CursorView();
    getch();
}

void gotoxy(int x, int y){
    COORD pos = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void draw_check(int height, int width){
    int i , j;

    for(i = 0; i < height; i++){
        for( j = 0; j < width; j++){
            if(j == 0)printf("%c%c",0xa6,0xa2);
            else{printf(" ");}
            if(j == width-1)printf("%c%c",0xa6,0xa2);
        }
        printf("\n");
    }
    for(i = 0; i < width; i++){
        if(i == 0)printf("%c%c",0xa6,0xa6);
        else{printf("%c%c",0xa6,0xa1);}
        if(i == width-1)printf("%c%c",0xa6,0xa5);        
    }
}

void ShowBlock(char Shape[][4])
{
	int y, x;
	COORD curPos = GetCurrentCursorPos();		//현재 커서의 위치를 저장한
	for (y = 0; y < 8; y++)
	{
		for (x = 0; x < 8; x++)
		{
			SetCurrentCursorPos(curPos.X + (x * 2), curPos.Y + y);
			// (x*2)인 이유는 특수문자가 출력 시 두칸을 차지하기 때문이다
			if (Shape[y][x] == 1)
				printf("A");
		}
	}
	SetCurrentCursorPos(curPos.X, curPos.Y);	//커서 위치 원래대로
}


void SetCurrentCursorPos(int x, int y)
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);	//pos의 좌표로 이동
}


COORD GetCurrentCursorPos(void)
{
	COORD curPoint;
	CONSOLE_SCREEN_BUFFER_INFO curInfo;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
	curPoint.X = curInfo.dwCursorPosition.X;
	curPoint.Y = curInfo.dwCursorPosition.Y;
	return curPoint;

}


    

void game_control(){
    int x = 0, y = 0;
    char key;
    while(1){
    draw_check(20, 30);
    CursorView();
<<<<<<< HEAD
    SetCurrentCursorPos(0, 0);		// 0,0으로 커서를 이동시킨 후 블럭 출력
	ShowBlock(Shape[0]);		// 블럭을 출력시키기 위한 함수
=======
>>>>>>> 00d41e211739998ed8123ee18b9a9146a0f54ee7
    key = getch();

    }
    

}

