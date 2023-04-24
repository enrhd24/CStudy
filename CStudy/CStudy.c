#include <stdio.h>
void function1();
#define X 10; //global variable

int main(){
    static int static = 10; //static variable

    return 0;
}

void function1(){
    int x = 10; //local variable
}