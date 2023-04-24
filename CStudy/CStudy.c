#include <stdio.h>
#include <stdbool.h>
typedef enum{false,true} b;

int main(){
    // Syntax
    bool x = false;
    if(x == true){printf("The value if x is true\n");}
    else{printf("The value of x is FALSE\n");}

    //Boolean Array
    bool b[2] = {true, false};
    for(int i = 0; i < 2; i++){
        printf("%d ",b[i]);
    }

    //typedef
    b one=false; // variable initialization 
    if(one==true) // conditional statements  
    {printf("The value of x is true");}  
    else{printf("The value of x is false");}  
    return 0;
}