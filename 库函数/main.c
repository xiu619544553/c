//
//  main.c
//  库函数
//
//  Created by hello on 2021/12/13.
//

#include <stdio.h>
#include <stdlib.h>

int cmp (const void *a, const void *b) {
    // a/b 是指向 int 类型的指针，首先强转类型 (int *)a，然后取值 *(int *)a
    return (*(int *)a) - (*(int *)b);
}

int main(int argc, const char * argv[]) {
    
    int n = 0;
    int values[] = { 88, 56, 100, 2, 25 };
    
    printf("排序之前的列表：");
    for( n = 0 ; n < 5; n++ ) {
        printf("%d ", values[n]);
    }
    
    qsort(values, sizeof(values) / sizeof(values[0]), sizeof(int), cmp);
    
    printf("\n排序之后的列表：");
    for( n = 0 ; n < 5; n++ ) {
        printf("%d ", values[n]);
    }
    
    printf("\n结束\n");
    
    return 0;
}
