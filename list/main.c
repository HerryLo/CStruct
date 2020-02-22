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

// 结构体
typedef struct Node {
    int data; // 数据域
    struct Node * next; //指针域
}Node, *PNode;

//  创建非循环单链表
PNode createList(void) {
    // 长度
    int len;
    // 存放用户输入的节点值
    int val;
    
    // 不存放有效数据的头结点
    PNode pHead = (PNode)malloc(sizeof(Node));
    if(NULL == pHead) {
        printf("分配失败，程序终止！\n");
        exit(-1);
    }
    
    PNode pTail = pHead;
    pTail->next = NULL;
    
    printf("请输入链表的长度: len=");
    scanf("%d", &len);
    
    for (int i = 0; i<len; ++i) {
        printf("请输入第%d个节点的值: ", i+1);
        scanf("%d", &val);
        
        PNode pNew = (PNode)malloc(sizeof(Node));
        if(NULL == pNew) {
            printf("分配失败，程序终止！\n");
            exit(-1);
        }
        
        pNew->data = val;
        pTail->next = pNew;
        pNew->next = NULL;
        pTail = pNew;
    }
    return pHead;
}

// 遍历  
int traverseList(PNode pHead) {
    printf("打印链表的z值：\n");
    PNode next = pHead->next;
    while(next != NULL) {
        printf("%d \n", next->data);
        next = next->next;
    }
    printf("\n");
    return 0;
}

// 是否为空
bool isEmpty(PNode pHead) {
    PNode next = pHead->next;
    if(next != NULL) {
        return false;
    }
    return true;
}

// 长度
int lengthList(PNode pHead) {
    PNode next = pHead->next;
    int i = 0;
    while(next != NULL) {
        next = next->next;
        i++;
    }
    printf("链表的长度为: %d \n", i);
    return i;
}

// 移除
// pHead 链表头节点
// i 移除的下标，由1开始
bool removeList(PNode pHead, int position, int *pVal) {
    PNode p = pHead;
    int i = 0;
    
    // p->next != NULL，移除的前提下，保证要移除的那个只存在；
    // 在存在的前提下，p会指向要移除的前一个节点；
    while (p->next != NULL && i< position - 1) {
        p = p->next;
        ++i;
    }
    
    // i > position - 1，防止负数
    if(i > position - 1 || p->next == NULL) {
        return false;
    }
    
    PNode q = p->next;
    *pVal = p->data;
    
    p->next = p->next->next;
    free(q);
    q = NULL;
    return true;
}

// 插入
// pHead 链表头节点
// i 插入的下标，由1开始
bool insertList(PNode pHead, int position, int val){
    PNode p = pHead;
    int i = 0;
    
    // p != NULL，插入的前提下，保证要插入位置的前y一个元素存在；
    // 在存在的前提下，p会指向要插入的前的节点；
    while (p->next != NULL && i< position - 1) {
        p = p->next;
        ++i;
    }
    // // i > position - 1，防止负数
    if(i > position - 1 || p == NULL) {
        return false;
    }
    
    PNode pNew = (PNode)malloc(sizeof(Node));
    if(NULL == pNew) {
        printf("分配失败，程序终止！\n");
        exit(-1);
    }
    pNew->data = val;
    pNew->next = p->next;
    p->next = pNew;
    return true;
}


int main() {
    // 头节点
    PNode pHead = NULL; // 等价于struct Node * pHead = NULL
    int value;
    
    pHead = createList();
    removeList(pHead, 8, &value);
    insertList(pHead, 2, 123123);
    traverseList(pHead);
    return 0;
}
