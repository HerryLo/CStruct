//
//  main.c
//  tree
//
//  Created by HerryLo on 2020/7/2.
//  Copyright © 2020 HerryLo. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct BiTNode {
    char data;
    struct TNode * pLchild;
    struct TNode * pRchild;
}BiTNode, *BiTree;

void createTree(BiTree *T);

int main(int argc, const char * argv[]) {
    BiTree bt;
    createTree(&bt);
    
    // insert code here...
//    printf("%d \n", bt->data);
    return 0;
}

// 创建一个二叉树
void createTree(BiTree *T){
    char ch;
    scanf("%c", &ch);
    if(ch == '0') {
        *T = NULL;
    }else {
        *T = (BiTree)malloc(sizeof(BiTNode));
        (*T)->data = ch;
        createTree(&(*T)->pLchild);
        createTree(&(*T)->pRchild);
    };
};
