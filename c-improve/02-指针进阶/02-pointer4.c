//
// Created by Cola on 2023/11/28.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//指针做函数参数的输入特性：主调函数分配内存，被调函数使用。
//栈区分配内存：
void fun(char *p)
{
    //给p指向的内存区域拷贝内容
    strcpy(p, "hello abcde");
}

void test01(void)
{
    //栈上分配内存
    //输入，主调函数分配内存
    char buf[1024] = { 0 };
    fun(buf);                    // 由于buf这个栈空间是主调函数test01分配的，所以被调函数在执行完毕后虽然被调函数对应的栈空间会被释放，
                                    // 但是buf空间未被释放，里面被操作的内存也没有释放，被调函数操作的空间仍存在。
    printf("buf  = %s\n", buf);
}

//堆区分配内存：
void printString(char * str)
{
    printf("%s\n", str);
}
void test02()
{
    //堆区分配内存
    char * p = malloc(sizeof(char)* 64);
    memset(p, 0, 64);
    strcpy(p, "hello world");
    printString(p);
}

//指针做函数参数的输入特性：被调函数分配内存，主调函数使用。//这种情况下被调函数只能在堆区分配内存，否则被调函数在执行完毕后其栈区内存会立即被释放。
//分配堆区内存：
void allocteSpace( char  ** x)
{
    char  * temp =  malloc(sizeof(char)* 64);  //temp = &
    memset(temp, 0, 64);
    strcpy(temp, "hello world!!!");
    * x = temp;                                     //x指向的内存空间赋值为temp，即p = temp;
}

void test03()
{
    char * p = NULL;
    allocteSpace(&p);                           //char ** x = &p; x是二级指针，x指向p这个char *类型的指针
    printf("%s\n", p);
    if (p!=NULL)
    {
        free(p);
    }
    p = NULL;
}

int main()
{
    test01();
    test02();
    test03();
}

