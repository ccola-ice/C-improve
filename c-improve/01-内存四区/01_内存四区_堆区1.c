//
// Created by Cola on 2023/11/22.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//①堆区基本使用：
int * getSpace()
{
    int * temp = malloc(sizeof(int)*5);
    if(temp==NULL)
    {
        printf("分配内存失败\n");
        return 0;
    }
    for(int i=0;i<5;i++)
    {
        temp[i]=i+100;
    }
    return temp;
}
void test01()
{
    int *p = getSpace();
    for(int i=0;i<5;i++)
    {
        printf("%d\n",p[i]);
    }
    if(p!= NULL)
    {
        free(p);
        p=NULL;
    }
}

//②注意事项：同级指针修饰同级指针，主调函数中的指针没有分配内存
void allocateSpace(char *pp)
{
    char * temp = malloc(sizeof(char)*100);
    memset(temp,0,100);
    strcpy(temp,"hello world");
    pp = temp;
}
void test02()
{
    char * p = NULL;
    allocateSpace(p);
    printf("%s\n",p);//输出结果为null
}

//③解决办法1：使用高级指针修饰低级指针
void allocateSpace2(char ** pp)
{
    char * temp = malloc(sizeof(char)*100);
    memset(temp,0,100);
    strcpy(temp,"hello world");
    *pp = temp;
}
void test03()
{
    char * p = NULL;
    allocateSpace2(&p);
    printf("%s\n",p);//输出结果为hello world
}

//④解决办法2：利用函数返回值
char * allocateSpace3()
{
    char * temp = malloc(sizeof(char)*100);
    memset(temp,0,100);
    strcpy(temp,"hello world!!!!!!");
    return temp;
}
void test04()
{
    char * p = NULL;
    p = allocateSpace3();
    printf("%s\n",p);
}

int main()
{
    test01();
    test02();
    test03();
    test04();
}
