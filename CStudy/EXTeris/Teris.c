#include<stdio.h>
#include<windows.h>

void ShowBlock(char blockInfo[][4]);		//콘솔 출력 차에 블록을 그리는 역활
void SetCurrentCursorPos(int x, int y);		//전달 인자로 좌표값을 입력 받아서 커서의 위치 이동
COORD GetCurrentCursorPos(void);			//현재 커서 정보를 반환

char blockModel[][4][4] = 
{
	{{0,0,0,0},{1,0,0,0},{1,1,1,0},{0,0,0,0} },
	{{ 0,1,0,0 },{ 0,1,0,0 },{ 1,1,0,0 },{ 0,0,0,0 } },
	{{ 0,0,0,0 },{ 1,1,1,0 },{ 0,0,1,0 },{ 0,0,0,0 } },
	{{ 0,0,0,0 },{ 1,1,0,0 },{ 1,0,0,0 },{ 1,0,0,0 } }
};

int main(void)
{
	SetCurrentCursorPos(0, 0);		// 0,0으로 커서를 이동시킨 후 블럭 출력
	ShowBlock(blockModel[0]);		// 블럭을 출력시키기 위한 함수

	SetCurrentCursorPos(0, 8);
	ShowBlock(blockModel[1]);

	SetCurrentCursorPos(12, 0);
	ShowBlock(blockModel[2]);
    
	SetCurrentCursorPos(12, 8);
	ShowBlock(blockModel[3]);
	getchar();
	return 0;
}


void ShowBlock(char blockInfo[][4])
{
	int y, x;
	COORD curPos = GetCurrentCursorPos();		//현재 커서의 위치를 저장한
	for (y = 0; y < 4; y++)
	{
		for (x = 0; x < 4; x++)
		{
			SetCurrentCursorPos(curPos.X + (x * 2), curPos.Y + y);
			// (x*2)인 이유는 특수문자가 출력 시 두칸을 차지하기 때문이다
			if (blockInfo[y][x] == 1)
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
