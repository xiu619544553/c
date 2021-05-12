//
//  main.m
//  struct
//
//  Created by hello on 2021/5/12.
//  结构体


#include <stdio.h>

//struct PersonInfo {
//    char gender;
//    int age;
//    double weight;
//};

typedef struct Person {
    char gender;
    int age;
    double weight;
}PersonInfo;

// 结构体变量名作为函数名，值传递
void modifyPersonAge(PersonInfo p) {
    p.age = 6;
    printf("修：%c %d %f\n", p.gender, p.age, p.weight);
}

// 结构体指针作为函数参数
void modifyPersonName(PersonInfo *p) {
    p->weight = 30.0;
    printf("修：%c %d %f\n", p->gender, p->age, p->weight);
}

int main(int argc, const char * argv[]) {

    
    // 结构体变量名作为函数参数------------start
    printf("结构体\n");
    PersonInfo tank;
    tank.gender = 'm';
    tank.age = 5;
    tank.weight = 20.0;
    
    printf("前：%c %d %f\n", tank.gender, tank.age, tank.weight);
    modifyPersonAge(tank);
    printf("后：%c %d %f\n", tank.gender, tank.age, tank.weight);
    // 结构体变量名作为函数参数------------end
    
    
    
    /*
     结构体指针作为函数参数
     结构体变量名代表的是整个集合本身，作为函数参数时传递的整个集合，也就是所有成员，而不是像数组一样被编译器转换成一个指针。如果结构体成员较多，尤其是成员为数组时，传送的时间和空间开销会很大，影响程序的运行效率。所以最好的办法就是使用结构体指针，这时由实参传向形参的只是一个地址，非常快速。
     */
    // 结构体指针作为函数参数------------start
    printf("前2：%c %d %f\n", tank.gender, tank.age, tank.weight);
    modifyPersonName(&tank);
    printf("后2：%c %d %f\n", tank.gender, tank.age, tank.weight);
    // 结构体指针作为函数参数------------end
    
    return 0;
}
