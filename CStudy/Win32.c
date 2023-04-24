#include <Windows.h>
//윈도우즈 API의 제공 형식과 기능을 사용하기 위해 포함

INT APIENTRY WinMain(HINSTANCE hIns, HINSTANCE hPrev, LPSTR cmd, INT nShow)
{
    MessageBox(
        0, 
        TEXT("첫 번재 윈도우즈 프로그램입니다."), 
        TEXT("메시지 창 띄위기"), 
        MB_OK
    );
    return 0;
}