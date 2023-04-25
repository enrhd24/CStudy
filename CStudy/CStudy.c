#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>


void intro();
void gotoxy(short x, short y);
void game_control(void);
void draw_check(int c, int r);

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

void draw_check(int c, int r)
{
        int i, j;
        unsigned char a = 0xa6;
        unsigned char b[12];
        for (i = 1; i < 12; i++)
               b[i] = 0xa0 + i;
        printf("%c%c", a, b[3]);
        for (i = 0; i < c - 1; i++)
               printf("%c%c", a, b[8]);
        printf("%c%c", a, b[4]);
        printf("\n");
        for (i = 0; i < r - 1; i++)
        {
               printf("%c%c", a, b[7]);
               for (j = 0; j < c - 1; j++)
                       printf("%c%c", a, b[11]);
               printf("%c%c", a, b[9]);
               printf("\n");
        }
        printf("%c%c", a, b[6]);
        for (i = 0; i < c - 1; i++)
               printf("%c%c", a, b[10]);
        printf("%c%c", a, b[5]);
        printf("\n");
}
void display_stone(int matrix[][20][20])
{
        int i, x, y;
        char *stone[2] = { "A", "B" };
        for (i = 0; i < 2; i++)
               for (x = 1; x < 20; x++)
                       for (y = 1; y < 20; y++)
                       {
                              if (matrix[i][x][y] == 1)
                              {
                                      gotoxy(x * 2 - 1, y);
                                      printf("%s", stone[i]);
                              }
                       }
}

void game_control(void){
	int x = 1, y = 1, other = 0;
	 int matrix[2][20][20] = { 0 };
	 char *stone[2] = { "A", "B" };
	char key;
	do{
		 draw_check(18, 18);
		  printf("%s", stone[other]);
               display_stone(matrix);
		 key = getch();
	}while(1);
}