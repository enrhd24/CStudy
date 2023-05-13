/*
    표준 입력 함수란?
    -> 장치의 입력을 읽는 것을 파일에서 데이터를 읽는 것처럼 구성한다.
    ex> 컴퓨터로 부터 입력받는 키보드가 그 예시이다.
    
    표준 입력 장치 : 다양한 입력 장치 중 가장 기본으로 생각하는 장치
    ex> 카메라, 키보드, 마우스, 이어폰 , etc..

    표준 입력 버퍼 : 특정 키를 누를 때까지 사용자 입력을 임시로 저장하는 메모리
    ex> 컴퓨터로 예로 들면, Enter키를 누를때까지 저장하는 임시 버처 메모리

    1. rewind함수 [rewind(stdiin)] 입력 버러를 초기화하는 방법
    -> stdin 포인터와 rewind함수를 이용하면, 입력 버퍼에 남아 있는 입력 정보를 모두 지울 수 있음.

    2. getcher함수 [문자 한 개를 입력받는 함수]
    -> getcher함수를 사용할시 "개행문자"를 제거 하고 사용해야 연속적으로 사용 가능.

    3. getc함수 
    -> 표준 입력 장치를 의미하는 stdin을 인자로 넘겨주면 하나으 문자를 입력
    -> 파일 포인터를 인자로 넘겨줌녀 파일에서 1byte 정보를 입력
    -> 인자 없이 표준 입력 장치에서 입력을 받는 기능만 제공하느 것이 getchar 함수
    -> getc 함수를 이용하여 getchar 함수를 만듬

    4. gets 함수
    -> gets 는 get string 의 줄임 표현
    -> 문자열을 입력 받는 표준 입력 함수

    문자에서 숫자로 변환하는 방법
    -> 문자 - '0'
    -> atoi 함수 사용하기
    -> NULL 값과 입력값 그리고 조건문을 활용하여 알고리즘 구현하기
    

*/

#include <stdio.h>

void main(){
    int input_data;

    input_data  = getcher();
    getchat(); //Enter키 값을 제거
    printf"first input : %d\n", input_data);
    
    input_data  = getcher();
    getchat(); //Enter키 값을 제거
    printf("second input : %d\n", input_data);
   
    input_data  = getcher();
    rewind(Stdin); //Enter키 값을 제거
    printf("second input : %d\n", input_data);
    
    char finput_String[10];
    gets(finput_String);
    printf("first input : %d\n", finput_String[10]);

    char sinput_String[10];
    if (NULL != gets(input_String)){
        printf("sunput : %d", sinput_String[10];)
    }else{
        printf("input -> Conceled\n");
    }

}