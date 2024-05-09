//
// Created by Cola on 2024/5/9.
//
#include "stdio.h"

int test01()
{
    int arr[] = {1,2,3,4,5};

    //1.先定义数组的类型，再通过数组类型定义数组指针变量。
    typedef int(ARRAY_TYPE)[5]; //ARRAY_TYPE就是一个数据类型，是一个存放了5个int元素的数组类型。
    ARRAY_TYPE * arrp = &arr;   //ARRAY_TYPE *就可以定义一个数组指针，这句话是指针的初始化

    for(int i = 0; i < 5; i++)
    {
        printf("%d ",(*arrp)[i]); //*arrp等价于arr
    }
    printf("\n");
}


void test02()
{
    int arr[] = {1,2,3,4,5};

    //2.先定义数组指针类型，再通过数组指针类型定义数组指针变量。
    typedef int(*ARRAY_TYPE)[5];//ARRAY_TYPE就是一个数据类型，是一个指向含有5个元素数组的指针类型
    ARRAY_TYPE arrp = &arr;     //ARRAY_TYPE就可以定义一个数组指针，arr是数组首元素的首地址，arrp=&arr表示的是arrp指向arr这个数组

    for(int i = 0; i < 5; i++)
    {
        printf("%d ",(*arrp)[i]); //*arrp等价于arr
    }
    printf("\n");
}

void test03()
{
    int arr[] = {1,2,3,4,5};

    //3.直接定义数组指针变量,arrp就是一个数组指针
    int (*arrp)[5] = &arr;   //数组的每个元素:int类型、数组的元素个数:5、中间写一个指针变量并命名

    for(int i = 0; i < 5; i++)
    {
        printf("%d ",(*arrp)[i]); //*arrp等价于arr
    }
    printf("\n");
}


int main()
{
    test01();
    test02();
    test03();
}