 ## C语言数据结构

C语言学习数据结构的原因：C语言中存在指针、内存的概念，我们可以手动去操作它。
数据结构实际专门是来研究数据存储的问题，而数据的存储包含两个方面：个体关系的存储 + 个体关系的存储。

环境工具：
- Mac
- XCode

以下的内容都是通过学习[郝斌老师数据结构自学视频](https://www.bilibili.com/video/av12907870)后整理。
 
## 指针Pointer

**指针就是地址，地址就是指针**。

这里的地址就是内存地址。在计算机开发中，我们会使用C/C++、Java、Go、python、NodeJs等高级语言进行软件开发，而在代码中声明的变量，通过编译器编译后，它们就会指向到内存地址中。我们对于变量的操作，实际就是对于计算机内存的操作。

内存地址：内存单元的编号，从0到非负整数；

指针变量：**存储内存单元编号的变量**；

```C
void main() {
    int *p;                 // 声明指针变量p；
    int i = 10;             // 声明整型变量i赋值10；
    p = &i;                 // 将i的地址赋值给变量p
    printf("%d", *p);       // *p == i;
}
```
一个指针变量占几个字节，由变量类型和机型决定。
 
## 结构体Struct

结构体用来定义一种数据类型。**struct**定义：用户需要定义的复合数据类型。

注意：普通的数据结构无法加减运算，但是可以相互赋值。

```c
typedef struct Student {
    int id;
    int grade;
    char name[20];
}Student;

void Assignment(Student *c) {
    c->id = 2;
}

void main() {
    Student a = {1, 1000, "liuheng"};
    Student *b;
    b = &a;
    Assignment(&b);
    printf("%d\n", a.id);
}
```
结构体变量指针b，存储结构体变量a的地址。
 
## 动态内存

```c
void mallocFn() {
    // malloc申请动态内存空间
    // sizeof设置内存大小，(int *)表示数据类型
    int * arr = (int *)malloc(sizeof(5)); // 返回的是第一个字节的地址
    
    arr[0]= 12;
    arr[1]= 234;
    printf("%d\n", arr[0]);
    
    // free释放内存空间
    free(arr); // 只是将申请的内存地址标记为释放
    arr = NULL;
    printf("%d\n", p[1]);
}
```
变脸指针b是指向内存第一个元素的内存地址。

## 数组Array

数组是线性结构，在内存中连续存储数据元素的一种数据结构，它是连续存储的。例如：创建一个数组arr，我们可以通过arr[0]、arr[1]、arr[3]来访问数组中的元素。

下面是数组的结构体数据类型：
```c
typedef struct ArrList {
    int *p;         // 数组中第一个元素的地址
    int len;        // 数组的长度
    int cnt;        // 当前有效的长度
}ArrList, *Array
```

使用如下：
```c
void main() {
    ArrList arr;

    // ....赋值操作省略

    printf("数组长度为：%d\n", arr.len);
    printf("数组当前有效长度为：%d\n", arr.cnt);
    // arr.p[0] == *(arr.p)
    printf("数组当前第一个元素的值：%d\n", arr.p[0]);
}
```
**这里的arr.p只是指向数组中第一个元素的内存地址**

## 链表List

链表是线性结构，在内存中非连续存储数据元素的一种数据结构，它的结点是离散分部的。每个结点通过指针相连，每个结点有一个前驱结点和后续结点，头结点无前驱结点，尾结点无后续结点。

## 队列