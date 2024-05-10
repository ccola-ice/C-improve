//
// Created by Cola on 2023/11/28.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//1、指针越界
void test01()
{
    char buf[8] = "zhangtao";
    printf("buf:%s\n",buf);
}

//2、返回局部变量的地址
char *getString()
{
    char str[] = "abcdedsgads"; //栈区，
    printf("getString - str = %s\n", str);
    return str;
}
void test02()
{
    char * str = getString();
    printf("test - str = %s\n", str);
}

//3、连续释放堆空间
void test03()
{
    char *p = malloc(sizeof(char) * 64);
    free(p);
    free(p);
}

//4、释放偏移后的地址
//本来开辟的空间的p指针是指向开辟的堆区的首地址，循环过后，它指向hello world\0的最后一个字符，
//此时去释放这个p指针是错的，因为这个p相当于未定义过，相当于去释放一个野指针。
void test04()
{
    char str[] = "hello world";
    char *p = malloc(64);
    for (int i = 0; i <= strlen(str); i++)
    {
        *p = str[i];
        ++p;
    }
    free(p);
}

int main()
{
    test01();
    test02();
    test03();
    test04();
}