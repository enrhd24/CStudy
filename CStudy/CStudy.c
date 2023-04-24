#include <stdio.h>
#include <stdbool.h>

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
    printf("\n");
    
    // Logical Operators
    bool f = 0;
    bool t = 1;
    printf("The value if x&&y is %d\n",f&&t);
    printf("The value if x||y is %d\n",f||t);
    printf("The value if !x is %d\n",!f);
    return 0;
}