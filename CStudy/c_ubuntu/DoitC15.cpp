/*
    배열과 포인터

    배열   
    -> char data[5];
    -> 배열이 사용하는 메머리 그룹

    포인터 
    -> char *p;
    -> 포인터 변수가 가리킴
    // 배열과 포인터는 표기만 다를 뿐 문법 구조가 유사함.

    배열 변수의 이름은 배열의 시작 주소
    char *p = &data[0];
    char *p = &*(data + 0);    
    char *p = &*data;
    char *p = data;
    // &(*data) == data

    char *p = data + select 
    char *p = &data[select]
    // data + select == &data[select]

    포인터로 배열의 주소를 저장하여 사용하기
    -> 배열은 배열의 시작 주소를 기분으로 색인 작업된 요소의 위치를 계산
    -> 배열의 같은 요소를 반복적으로 사용하는 경우 효율이 떨어짐
    // data[select] 보단 *(data + select)를 사용하자!!

    배열을 기준으로 포인터와 합체하기
    1. char *p[5];
    -> 포인터가 5개 선언된 것이기 때문에 p 배열의 크기는 20byte이다.
    -> 개별 포인터를 사용하려면 ? p[0], p[1], p[2], etc..
    -> 포인터가 가리키는 대상에 값을 사용하려면? *p[0], *p[1], *p[2], etc..

    2. char (*p)[5];
    -> 포인터 p가 배열[5]인 부분을 가리킨다.
    -> (*p)[2] = 7 == p의 시작주소로 부터 2만큼 떨어진 곳에 값을 저장한다.

    ```
    char data[3][5];
    char (*p)[5];
    p = data;
    (*p)[1] = 3;
    (*(p+1))[2] = 4
    ```


*/

#include <stdio.h>

int main(){
    // 포인터로 배열의 주소를 저장하여 사용하기
    char data[5] = {1,2,3,4,5};
    int i, sum = 0, select = 2;

    char *p = data + select // &data[select]
    for(i = 0; i < 10; i++)sum += *p;

    // 배열을 기준으로 포인터와 합체하기
    char Data1, Data2, Data3, Data4, Data5, i;
    // char *p[5] == char *(p[5]) 
    char *p[5] = {&Data1,&Data2,&Data3,&Data4,&Data5};
    for(i = 0; i < 5; i++)*p[i] = 0;
    retunr 0;
}