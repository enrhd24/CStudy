
/*
프로그램 소스를 분할하는 이유
1. 프로그램의 구조화
2. 빌드 시간 단축
3. 여러 개발자에 의한 개발
4. 유지보수 향상
*/

#include <stdio.h>

void function();

int main(){
    function();
    function();
}

void function(){
    printf("hello from function No.1\n");
}
