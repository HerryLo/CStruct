//
//  main.c
//  stack
//
//  Created by HerryLo on 2020/3/8.
//  Copyright © 2020年 HerryLo. All rights reserved.
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
}

bool popStack(pStack s){
    printf("出栈\n");
    pNode top = s->pTop;
    if(top->next == NULL){
        return false;
    }
    s->pTop = top->next;
    free(top);
    
    return true;
}

void traverseStack(pStack s) {
    printf("遍历stack\n");
    pNode top = s->pTop;
    while(top->next != NULL) {
        printf("%d\n", top->data);
        top = top->next;
    }
}
