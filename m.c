//
//  m.c
//  CC
//
//  Created by HerryLo on 2019/10/10.
//  Copyright © 2019年 HerryLo. All rights reserved.
//

#include "m.h"

// 结构体
struct Student {
    int id;
    char name[20];
    int grade;
};

int main()
{
    struct Student a = {1, "liuheng", 99};
    
    printf("%d\n", a.id);
    return 0;
}
