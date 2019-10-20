//
//  ArrList.c
//  CC
//
//  Created by HerryLo on 2019/10/20.
//  Copyright © 2019年 HerryLo. All rights reserved.
//


#include "ArrList.h"
#include <stdlib.h>

typedef struct ArrList {
    int *p;     //  数组第一个元素的地址
    int len;    //  数组长度
    int cnt;    //  数组元素的有效长度
}ArrList; //别名 ArrList

// 初始化创建数组
void arrInit(ArrList *arr, int length);
// 添加(尾部)
void append(ArrList);
// 插入
void insert(ArrList);
// 删除
void delet(ArrList);
// 排序
void sort(ArrList);

// 判断是否空
void isEmpty(ArrList);
// 判断是否满
void isFullF(ArrList);

// 创建数组
void arrInit(ArrList *arr, int length) {
    arr->p = (int *)malloc(sizeof(int) * length);
    
    if(arr == NULL)
        printf("Array create fail");
    else
        arr->len = length;
        arr->cnt = 0;
}
