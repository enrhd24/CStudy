#include <stdio.h>
#include <conio.h>

int main(void){
    printf("press any key to start the game \n");
    while(kbhit() == 0){}
    printf("We'll start the game soon^^");
}