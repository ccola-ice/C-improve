//
// Created by Cola on 2023/11/23.
//
#include <stdio.h>
#include <stdlib.h>


void test01()
{
    //int * p = malloc(sizeof(int)*10);                             //malloc不会初始化开辟的内存空间
    int * p = calloc(10,sizeof(int));    //calloc会初始化开辟的内存空间
    for(int i = 0;i < 10;i++)
    {
        printf("%d\n",p[i]);
    }
    if(p != NULL)               //手动释放
    {
        free(p);
        p = NULL;
    }
}

void test02()
{
    int * p = malloc(sizeof(int)*10);
    for(int i = 0;i < 10;i++)
    {
        p[i] = i + 100;
    }
    for(int i = 0;i < 10;i++)
    {
        printf("%d\n",p[i]);
    }
    printf("realloc前p指针的值：%p\n",p);
    p = realloc(p,sizeof(int)*20000);        //重新分配20000个int大小的堆空间。
    printf("realloc后p指针的值：%p\n",p);               //若原空间后面够大，足够新增的空间使用，则p指针不变，否则会重新找一块很大的空间来分配堆，
    printf("---------------------------------\n");    //此时p指针是改变的。
    for(int i = 0;i < 30;i++)
    {
        printf("%d\n",p[i]);   //扩展出来的新空间是没有被初始化的（B站张涛版本），自己实验时发现是有初始化的。
    }
    if(p != NULL)
    {
        free(p);           //手动释放
        p = NULL;
    }
}

int main()
{
    test01();
    printf("============================================================\n");
    test02();
}