/*
    배열(array) 

    연속된 메모리 공간에 순차적으로 저장된 데이터 모음.
    대부분의 프로그램 언어에서 동일 타입의 데이터를 저장합니다.
    
    배열을 구성하는 각각의 값을 요소라고 하며 
    배열에서 위치를 가리키는 숫자는 인덱스라고 한다.

*/

/* 스택(Stack)
    1. 배열 기반으로 구현
    2. 동적 배열을 기반으로 구현
    3. 연결리스트로 구현
*/

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

Stack* createStack(int capacity);
int isEmpty(Stack* stack);
int isFull(Stack* stack);
int peek(Stack* stack);
void push(Stack *stack, int data);
int pop(Stack* stack);

typedef struct ArrayStack{
    int top;
    int capacity; //크기지정
    int* array;
}Stack;

int main(){return 0;}

Stack* createStack(int capacity){
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    if(!stack)return NULL;
    stack -> capacity = capacity;
    stack -> top = -1;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

int isEmpty(Stack* stack){return (stack->top == -1);}
int isFull(Stack* stack){return(stack->top == stack->capacity -1);}
