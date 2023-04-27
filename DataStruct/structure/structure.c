#include <stdio.h>
#include <stdlib.h>

struct contant{
    char name[20];  //이름
    char phone[20]; //전화번호
    int ringtone;   //벨 소리
    // 각각 구조체의 멤버
}Contant; //구조체 변수를 함계선 선언한다.

void test(){
    struct contant c1;
    struct Contant;

    // 구조체 포인터
    struct contant ct = {
        "김석진","01011112222",0
    };
    //struct contact *p = &ct;
}

struct complex{ double re; double im; };
typedef struct complex Complex;
// typedef 기존의 데이터형에 대한 별명(alias)
// 1. 이식성 , 2. 가독성 

// 멤버 접근 연산자 - 예제
void add(Complex *sum, Complex *b,Complex *c){
    sum -> re = b -> re + c -> re;
    sum -> im = b -> im + c -> im;
}

typedef struct date{
    unsigned short year : 7;   // 7비트에 연를 저장.
    unsigned short month : 4;  // 4비트에 월을 저장.
    unsigned short day : 5;    // 5비트에 일을 저장.
    char the_day_of_week[4];   // 일반 멤버를 함께 정의 가능.
}DATE;


int main(){
    // 일반 구조체 멤버 접근 연산자 [Content.ringtone]
    // 포인터를 통한 구조체 멤버 접근 연산자 [Content->ringtone]
    // 다른 방법 [(*Contant).ringtone]
    
    struct contant c1;
    printf("structure size = %d\n", sizeof(c1));
    printf("structure size = %d\n", sizeof(Contant));
    // 구조체의 크기는 멤버들의 크기의 합보다 크거나 같다.
    // 태그명만 사용하면 안된다.


    // 구조체 포인터 변수 초기화 하는 방법
    struct contant ct = {"Name","01011112222",0};
    printf("name %s\n",ct.name);
    printf("phone %s\n", ct.phone);
    printf("ringtone %d\n", ct.ringtone);
    return 0;
}

/*
    POINT *p = &pt1; --> &pt1;

    int main(void){
        POINT pt1 = { 10, 20 };
        print_point(&pt1);
    }

    void print_point(POINT *pt){
        printf("(%d, %d)", pt->x, pt->y);
    }
*/

// 열거체
// 공용체