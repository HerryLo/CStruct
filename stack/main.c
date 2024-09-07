//
//  main.c
//  stack
//
//  Created by HerryLo on 2020/3/8.
//  Copyright ? 2020年 HerryLo. All rights reserved.
//

// 栈之动态链表栈
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node *next;
}Node, *pNode;

typedef struct Stack{
    pNode pTop;
    pNode pBottom;
}Stack, *pStack;

// 初始化
void initStack(pStack s);
// 压栈
void pushStack(pStack s, int value);
// 遍历
void traverseStack(pStack s);
// 出栈
bool popStack(pStack s);

int main() {
    Stack s;
    
    initStack(&s);
    pushStack(&s, 1);
    pushStack(&s, 2);
    pushStack(&s, 3);
    pushStack(&s, 4);
    traverseStack(&s);
    popStack(&s);
    traverseStack(&s);
    
    return 0;
}

void initStack(pStack s){
    // 初始化栈
    s->pTop = (pNode)malloc(sizeof(Node));
    if(s->pTop == NULL) {
        printf("动态内存分配失败");
        exit(-1);
    }else{
        s->pBottom = s->pTop;
        s->pTop->next = NULL;
        printf("初始化栈成功 ");
        printf("pTop = %d ", s->pTop->data);
        printf("pBottom = %d \n", s->pBottom->data);
    }
}

void pushStack(pStack s, int value){
    pNode pNew = (pNode)malloc(sizeof(Node));
    if(pNew == NULL) {
        printf("动态内存分配失败");
        exit(-1);
    }
    pNew->data = value;
    pNew->next = s->pTop;
    s->pTop = pNew;

    printf("入栈成功 data = %d \n", value);
}

bool popStack(pStack s){
    pNode top = s->pTop;
    int data = top->data;
    if(top->next == NULL){
        return false;
    }
    s->pTop = top->next;
    printf("出栈成功 data = %d \n", data);
    free(top);
    return true;
}

void traverseStack(pStack s) {
    printf("\n遍历stack");
    pNode top = s->pTop;
    while(top->next != NULL) {
        printf(" %d ", top->data);
        top = top->next;
    }
    printf("\n");
}
