//
// Created by Cola on 2023/11/27.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//野指针指向一个已释放的内存或者未申请过的内存空间,程序报错
void test01()
{
    char * p = NULL;
    //给p指向的内存区域拷贝内容
    strcpy(p, "1111"); //err

    char * q = 0x1122;
    //给q指向的内存区域拷贝内容
    strcpy(q, "2222"); //err
}

int* func()
{
    int a = 10;
    int * p = &a;
    return p;
}
//常见的几种野指针
void test02()
{
    //1 指针变量未初始化
    int * p1;
    //printf("%d\n", *p1);

    //2 指针释放后未置空
    int * p2 = (int*)malloc(sizeof(int));
    *p2 = 100;
    free(p2);
    printf("%d\n", *p2); //乱码 已经释放了

    //3 指针操作超越变量作用域，其实就是栈返回局部变量的地址
    int * p3 = func();
    printf("%d\n", *p3);
}
int main()
{
    //test01();
    test02();
}
