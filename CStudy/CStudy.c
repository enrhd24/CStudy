// https://m.blog.naver.com/PostView.naver?isHttpsRedirect=true&blogId=dgsw102&logNo=221020139485
#include <windows.h>
#include <stdio.h>
#include <time.h>

void cur(short x, short y) {
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
int main(void)
{
	int i;
	for (i = 0; i < 100; i++)
	{
		printf("%d%%", i);
		Sleep(10);
		cur(0, 0);
	}
	printf("총 %d초가 경과되었습니다.", clock() / 1000); //필자는 10 * 100 ms 즉 1초를 기대하였다.
}