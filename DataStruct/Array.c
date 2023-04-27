/*
    배열(array)

    연속된 메모리 공간에 순차적으로 저장된 데이터 모음.
    대부분의 프로그램 언어에서 동일 타입의 데이터를 저장합니다.
    
    배열을 구성하는 각각의 값을 요소라고 하며 
    배열에서 위치를 가리키는 숫자는 인덱스라고 한다.

    https://blog.naver.com/PostView.naver?blogId=tipsware&logNo=221694885902&categoryNo=94&parentCategoryNo=0&viewDate=&currentPage=1&postListTopCurrentPage=1&from=postView

*/

#include <stdio.h>

#define STUDENT_COUNT 4 //입력 받을 학생 수
#define CLASS_COUNT 3 // 입력 받을 과목 수
#define MAX_CLASS_NAME_LEN 10 // 과목이른 최대길이

int main(){

    int score[STUDENT_COUNT][CLASS_COUNT]; // 각각 학생의 과목
    char class_name[CLASS_COUNT][MAX_CLASS_NAME_LEN] = {"Language","English","Math"};
    // char class_name[CLASS_COUNT] = {"Language","English","Math"};
    int total, s_num, c_num, min, max;

    //학생들의 성적을 입력받는다.
    for(s_num = 0; s_num < STUDENT_COUNT; s_num++){
        printf("%d student input -> ", s_num+1);
        for(c_num = 0; c_num < CLASS_COUNT; c_num++){
            printf("%s score : ", class_name[c_num]);
            scanf("%d", &score[s_num][c_num]);
        }
    }
    printf("\ninput score student Score and Average\n");


    return 0;
}

