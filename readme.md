 ## C语言数据结构

C语言学习数据结构的原因：C语言中存在指针、内存的概念，我们可以手动去操作它。
数据结构实际专门是来研究数据存储的问题，而数据的存储包含两个方面：个体关系的存储 + 个体关系的存储。

环境工具：
- Mac
- XCode

以下的内容都是通过学习[郝斌老师数据结构自学视频](https://www.bilibili.com/video/av12907870)后整理。
 
## 指针

指针就是地址，地址就是指针。

这里的地址就是内存地址。在计算机开发中，我们会使用C/C++、Java、Go、python、NodeJs等高级语言进行软件开发，而在代码中声明的变量，通过编译器编译后，它们就会指向到内存地址中。我们对于变量的操作，实际就是对于计算机内存的操作。

内存地址：内存单元的编号，从0到非负整数；

指针变量：存储内存单元编号的变量；

```C
void main() {
    int *p;                 // 声明指针变量p；
    int i = 10;             // 声明整型变量i赋值10；
    p = &i;                 // 将i的地址赋值给变量p
    printf("%d", *p);       // *p == i;
}
```
一个指针变量占几个字节，由变量类型和机型决定。
 
## 结构体

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

—— 数组 Arr

—— 链表 list