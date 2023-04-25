#include <windows.h>
#include <stdio.h>
#include <conio.h>

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
    

void game_control(){
    int x = 0, y = 0;
    char key;
    while(1){
    draw_check(20, 30);
    CursorView();
    key = getch();

    }
    

}

