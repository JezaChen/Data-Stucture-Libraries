# Data Stucture Libraries

## 概述
该项目是数据结构的作业之一，为了能巩固下C++的知识，故准备写成Library的形式，并不断优化其性能.

该项目全部由JetBrains的Clion完成.

本项目大多数的算法思路都来自于Clifford A.Shaffer的《数据结构与算法分析（C++版）（第三版）》 （英文原名：*Data Structure and Algorithm in C++ Third Edition*）

部分算法思路可能参考清华大学出版社出版的邓俊辉版《数据结构（C++）》进行相应的优化.

## 当前的目录
1. 线性表、栈和队列 (List, Stack and Queue)
- 线性表(List)，有两种：顺序表(Array Based List)和链表(linked List). *链表用可利用空间表进行优化*

*链表中有单向链表和双向链表*
- 栈(Stack)，有两种：顺序栈(Array Based Stack)和链式栈(Linked Stack).
- 队列(Queue)，也同样分两种：顺序队列(Array Based Queue)和链式队列(Linked Queue).

*当前的版本仍在编写，编译当前通过，列表调试基本通过*

2. 二叉树 (Binary Tree)

3. 二叉搜索树 (Binary Search Tree)

4. 优先级队列 (Priority Queue)

5. Huffman 编码树 (Huffman Tree)

6. 普通的树 (General Tree)

树的表示方法有以下几种：

- 父指针表示法 (Parent Pointer Representation)

- 子结点表表示法 (List of Children Representation)

- 左孩子右兄弟表示法

- 动态结点表示法 

### 重要更新记录
- 完成了树的几种表示方法，并完成了它的顺序表示法，可以完成重建和表示. (2017/11/04)
- 完成了Huffman 编码树的大体框架. (2017/10)
- 增加了优先级队列项目，基本完成大体框架. (2017/10/10)
- 增加了二叉树项目，基本完成大体框架. (2017/9/21)
- 由于类模板的实现和定义只能在头文件里进行，因此把cpp文件所有的内容全部迁移到头文件里. (2017/9/18)
- 遍历机制完善，分别利用函数对象机制和函数指针机制，参考了邓俊辉老师的思路. (2017/9/15)
- 完善了命名空间，避免单向链表和双向链表的命名冲突. (2017/9/15)
- 增加了异常处理机制和访问器机制. (2017/9/14)

### TODO 列表

- 要优化性能
- 要深入贯彻落实 C++11/14
- 准备写平衡二叉树，不知道后面的课程有没有讲.
