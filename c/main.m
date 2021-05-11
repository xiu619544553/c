//
//  main.m
//  c
//
//  Created by hello on 2021/5/11.
//

#import <Foundation/Foundation.h>

#pragma mark - 指针定义和简单实用
void pointerDefine() {
    int a = 15;
    // 定义指针变量   int *p = &a;
    int *p;
    
    // 给指针变量本身赋值时不能加 *
    p = &a;
    NSLog(@"p = %p", p); // 输出指针变量的地址
    
    // 修改指针变量指向的数据
    *p = 100;
    NSLog(@"a = %d", a); // 输出结果：100
    
    // *&a = *(&a);  &a表示取变量a的地址，&a等价于指针p，*p表示取指针指向的地址的变量
    NSLog(@"*&a = %d", *&a);
}

#pragma mark - 指针变量的运算
void pointerVarCalculate() {
    
    // 指针变量保存的是地址，而地址本质上是一个整数，所以指针变量可以进行部分运算，例如加法、减法、比较等，请看下面的代码：

    int    a = 10, *p = &a, *pa = &a;
    double b = 99.9, *pb = &b;
    char   c = '@', *pc = &c;
    
//    printf("&a = %#X, &b = %#X, &c = %#X\n", &a, &b, &c);
//    printf("pa = %#X, pb = %#X, pc = %#X\n", pa, pb, pc);
    
    
    printf("&a = %p, &b = %p, &c = %p\n", &a, &b, &c);
    printf("pa = %p, pb = %p, pc = %p\n", pa, pb, pc);
    
    // 加法
    pa++; pb++; pc++;
    printf("pa = %p, pb = %p, pc = %p\n", pa, pb, pc);
    
    // A B C D E F
    // 减法
    pa--; pb--; pc--;
    printf("pa = %p, pb = %p, pc = %p\n", pa, pb, pc);
    
    /*
     pa 指针地址变化
        原地址：0x7ffeefbff56c
        ++1后：0x7ffeefbff570 = 原地址 + 4
        --1后：0x7ffeefbff56c
     */
}




int main(int argc, const char * argv[]) {
    
    // 指针定义
    pointerDefine();
    
    // 指针变量的运算
    pointerVarCalculate();
    
    return 0;
}