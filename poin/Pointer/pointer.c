//
//  pointer.c
//  CC
//
//  Created by HerryLo on 2019/10/10.
//  Copyright © 2019年 HerryLo. All rights reserved.
//

#include "pointer.h"
#include <stdio.h>
#include <limits.h>

// 指针变量 & 示例
// 内存地址是内存单元的编号
// 指针就是内存地址
// 变量指针是存储在内存单元编号的变量
void fn(int * a) {
    a[2] = 12313;
    printf("数组a中第一个值的l内存地址： %p\n", a);
    printf("指针a即数组第一个值的内存地址： %d\n", *a);
}

void pointerFn() {
    int arr[5] = {1,2,3,4,5};
    
    fn(arr);
    printf("数组arr中第一个值的内存地址： %p\n", arr);
    printf("数组arr[2]的值：%d\n", arr[2]);
}
