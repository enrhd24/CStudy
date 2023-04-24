#include <stdio.h>
int func();
static void stfunc();
/* Static global variable */

int main(){
    /* Static local variable */
    printf("%d ",func());
    printf("%d\n",func());
    return 0;
}

int func(){
    int cnt = 0; //variable initialization
    cnt++; //increamenting counter variable
    return cnt;
}

// static function
static void stfunc(){
    printf('Hello javaTpoint');
}