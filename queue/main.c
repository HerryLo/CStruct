//
//  main.c
//  queue
//
//  Created by HerryLo on 2020/2/23.
//  Copyright © 2020年 HerryLo. All rights reserved.
//

// 队列之静态循环队列
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int len = 6;

typedef struct Queue{
    int * PArrry;
    int pFront;
    int pRear;
}Queue;

void initQueue(Queue * q) {
    q->PArrry = (int *)malloc(sizeof(int)* 6);
    q->pFront = 0;
    q->pRear = 0;
}

// 是否满队
bool isFullQueue(Queue * q) {
    if((q->pRear + 1)%len == q->pFront)
        return true;
    return false;
}

// 入队
bool inputQueue(Queue * q, int value) {
    if(isFullQueue(q))
        return false;
    else
        q->PArrry[q->pRear] = value;
        q->pRear = (q->pRear + 1)%len;
    return true;
}

// 遍历
void traverseQueue(Queue * q) {
    printf("遍历队列中的值\n");
    int front =q->pFront;
    while (front != q->pRear) {
        printf("%d\n", q->PArrry[front]);
        front = (front+1)%len;
    }
}

int main(int argc, const char * argv[]) {
    printf("---------循环队列构建---------\n");
    Queue q;
    
    initQueue(&q);
    
    inputQueue(&q, 12);
    inputQueue(&q, 12);
    inputQueue(&q, 12);
    inputQueue(&q, 12);
    inputQueue(&q, 12);
    inputQueue(&q, 12);
    inputQueue(&q, 12);
    inputQueue(&q, 12);
    traverseQueue(&q);
    return 0;
}
