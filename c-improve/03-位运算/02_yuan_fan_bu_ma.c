//
// Created by Cola on 2023/12/4.
//
#include <stdio.h>

void test01()
{
    char num = -15;
    //原码  1000 1111
    //反码  1111 0001
    //补码  1111 1010

    //有符号输出
    printf("%d\n", num);

    //无符号输出
    printf("%u\n", num & 0x000000ff);
    //编译器自动让结果与 前3个字节为1 的数字 做了按位或操作
    /*
        0000 0000 0000 0000 0000 0000 1111 0001  反码
        1111 1111 1111 1111 1111 1111 0000 0000 |
        1111 1111 1111 1111 1111 1111 1111 0001  结果
    */
}

void test02()
{

    char num = 0x9b;  // 这个就是 1001  1011  就是补码
    //计算机原样存储
    // 有符号取
    // 补码 1001  1011
    // 原码 1110  0101   -（64 + 32 + 4 + 1） = - 101
    printf("%d\n", num);

    //无符号取
    printf("%x\n", num & 0x000000ff); //9b
    printf("%u\n", num & 0x000000ff); // 128 + 16 + 8 + 2 + 1 = 155
}


int main()
{
    test01();
    test02();
}