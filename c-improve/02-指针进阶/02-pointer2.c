//
// Created by Cola on 2023/11/27.
//
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

struct Person
{
    char a;              //占4个字节
    int b;               //占4个字节
    char buf[64];        //占64个字节
    double d;            //占8个字节
};

//指针步长的意义
void test01()
{
    char buf[1024] = {0};
    int a = 0x11111111;
    memcpy(buf,&a,sizeof(int));
    printf("%x\n",buf[0]);
    printf("%x\n",buf[1]);
    printf("%x\n",buf[2]);
    printf("%x\n",buf[3]);
    printf("%x\n",buf[4]);
    char * p = buf;
    printf("%d\n",*(int *)p);

    char buf2[1024] = {0};
    int b = 0x11111111;
    memcpy(buf2+1,&b,sizeof(int));
    printf("%x\n",buf2[0]);
    printf("%x\n",buf2[1]);
    printf("%x\n",buf2[2]);
    printf("%x\n",buf2[3]);
    printf("%x\n",buf2[4]);
    char * p1 = buf2;
    printf("%x\n",*(int *)(p1+1));
}

//在上面结构体中利用地址偏移，找到结构体中d属性的位置以及打印该属性
void test02()
{
    struct Person person={'A',88,"hello world",6666.0};

    printf("直接法得到的d的值为：%f\n",person.d);

    printf("a的偏移量：%d Bytes\n", offsetof(struct Person, a));         //通过函数直接获取结构体某个成员的地址偏移量
    printf("b的偏移量：%d Bytes\n", offsetof(struct Person, b));         //通过函数直接获取结构体某个成员的地址偏移量
    printf("buf的偏移量：%d Bytes\n", offsetof(struct Person, buf));     //通过函数直接获取结构体某个成员的地址偏移量
    printf("d的偏移量：%d Bytes\n", offsetof(struct Person, d));         //通过函数直接获取结构体某个成员的地址偏移量

    printf("a的值为：%c\n",*(char *)((char *)&person + 0));
    printf("b的值为：%d\n",*(int *)((char *)&person + 4));
    printf("buf的值为：%s\n",((char *)&person + 8));                    //字符串不需要解引用，只需提供字符串的第一个字符的偏移地址
    printf("d的值为：%f\n",*(double *)((char *)&person + 72));

    *(double *)((char *)&person + 72) = 9999.0;                              //可以利用这种方法再修改结构体中的值
    printf("修改后的d的值为：%f\n",*(double *)((char *)&person + 72));
}


int main()
{
    test01();
    printf("=========================================================\n");
    test02();
}
