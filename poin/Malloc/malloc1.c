//
//  malloc1.c
//  CC
//
//  Created by HerryLo on 2019/10/13.
//  Copyright © 2019年 HerryLo. All rights reserved.
//

#include "malloc1.h"
#include <stdlib.h>

void *malloc(size_t size);
void free(void *ptr);

void mallocFn() {
//    malloc申请动态内存空间
    int * p = (int *)malloc(sizeof(4)); // 返回的是第一个字节的地址
    
    p[0]= 12;
    p[1]= 234;
    
    printf("%d\n", p[0]);
    
//    free释放内存空间
    free(p); // 只是将申请的内存地址标记为释放
//    p = NULL;
    
    printf("%d\n", p[1]);
}
