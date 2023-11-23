//
// Created by Cola on 2023/11/23.
//
#include <stdio.h>
#include <stdlib.h>

//const修饰的变量
//const修饰的全局变量：全局变量保存在常量区/静态区/全局区，受到常量区的保护，上面的值不可以被修改
const int a = 10;
void test05()
{
    //a = 20;   //直接修改，失败
    //int * p = &a;
    //*p = 20;
    //printf("a = %d\n",a);   //间接修改，失败
}
//const修饰的局部变量：
void test06()
{
    const int b = 10;   //虽然仍是const修饰，
    //b = 20;     //直接修改，失败
    int * p = &b;
    *p = 20;
    printf("b = %d\n",b);   //间接修改，成功
}

int main()
{
    test05();
    test06();
}