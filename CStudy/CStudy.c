#include <stdio.h>
void function1();
#define X 10; //global variable[전역 변수]
extern int ex_x = 10  //external variable[외부 변수, 전역 변수]

int main(){
    static int static = 10; 
    //static variable[정적 변수]

    return 0;
}

void function1(){
    int x = 10; //local variable[지역변수]
    auto int y = 20 // automaticc variable[자동변수]
}
