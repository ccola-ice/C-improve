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
    p = realloc(p,sizeof(int)*20000);
    printf("realloc后p指针的值：%p\n",p);
    printf("---------------------------------\n");
    for(int i = 0;i < 30;i++)
    {
        printf("%d\n",p[i]);
    }
}


void test03()
{
//github test.c
//git add
}

int main()
{
    test02();
}