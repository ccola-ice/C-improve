//
// Created by Cola on 2023/12/4.
//
#include <stdio.h>

void test01()
{
    int a = 10;

    printf("十进制：%d\n", a);
    printf("八进制：%#o\n", a);
    printf("十六进制：%#x\n", a);
    printf("十六进制：%#X\n", a);
}

void test02()
{
    int a = 123;		//十进制方式赋值
    int b = 0123;		//八进制方式赋值， 以数字0开头
    int c = 0xabc;	    //十六进制方式赋值

    printf("十进制：%d\n", a);
    printf("八进制：%#o\n", b);	//%o,为字母o,不是数字
    printf("十六进制：%#x\n", c);
}

int main()
{
    test01();
    test02();
}