https://badayak.com/entry/C%EC%96%B8%EC%96%B4-%ED%8F%AC%EC%9D%B8%ED%84%B0-%EB%B0%B0%EC%97%B4
/*
    C언어로 프로그래밍 하면,
    배열을 포인터로 처리하는 경우가 많다.

    오류 없는 프로그래밍을 하려면 
    배열의 특성도 정확히 알아야 한다.

*/

// C언어 포인터 변수 타입별 차이 -> C언어는 문자 변수에 숫자를 넣어도 가능합니다.
// char[byte], short[2byte], int[4byte], long[64bit-8byte]

// C언어는 변수 형에 따라 크기에 맞추어 포인터의 값이 계산되는 것은 C언어의 배려
// warning떠도 컴파일이 된다면, 당연히 엉뚱한 결과를 내놓습니다.

// C언어는 포인터의 변수 형에 따라 그 크기에 맞추어 걔산합니다.
// char*+1 = +1 , short*+1 = +2 , int*+1 = +4 , long* 64bit of +1 = +8 
// char *ptr , int *ptr;

#include <stdio.h>
struct Init{
    char c_value;
    int n_value;
};

int main(){
    struct Init init;
    printf("%d %d \n", 
    init.c_value = 254,        //0x100
    init.n_value = 4294967294 //0x100000000
    );

    char ary1[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char *ptr1  = ary1; 
    int *ptr2 = ary1;
    printf( "%c ", *(ptr1 +0)); printf( "%c ", *(ptr1 +1));
    printf( "%c ", *(ptr1 +2)); printf( "%c\n", *(ptr1 +3));
    printf( "%c ", *(ptr2 +0)); printf( "%c ", *(ptr2 +1));
    printf( "%c ", *(ptr2 +2)); printf( "%c\n", *(ptr2 +3));

   
    return 0;
}