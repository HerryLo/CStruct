//
//  main.c
//  list
//
//  Created by HerryLo on 2019/10/20.
//  Copyright © 2019年 HerryLo. All rights reserved.
//

// 线性结构：连续存储 数组
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool a = 1;

typedef struct ArrList {
    int *p;     //  数组第一个元素的地址
    int len;    //  数组长度
    int cnt;    //  数组元素的有效长度
}ArrList; //别名 ArrList

// 初始化创建数组
void arrInit(ArrList *arr, int length);
// 添加(尾部)
void append(ArrList *arr, int value);
// 展示元素
void show(ArrList *arr);
// 插入
void insert(ArrList *arr, int value, int index);
// 删除
void delet(ArrList);
// 排序
void sort(ArrList);

// 判断是否空
bool isEmpty(ArrList *arr);
// 判断是否满
bool isFull(ArrList *arr);

int main() {
    ArrList arr;
    
    arrInit(&arr, 5);
    append(&arr, 1);
    append(&arr, 2);
    append(&arr, 3);
    insert(&arr, 99, 1);
    show(&arr);
    
    printf("数组长度为：%d\n", arr.len);
    
    return 0;
}

// 初始化数组
void arrInit(ArrList *arr, int length) {
    arr->p = (int *)malloc(sizeof(int) * length);
    
    if(arr == NULL)
        printf("Array create fail");
    else
        arr->len = length;
    arr->cnt = 0;
}

// 是否空
bool isEmpty(ArrList *arr) {
    if(arr->cnt == 0) {
        return true;
    }else {
        return false;
    }
}

// 是否满
bool isFull(ArrList *arr) {
    if(arr->cnt == arr->len) {
        return true;
    }else {
        return false;
    }
}


// append
void append(ArrList *arr, int value){
    if(isFull(arr)) {
        printf("数组已满, 已无法 append \n");
        return;
    }
    
    arr->p[arr->cnt] = value;
    ++(arr->cnt);
    return;
}

// show
void show(ArrList *arr) {
    int len = arr->cnt;
    
    if(isEmpty(arr)) {
        printf("数组为空\n");
        return;
    }
    
    for (int i = 0; i< len; ++i) {
        printf("%d ", arr->p[i]);
    }
    printf("\n");
}

//插入
// arr 数组
// value 数值
// index 个数
void insert(ArrList *arr, int value, int index) {
    if(isFull(arr)) {
        printf("数组已满, 已无法 insert \n");
        return;
    }
    
    int len = arr->cnt;
    
    if(index < 1 || index > arr->cnt+1){
        return;
    }
    
    for (int i = len-1; i>=index-1; --i) {
        arr->p[i+1] = arr->p[i];
    }
    arr->p[index-1] = value;
    ++(arr->cnt);
    return;
}


