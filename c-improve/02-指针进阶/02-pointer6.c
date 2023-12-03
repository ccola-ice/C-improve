//
// Created by Cola on 2023/11/28.
//
#include <stdio.h>
#include <stdlib.h>

//二级指针做函数参数的输入特性：test01(),test02()
//主调函数分配内存，被调函数使用
void printArray(int ** p,int num)
{
    for(int i = 0;i<num;i++)
    {
        printf("第%d个元素的值为%d,地址为%p\n", i, *p[i], p[i]);
    }
}

//在堆区开辟空间：
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

    //释放堆区空间
    if(pArray != NULL)
    {
        free(pArray);
        pArray = NULL;
    }
}

//在栈区开辟空间：
void test02()
{
    int * pArray[5];

    for(int i=0;i<5;i++)
    {
        pArray[i] = malloc(sizeof(int *));
        *(pArray[i]) = i+100;
    }

    printArray(pArray,5);

    //释放堆区空间
    for(int i=0;i<5;i++)
    {
        if(pArray[i] != NULL)
        {
            free(pArray[i]);
            pArray[i] = NULL;
        }
    }
}

//二级指针做函数参数的输出特性：test03()
//被调函数分配内存，主调函数使用
void allocateSpace(int ** p1)
{
    int * arr = malloc(sizeof(int)*10);

    for(int i=0;i<10;i++)
    {
        arr[i] = i;
    }

    *p1 = arr;
}

void printArray2(int ** p2,int num)
{
    for(int i=0;i<num;i++)
    {
        printf("%d  ",(*p2)[i]);
    }
}

//只能把形参指针置空
void freeArray1(int * p3)
{
    if(p3 != NULL)
    {
        free(p3);
        p3 = NULL;
    }
}
//能把实参指针置空
void freeArray2(int ** p3)
{
    if(*p3 != NULL)
    {
        free(*p3);
        *p3 = NULL;
    }
}

void test03()
{
    int * p = NULL;

    //创建空间：
    allocateSpace(&p);

    //遍历数组：
    printArray2(&p,10);

    //释放数组：
/*  //方法1释放数组，释放后p是野指针
    freeArray1(p);
    if(p == NULL)
        printf("\np现在是空指针。\n");
    else
        printf("\np现在是野指针。\n");
*/
    //方法2释放数组，释放后p是空指针
    freeArray2(&p);
    if(p == NULL)
        printf("\np现在是空指针。\n");
    else
        printf("\np现在是野指针。\n");
}

int main()
{
    test01();
    printf("------------------------------------------------------------------------------------\n");
    test02();
    printf("====================================================================================\n");
    test03();
}