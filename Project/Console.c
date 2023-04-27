#include <stdio.h>
#include <windows.h>

void GotoXY(short x, short y);

int main(void){
    int pos1 = 0, pos2 = 0;

    while(1){
        system("cls");
        pos1++; pos2++;

        if(pos1 > 20) pos1 = 20;
        if(pos2 > 20) pos2 = 20;

        GotoXY(10+pos1,5);
        printf("test1");

        GotoXY(10+pos2,20);
        printf("test2");
        Sleep(70);
    }
    return 0;
}

void GotoXY(short x, short y) {
	COORD pos = { x-1, y-1};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}