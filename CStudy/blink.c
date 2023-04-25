#include <stdio.h>
#include <conio.h>
#include <windows.h>

void Kbit();
void Getc();
void Getch();
void gotoxy(int x, int y);

int main(void){
    int x, y;
    scanf("%d %d", &x, &y);
    gotoxy(x, y);
    printf("Hello World");
    
    return 0;
   
}

void gotoxy(int x, int y){
    COORD pos = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void Kbit(){
     printf("press any key to start the game \n");
    while(kbhit() == 0){}
    printf("We'll start the game soon^^");
}

void Getc(){
    printf("%c",getc(stdin));
}

void Getch(){
    printf("%c", getch())
;}