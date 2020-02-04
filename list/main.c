//
//  main.c
//  list
//
//  Created by HerryLo on 2019/10/20.
//  Copyright © 2019年 HerryLo. All rights reserved.
//

// 线性结构：离散存储 链表
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data; // 数据域
    struct Node * next; //指针域
}Node, *PNode;

PNode createList() {
    
};

int main() {
    // 头节点
    PNode pHead = NULL; // 等价于struct Node * element = NULL

    return 0;
}
