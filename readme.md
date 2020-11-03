 ## C语言数据结构

![](https://img.shields.io/badge/-C-brightgreen)
![](https://img.shields.io/badge/-XCode-brightgreen)

C语言学习数据结构的原因：C语言中存在指针、内存的概念，我们可以手动去操作它。

数据结构实际专门是来研究数据存储的问题，而数据的存储包含两个方面：**个体关系 + 个体关系的存储**。

环境工具：
- Mac
- XCode

以下的内容都是通过学习[郝斌老师数据结构自学视频](https://www.bilibili.com/video/av12907870)后整理。
 
## 指针Pointer

**指针就是地址，地址就是指针**。

这里的地址就是内存地址。在计算机开发中，我们会使用C/C++、Java、Go、python、NodeJs等高级语言进行软件开发，而在代码中声明的变量，通过编译器编译后，它们就会指向到内存地址中。我们对于变量的操作，实际就是对于计算机内存的操作。

内存地址：内存单元的编号，从0到非负整数；

**指针变量**：**存储内存单元编号的变量**；

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

// 需要用到指针变量
void Assignment(Student *c) {
    c->id = 2;
}

void main() {
    Student a = {1, 1000, "liuheng"};
    Student *b;
    b = &a; // &a为变量a的地址，它需要指针变量才可以接收
    Assignment(&b); // 传递的是地址
    printf("%d\n", a.id);
}
```
结构体变量指针b，存储结构体变量a的地址。

注意⚠️：如何判断何时使用指针变量？在函数参数中，一旦你需要传递地址，而对方需要接收时，那么此时必须使用指针变量，当然类型也必须要相同！！
 
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

数组是线性结构，在内存中连续存储数据元素的一种数据结构，它是连续存储的。例如🌰：创建一个数组arr，我们可以通过arr[0]、arr[1]、arr[3]来访问数组中的元素。

下面是数组的结构体数据类型：
```c
typedef struct ArrList {
    int *p;         // 数组中第一个元素的地址
    int len;        // 数组的长度
    int cnt;        // 当前有效的长度
}ArrList, *Array
```

示例如下：
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

链表是线性结构，在内存中非连续存储数据元素的一种数据结构，它是离散分布的。每个节点通过指针相连，每个一个前驱节点点和后续节点，头节点无前驱节点，尾节点无后续节点。

链表的种类：单链表、双链表、循环链表

双链表、循环链表是在单链表基础上扩展，下面是单链表结构：
```c
    头结点:A           首节点:B                                  尾节点:C
       👇               👇                                       👇
[data=NULL|next]——>[data|next]——>[data|next]——>[data|next]——>[data|next]——> NULL
```
> **头结点**: **第一个有效节点之前的节点，不存放有效数据，加头结点的目的主要是为了方便链表操作**；

> **首节点**：第一个有效节点；

> **尾节点**：最后一个有效节点；

> **头指针**：指向头结点的指针变量；

> **尾指针**：指向尾结点的指针变量；

**确定一个链表只需要一个参数：头指针**；链表中单个节点的数据类型：

```c
struct Node {
    value;   // 数据域
    next;   // 指针域
}
```

示例如下：
```c
void main() {
    Node * pHead = NULL; //头结点

    // ....赋值操作省略

    // 遍历链表中的值
    Node * p = pHead->next; // 首节点
    while(p != NULL) {
        // 打印节点的值
        printf("%d \n", p->data);
        p = p->next;
    }

}
```

## 栈Stack

**栈是线性结构的具体应用**，类似于箱子📦📦，是一种可以实现“**先进后出**”的存储结构；

栈分为静态栈和动态栈，静态栈通常由数组构成，动态栈通常由链表构成(都**只有一个出入口**)；

以动态栈为🌰🌰，**确认一个栈的节点，只需要两个参数，顶部节点和尾部节点**。

```c
struct Stack {
    Node Top;
    Node Bottom;
}
```
可以想象为了一个放书的箱子📦，想法放入的📖会被后放入的压在下面，而后放入的就会在上面，后放入的必须先拿出，先放入的才可以拿出。

应用：函数调用、中断、表达式求值、内存分配、缓存、迷宫等；

## 队列Queue

**队列是线性结构的具体应用**，类似于排队，是一种“**先进先出**”的存储结构。

队列分为链式队列和静态队列，前者使用链表实现，后者是数组实现(都是**一头出，一头入**)；

下面是以静态队列为例子讲解。对于静态队列，它由数组构成，存储空间是一定的，而为了**避免出现空间浪费的问题**，它就必须是一个循环队列(静态队列必须是循环队列)；**一个循环队列只需要两个参数：front(头)、rear(尾)**；

不同场合front和rear不同的含义：

> **队列初始化**：front 和 rear 值都是0；

> **队列非空**：front代表队列的第一个元素；rear代表得失队列最后一个有效元素的下一个元素；

> **队列为空**：front和rear值相等，但不一定是0；

**队列算法核心：**

入队算法：**rear = (rear+1)%数组长度；**

出队算法：**front = (front+1)%数组长度；**

可以想象一个水池，一头注水，一头出水，先放入水会先出，后放入的后出。

## 递归

递归就是一个函数直接或间接调用它自身。

递归需要满足三个条件：
* 1. **递归必须得有一个明确的中止条件；**
* 2. **该函数所处理的数据规模必须是递减的；**
* 3. **这个转化是可解的；**

循环和递归的比较：

递归：易于理解；速度慢；存储空间大；

循环：不易于理解；速度快；存储空间小；

参考：阶乘、汉诺塔、斐波拉切数列

## 树Tree 

树的专业定义：

    1. 有且只有一个根节点；
    2. 有若干个互不相交的子树，这些子树本身也是一棵树的通俗定义；

树的通俗定义：

    1. 树由节点和边组成；
    2. 每个节点只有一个父节点，但可以有多个子节点；
    3. 但有一个节点例外，该节点没有父节点，此节点称为根节点；

树的分类：

- 一般树：任意一个节点的子节点的个数不受限制；
- **二叉树：任意一个节点的子节点个数最多两个，且子节点的位置不可更改**；
- 森林：n个互不相交的树的集合；

### 二叉树

二叉树分类：

一般二叉树：任意一个节点的子节点个数最多两个

**满二叉树**：在不增加树的层数的前提下，无法再多添加一个节点的二叉树就是满二叉树；

**完全二叉树**：如果只是删除满二叉树最右边的连续若干节点，这样形成的二叉树就是完全二叉树；

![](./img/WechatIMG453.png)

**一般树转换为二叉树**：把一个普通的树转换为二叉树，它一定没有右子节点。转换方法——左指针域指向它的第一个孩子，右指针指向它的兄弟，只要能满足此条件，就可以把普通二叉树转换为二叉树。

![](./img/WechatIMG454.png)
