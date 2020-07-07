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

typedef char ElemType;

typedef struct BiTNode {
    ElemType data;
    struct BiTNode * pLchild;
    struct BiTNode * pRchild;
}BiTNode, *BiTree;

void createTree(BiTree *T);
void preOrderTree(BiTree T);

int main(int argc, const char * argv[]) {
    BiTree bt; //等同于 struct BiTNode * bt
    // &bt是一个地址
    createTree(&bt);
    
    preOrderTree(bt);
    return 0;
}

// 创建一个二叉树
// 参数 struct BiTNode * * T
// 参数拆为两部分看，首先 struct BiTNode * 表示的是参数的类型
// *T表示的是一个存储内存地址的指针变量
// 形参 T存储内存地址，*T才是实际传入的值
void createTree(BiTree *T){
    ElemType ch;
    printf("输入值：");
    scanf("\n %c", &ch);
    if(ch == '#') {
        *T = NULL;
    }else {
        *T = (BiTree)malloc(sizeof(BiTNode));
        if(!*T) {
            printf("创建失败！！\n");
            exit(-1);
        }
        (*T)->data = ch;
        createTree(&(*T)->pLchild);
        createTree(&(*T)->pRchild);
    };
};

// 递归——->先序遍历
// 先访问根节点，再访问左子节点，最后访问右子节点
void preOrderTree(BiTree T){
    if(T == NULL) {
        return;
    }
    printf("%c \n", T->data);
    preOrderTree(T->pLchild);
    preOrderTree(T->pRchild);
};
