#include <stdio.h>
#include <Stdbool.h>

int main(){
    int a = 30;
    float b = 3.14;
    char c = 'A';
    char d[5] = {'K','O','R','E','A',};
    char e[6] = {'H','E','L','L','O','\0'};
    printf("%d\n%f\n%c\n%s\n%s\n", a,b,c,d,e);

    bool ba = false;
    bool bb = 25;
    printf("%d %d \n", ba, 0);
    printf("%d %d \n",bb, true);

    int __,ca = 3;
    char cb = 'A';
    __ = ca + 6;
    printf("%d %c %d\n", __,cb,cb);

    //printf("\n");
    printf("Hello, World~1\n");
    printf("Hello, World~%d\n",2);

    // 연산자(참조, 형 변환, 우섢순위)
    int da = 3;
    printf("[address]->%d\n[data]->%d\n[data]->%d\n", &da, da, *&da);

    // array
    int score[6];
    int integer, variable, sum = 0;

    for(int i = 0; i < 6; i++){
        printf("학생 %d 성적을 입력하세요 : ", i+1);
        scanf("%d", &score[i]);
    }
    for(int i = 0; i < 6; i++){
        printf("합계: %d\n", sum);
        printf("평균 %.2f\n", (double)sum/6);
        printf("\n score[6]에 저장되어있는 숫자:\n");
    }
    for(int v = 0; v < 6; v++){
        printf(" %d",score[v]);
    }

    return 0;
}