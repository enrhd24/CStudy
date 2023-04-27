#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

void intro();
void GotoXY(short x, short y);
void game_control(void);
void draw_check(int height, int width); // 높이, 가로
void Setcursor(BOOL _bShow);
void display_game(void);

struct ST_OBJECT{
    int x;
    int y;
    int Active;
};

int main(void) {
	intro();
	system("cls");
	game_control();
	return 0;
}

void intro() {;
	printf("please push keyboard");
	getch();
}

void GotoXY(short x, short y) {
	COORD pos = { x-1 , y-1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void draw_check(int width, int height){
    int i , j;

    for(i = 0; i < width; i++){
        if(i == 0)printf("%c%c",0xa6,0xa3);
        else{printf("%c%c",0xa6,0xa1);}
        if(i == width-1)printf("%c%c",0xa6,0xa4);        
    }

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

void game_control(void) {
	int x = 40, y = 30;
   
	char key;

	while (1) {
		
        draw_check(x,y);
        display_game();
        Setcursor(0);
		
        key = getch();
        
        if(key == 27){exit(0);}

        
  
	}
}

void display_game(void){
     int tx = 20, ty = 28;
    GotoXY(tx, ty);
    printf("A");
    //if (GetAsyncKeyState(VK_LEFT) & 0x8000) {tx -= 2; if (tx < 2)tx = 2;}
    //if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {tx += 2; if (tx > 28)tx = 28;}
}

void Setcursor(BOOL _bShow){
    CONSOLE_CURSOR_INFO curInfo;
    GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
    curInfo.bVisible = _bShow;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
}
