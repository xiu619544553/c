//
//  main.c
//  二级指针作为形参
//
//  Created by hello on 2021/12/14.
//  https://www.cnblogs.com/lanhaicode/p/10342932.html

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void getMemory(char *p, int num);
void getMemory1(char **p, int num);

#pragma mark ----------- 一级指针
#pragma mark - 值传递

void swap1(int x, int y);
void demo1(void) {
    printf("\n================值传递================\n");
    
    int a = 10, b = 20;
    swap1(a, b);
    printf("值传递：a = %d，b = %d\n", a, b); // a = 10，b = 20。
}

// 形参是实参的拷贝，改变形参的值并不会影响外部实参的值。从被调用函数的角度来说，值传递是单向的（实参->形参）
void swap1(int x, int y) {
    int t = 0;
    t = x;
    x = y;
    y = t;
}


#pragma mark - 引用传递/地址传递

void swap2(int *x, int *y);
void demo2(void) {
    printf("\n================引用传递/地址传递================\n");
    
    int a = 10, b = 20;
    
    // 形参为指向实参地址的指针，当对形参的指向操作时，就相当于对实参本身进行的操作
    swap2(&a, &b); // 传入变量a、b的地址
    printf("引用传递：a = %d，b = %d\n", a, b); // 引用传递：a = 20，b = 10
}

void swap2(int *x, int *y) {
    // x是指针变量，它的地址指向a。
    // 操作指针变量所指向的内存保存的值 x、y所指向地址的值
    int t = 0;
    t = *x;
    *x = *y;
    *y = t;
}

#pragma mark - 易错点补充

void swap3(int *x, int *y);
void demo3(void) {
    printf("\n================易错点补充================\n");
    
    int a = 10, b = 20;
    
    // 指针变量
    int *pp = &a;
    int *kk = &b;
    
    /*
     a的地址  0x7ffeefbff46c ---- b的地址  0x7ffeefbff468
     pp的值   0x7ffeefbff46c ---- kk的值   0x7ffeefbff468
     pp的地址 0x7ffeefbff460 ---- kk的地址 0x7ffeefbff458
     */
    printf("a的地址 %p ---- b的地址 %p\n\n", &a, &b);
    printf("pp的值 %p ---- kk的值 %p\n", pp, kk);
    printf("pp的地址 %p ---- kk的地址 %p\n\n", &pp, &kk);
    
    // 实参pp、kk是值传递，传递的是指针的值。以指针pp来说，指针的值是变量a的地址。
    swap3(pp, kk);
    
    printf("a = %d，b = %d\n", *pp, *kk); // a=10，b=20。pp指向的仍是a，kk指向的仍是b
}

// pp、kk是值传递，传递的是指针的值。以指针pp来讲，指针的值是变量a的地址。
// 指针的值传入后用形参int *x和int *y接收，这里x和pp虽然都指向变量a的地址，但指针x和pp自身的地址并不相同（意思是x拷贝了一份pp的值），意味着你能改变变量a的值，但是不能改变pp的值（这里与值传递相似）
void swap3(int *x, int *y) {
    int *t;
    
    /*
     x的值   0x7ffeefbff46c ---- y的值  0x7ffeefbff468
     x的地址 0x7ffeefbff438 ---- y的地址 0x7ffeefbff430
     */
    printf("x的值 %p ---- y的值 %p\n", x, y);
    printf("x的地址 %p ---- y的地址 %p\n", &x, &y);
    
    t = x;
    x = y;
    y = t;
}

#pragma mark - 交换指针变量所指向的数据

void swap4(int *x, int *y);
void demo4(void) {
    printf("\n================交换指针变量所指向的数据================\n");
    int a = 10, b = 20;
    int *pp = &a;
    int *kk = &b;
    
    swap4(pp, kk);
    
    printf("引用传递：a = %d，b = %d\n", a, b); // 引用传递：a = 20，b = 10
}

void swap4(int *x, int *y) {
    // 交换 &a、&b 指针所指向内存的值
    int t = 0;
    t = *x;
    *x = *y;
    *y = t;
}


#pragma mark ----------- 二级指针

#pragma mark - 第一种，直接对变量值进行修改

void swap5(int **x, int **y);
void demo5(void) {
    printf("\n================二级指针：交换二级指针变量================\n");
    
    int a = 10, b = 20;
    int *pp = &a;
    int *kk = &b;
    
    swap5(&pp, &kk);
    
    printf("a = %d，b = %d\n", *pp, *kk); // a = 20，b = 10
}

void swap5(int **x, int **y) {
    // 直接对变量值进行修改
    int t = 0;
    t = **x;
    **x = **y;
    **y = t;
}

#pragma mark - 第二种：对指针的值进行修改

void swap6(int **x, int **y);
void demo6(void) {
    printf("\n================二级指针：对指针的值进行修改================\n");
    int a = 10, b = 20;
    int *pp = &a;
    int *kk = &b;
    
    swap6(&pp, &kk);
    
    printf("a = %d，b = %d\n", *pp, *kk); // a = 20，b = 10
}

void swap6(int **x, int **y) {
    int *t;
    t = *x;
    *x = *y;
    *y = t;
}

#pragma mark - main

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    
    // 值传递
    demo1();
    
    // 引用传递
    demo2();
    
    // 易错点
    demo3();
    
    // 交换指针指向的数据
    demo4();
    
    // 二级指针：交换二级指针变量
    demo5();
    
    // 二级指针：对指针的值进行修改
    demo6();
    
    return 0;
}

void getMemory(char *p, int num) {
    p = (char *)malloc(sizeof(char) * num);
}

void getMemory1(char **p, int num) {
    *p = (char *)malloc(sizeof(char) * num);
}
