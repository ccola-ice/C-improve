//
// Created by Cola on 2023/12/11.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
struct Person{
    char name[64];
    int age;
    //1、结构体中可以放函数吗？：
    */
/*
     * void func()
     * {
     *      age++;
     * }
     * *//*

    //结论：声明和实现都不可以

    //2、结构体中的属性可以赋初值吗？
    //int height = 180;
    //结论：不可以，C语言中在结构体设计阶段不可以赋初值
};
*/

typedef struct Person{
    char name[64];
    int age;
}myperson;   //myperson是struct Person的类型别名

struct Person2{
    char name[64];
    int age;
}person2={"aaa",25};  //person2是结构体变量,在创建的时候可以赋初值。在定义结构体类型的时候顺便定义一个结构体变量person2。

struct{     //匿名结构体 ，后面不能通过这个结构体创建新的结构体变量
    char name[64];
    int age;
}person3={"ccc",22};  //person3是结构体变量,在创建的时候可以赋初值。

void test01()
{
    myperson person = {"xxx",23};
    printf("person1 name:%s  age:%d\n",person.name,person.age);
}

void test02()
{
    printf("person2 name:%s  age:%d\n",person2.name,person2.age);
    strcpy(person2.name,"bbb");
    person2.age = 26;
    printf("person2 name:%s  age:%d\n",person2.name,person2.age);
}

void test03()
{
    printf("person3 name:%s  age:%d\n",person3.name,person3.age);
    strcpy(person3.name,"zhang");
    person3.age = 27;
    printf("person3 name:%s  age:%d\n",person3.name,person3.age);
}

//分别在堆区和栈区创建和使用结构体
void test04()
{
    //栈区创建和使用
    myperson p1 = {"aa",20};
    printf("姓名:%s  年龄:%d\n",p1.name,p1.age);
    //堆区创建和使用
    struct Person * p2 = malloc(sizeof(struct Person));
    strcpy(p2->name, "bb");
    p2->age = 21;
    printf("姓名:%s  年龄:%d\n",p2->name,p2->age);
    if(p2!=NULL)
    {
        free(p2);
        p2=NULL;
    }
}

//结构体数组（结构体变量数组）
void printArray(struct Person personsArray[],int num)
{
    for(int i = 0;i<num;i++)
    {
        printf("姓名：%s 年龄：%d\n",personsArray[i].name,personsArray[i].age);
    }
}
void test05()
{
    //栈区创建
    struct Person personsArray[]=
    {
        {"a1",11},
        {"a2",12},
        {"a3",13},
        {"a4",14},
        {"a5",15},
    };
    int len = sizeof(personsArray)/sizeof(struct Person);
    printArray(personsArray,len);

    //堆区创建
    struct Person * personarrPoint = malloc(sizeof(struct Person)*5);
    for(int i=0;i<5;i++)
    {
        sprintf(personarrPoint[i].name,"name_%d",i);
        personarrPoint[i].age = 20 + i;
    }
    printArray(personarrPoint,5);
    if(personarrPoint != NULL)
    {
        free(personarrPoint);
        personarrPoint=NULL;
    }
}

int main()
{
    test01();
    test02();
    test03();
    test04();
    test05();
}












