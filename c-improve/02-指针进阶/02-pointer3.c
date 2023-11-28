//
// Created by Cola on 2023/11/28.
//
#include <stdio.h>

void changeValue(int *p)
{
    *p = 1000;
}

void test01()
{
    //1 、一个普通变量 和一个指针变量  构成指针的间接赋值
    int a = 10;
    int * p = &a;
    *p = 100;
    printf("a = %d\n", a);

    //2、通过实参和形参 进行间接赋值
    int a2 = 0;
    changeValue(&a2);
    printf("a2 = %d\n", a2);
}

int main()
{
    test01();
}
