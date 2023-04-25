#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>

#define one 24
#define two 12


void intro();
void move_arrow_key(char chr, int *x, int *y, int x_b, int y_b);
void gotoxy(int x, int y);
void draw_check01(int height, int width);
void game_control(void);
void display_stone(int matrix[][20][20]);
int game_end(int matrix[][20][20]);

 

int main(void)
{
        intro();
        system("cls");
        game_control();
        return 0;
}

 
void intro()
{
        printf("please push keyboard");
        getch();
}

 
void gotoxy(int x, int y)
{
        COORD Pos = { x-1 , y-1 };
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

 
void move_arrow_key(char key, int *x1, int *y1, int x_b, int y_b)
{
        switch (key)
        {
        case 72:
               *y1 = *y1 - 1; //위쪽 방향의 화살표 키 입력
               if (*y1 < 1)
                       *y1 = 1;
               break;
        case 75:
               *x1 = *x1 - 2; //왼쪽 방향의 화살표 키 입력
               if (*x1 < 1)
                       *x1 = 1;
               break;
        case 77:
               *x1 = *x1 + 2; //오른쪽 방향의 화살표 키 입력
               if (*x1 > x_b)
                       *x1 = x_b;
               break;
        case 80:
               *y1 = *y1 + 1; //아래쪽 방향의 화살표 키 입력
               if (*y1 > y_b)
                       *y1 = y_b;
               break;
        default:
               return;
        }
}

void draw_check01(int height, int width)
{
      int i , j;
	unsigned char a = 0xa6;
        unsigned char b[one];

	for(i = 1; i < 12; i++){
		b[i] = 0xa0 + i; 
		//특수문자 넣기 위한 배열 초기화
	}

	printf("%c%c", a, b[3]);
	for(i = 0; i < width; i++){
		if(i%2 == 0)printf("%c%c",a,b[1]);
		else{printf("%c%c",a,b[4]);}
	}
	//printf("%c%c",a,b[4]);
	printf("\n"); 
	// 첫번째 출 입력

	for(i =0; i < height; i++)
	{
	printf("%c%c",a,b[7]);
	for(j=0;j<width; j++)
	{
		if(j%2 == 0)printf("%c%c",a,b[1]);
		else{printf("%c%c",a,b[9]);}
	} 
	//printf("%c%c",a,b[2]);
	printf("\n");
	} // 중간째 줄 모두 입력

	printf("%c%c",a,b[6]);
	for(i=0; i< width; i++){
		if(i%2 == 0)printf("%c%c",a,b[1]);
		else{printf("%c%c",a,b[5]);}
	}
	//printf("%c%c",a,b[5]);
	printf("\n");
	// 마지막 줄 입력
}

void game_control(void)
{
        int x = 1, y = 1, other = 0;
        int matrix[2][20][20] = { 0 };
        char key;
        char *stone[2] = { "0", "@" };
        do
        {
               gotoxy(1, 1);
               draw_check01(18, 18);
               gotoxy(x, y);
               printf("%s", stone[other]);
               display_stone(matrix);

               key = getch();
               if (key == 27)
                       exit(0);
               else if (key == 32)
               {
                       matrix[other][(x + 1) / 2][y] = 1;
                       other = 1 - other;
               }
               else if (key >= 72)
                       move_arrow_key(key, &x, &y, 37, 19);
               if (game_end(matrix) == 1)
               {
                       gotoxy(1, 24);
                       printf("흑돌이 이겼습니다\n");
                       break;
               }
               else if (game_end(matrix) == 2)
               {
                       gotoxy(1, 24);
                       printf("백돌이 이겼습니다\n");
                       break;
               }
        } while (1);
}

void display_stone(int matrix[][20][20])
{
        int i, x, y;
        char *stone[2] = { "0", "@" };
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


int game_end(int matrix[][20][20])
{
        int count = 0;
        for (int i = 0; i < 2; i++)
        {
               for (int y = 1; y < 20; y++)
               {
                       count = 0; //새로운 줄일 때는 count=0으로 시작
                       for (int x = 1; x < 20; x++)
                       {
                              if (matrix[i][x][y])
                                      count++;
                              else
                                      count = 0;
                              if (count == 5)
                                      return (i + 1);
                       }
               }
        }

        for (int i = 0; i < 2; i++)
        {
               for (int x = 1; x < 20; x++)
               {
                       count = 0; //새로운 줄일 때는 count=0으로 시작
                       for (int y = 1; y < 20; y++)
                       {
                              if (matrix[i][x][y])
                                      count++;
                              else
                                      count = 0;
                              if (count == 5)
                                      return (i + 1);
                       }
               }
        }

        for (int i = 0; i < 2; i++)
        {
               for (int x = 1; x < 16; x++) //대각선이므로 15까지가 마지노선
               {
                       count = 0; //새로운 대각선일 때는 count=0으로 시작
                       for (int y = 1; y < 16; y++) //대각선이기 때문에 15까지가 마지노선
                       {
                              int temp1 = x; //x와 y값을 저장
                              int temp2 = y;
                              for (int j = 0; j < 5; j++)
                              {
                                      if (matrix[i][temp1++][temp2++])
                                              count++;
                                      else
                                              count = 0;
                              }
                              if (count == 5)
                                      return (i + 1);
                       }
               }
        }
        for (int i = 0; i < 2; i++)
        {
               for (int x = 1; x < 16; x++) //대각선이므로 15까지가 마지노선
               {
                       count = 0;
                       for (int y = 5; y < 20; y++) //대각선이기 때문에 5부터 시작
                       {
                              int temp1 = x;
                              int temp2 = y;
                              for (int j = 0; j < 5; j++)
                              {
                                      if (matrix[i][temp1++][temp2--])
                                              count++;
                                      else
                                              count = 0;
                              }
                              if (count == 5)
                                      return (i + 1);
                       }
               }
        }
        return 0; 

}

