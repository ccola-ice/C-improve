//
// Created by Cola on 2023/11/22.
//
#include <stdio.h>

int * func_1()
{
    int a=10;
    return &a;
}

void test01()
{
    int *p = func_1();
    printf("p=%d\n",*p);
}

char * getString()
{
    char str[]="hello world!";
    return str;
}

void test02(void)
{
    char * p = NULL;
    p = getString();
    printf("p=%s\n",p);
}

int main()
{
    //test01();//结果是乱码或无法运行或卡死
    test02();//结果是乱码
}
