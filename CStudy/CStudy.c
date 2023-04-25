#include <stdio.h> // c언어 공부할 때 입출력 용도로 알고있다.
#include <stdlib.h> // 이것의 용도로 모른다.
#include <conio.h> // 무슨헤더인지 모른다
#include <Windows.h> //콘솔에 창띄우기


void intro();
void gotoxy(short x, short y);
void game_control(void);
void draw_check(int height, int width);

void display_stone(int matrix[][20][12]);
void move_arrow_key(char key, int *x1, int *y1, int x_b, int y_b);

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
	COORD pos = { x-1, y-1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void draw_check(int height, int width)
{
	int i , j;
	unsigned char a = 0xa6;
    unsigned char b[20];

	for(i = 1; i < width; i++){
		b[i] = 0xa0 + i; 
		//특수문자 넣기 위한 배열 초기화
	}

	printf("%c%c", a, b[3]);
	for(i = 0; i < width; i++){
		printf("%c%c",a,b[8]);
	}
	printf("%c%c",a,b[4]);
	printf("\n"); 
	// 첫번째 출 입력

	for(i =0; i < height; i++)
	{
	printf("%c%c",a,b[7]);
	for(j=0;j<20; j++)
	{
	printf("%c%c",a,b[11]);
	} 
	printf("%c%c",a,b[9]);
	printf("\n");
	} // 중간째 줄 모두 입력

	printf("%c%c",a,b[6]);
	for(i=0; i< width; i++){
		printf("%c%c",a,b[10]);
	}
	printf("%c%c",a,b[5]);
	printf("\n");
	// 마지막 줄 입력
}

void display_stone(int matrix[][20][12]){
	int i, x, y;
	char *stone[2] = {"A", "B"};
	for(i =0; i < 2; i++){
		for(x = 1; x < 20; x++){
			for(y = 1; y < 12; y++){
				if(matrix[i][x][y] == 1){
					gotoxy(x*2 - 1, y);
					printf("%s",stone[i]);
				}
			}
		}
	}
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

void game_control(void){
	int x = 1, y = 1, other = 0;
	int matrix[2][20][12] = {0};
	char key;
	char *stone[2] = {"A","B"};
	do{
		 gotoxy(1,1); // 시작점 출발
		 draw_check(12, 20); //바둑반 그리기
		 gotoxy(x,y); // 말 시작점 초기화
		 printf("%s",stone[other]); // 말 올리기

		 gotoxy(1,15); //메시지 입력 란
		 printf("please using gosString\n");
		printf("and push Keyboard");// 메시지 입력하기
		 key = getch();
		 
		 if(key == 27){exit(0);}
		else if (key == 32)
               {
                       matrix[other][(x + 1) / 2][y] = 1;
                       other = 1 - other;
               }
               else if (key >= 72)
                       move_arrow_key(key, &x, &y, 37, 19);
               

	}while(1);
}