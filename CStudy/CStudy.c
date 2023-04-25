#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>


void intro();
void gotoxy(short x, short y);
void game_control(void);
void draw_check(int height, int width);

int main(void)
{
	intro();
	system("cls");
	game_control();
	return 0;
}

void intro(){
	printf("please push keyboard");
	getch();
}
void gotoxy(short x, short y) {
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void draw_check(int height, int width)
{
	int i , j;
	unsigned char a = 0xa6;
    unsigned char b[20];

	for(i = 1; i < width; i++){
		b[i] = 0xa0 + i;
	}
	printf("%c%c", a, b[3]);

	for(i = 0; i < width; i++){
		printf("%c%c",a,b[8]);
	}
	printf("%c%c",a,b[4]);
	printf("\n");

	for(i =0; i < height; i++)
	{
	printf("%c%c",a,b[7]);
	for(j=0;j<20; j++)
	{
	printf("%c%c",a,b[11]);
	}

	printf("%c%c",a,b[9]);
	printf("\n");
	}
	printf("%c%c",a,b[6]);

	for(i=0; i< width; i++){
		printf("%c%c",a,b[10]);
	}
	printf("%c%c",a,b[5]);
	printf("\n");
}


void game_control(void){
	int x = 1, y = 1, other = 0;
	char key;
	do{
		 draw_check(12, 20);
		 
		 key = getch();
	}while(1);
}