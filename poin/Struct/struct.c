//
//  struct.c
//  CC
//
//  Created by HerryLo on 2019/10/10.
//  Copyright © 2019年 HerryLo. All rights reserved.
//

#include "struct.h"

// 结构体
struct Student {
    int id;
    char name[20];
    int grade;
};

void inputfn(struct Student *c) {
    c->id = 2;
    
    (*c).id = 3;
    
    printf("%p\n", c);
}

void structFn() {
    struct Student a = {1, "liuheng", 99};
    
    printf("%p\n", &a);
    
    struct Student *b;
    
    b = &a;
    
    inputfn(b);
    
    printf("结构体： %d\n", a.id);
}
