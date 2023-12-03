//
// Created by Cola on 2023/11/28.
//
#include <stdio.h>
#include <stdlib.h>

//二级指针做函数参数的输入特性：
//主调函数分配内存，被调函数使用
void printArray(int ** p,int num)
{
    for(int i = 0;i<num;i++)
    {
        printf("第%d个元素的值为%d,地址为%p\n", i, *p[i], p[i]);
    }
}
void test01()
{
    int ** pArray = malloc(sizeof(int *)*5);

    int a1 = 100;
    int a2 = 200;
    int a3 = 300;
    int a4 = 400;
    int a5 = 500;

    pArray[0] = &a1;
    pArray[1] = &a2;
    pArray[2] = &a3;
    pArray[3] = &a4;
    pArray[4] = &a5;

    int len = 5;
    printArray(pArray,len);
}

void test02()
{

}

int main()
{
    test01();
}