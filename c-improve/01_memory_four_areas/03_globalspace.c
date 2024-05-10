//
// Created by Cola on 2023/11/23.
//
#include <stdio.h>
#include <stdlib.h>

//静态变量只初始化一次，static int s_a = 10只执行一次
void func()
{
    static int s_a = 10;        //静态变量只初始化一次
    s_a++;
    printf("s_a = %d\n", s_a);
}
void test01()
{
    func();     //static int s_a = 10会执行
    func();     //static int s_a = 10不会执行
    func();     //static int s_a = 10不会执行
}

//未初始化的静态变量会被初始化为0
void test02()
{
    static int s_b;
    printf("s_b = %d\n",s_b);
}

//const修饰的变量
//const修饰的全局变量：全局变量保存在常量区/静态区/全局区，受到常量区的保护，上面的值不可以被修改
const int a = 10;
void test03()
{
    //a = 20;   //直接修改，失败
    //int * p = &a;
    //*p = 20;
    //printf("a = %d\n",a);   //间接修改，失败
}
//const修饰的局部变量：
void test04()
{
    const int b = 10;   //虽然仍是const修饰，
    //b = 20;     //直接修改，失败 
    int * p = &b;
    *p = 20;
    printf("b = %d\n",b);   //间接修改，成功
}

//字符串常量：
//1、字符串常量是共享的
void test05()
{
    char * p1 = "hello world";
    char * p2 = "hello world";
    char * p3 = "hello world";
    printf("%p\n",&("hello world"));
    printf("%p\n",p1);
    printf("%p\n",p2);
    printf("%p\n",p3);  //三个不同的指针的地址值是相同的，指向同一个字符串常量。
}
//2、在mingw环境下，不允许修改字符串常量对应的内存，否则程序会崩溃
void test06()
{
    char * p = "hello world";
    printf("%c\n",p[0]);
    //p[0] = 'x';
    printf("%s\n",p);
}


int main()
{
    test01();
    test02();
    test03();
    test04();
    test05();
    test06();
}