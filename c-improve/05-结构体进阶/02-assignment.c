//
// Created by Cola on 2023/12/11.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//浅拷贝：系统提供的赋值，逐字节拷贝。such as "p1=p2"
struct Person{//结构体不含指针
    char name[64];
    int age;
};

void test01()
{
    struct Person person1 = {"张三",20};
    struct Person person2 = {"李四",20};

    printf("person1's name: %s  age: %d\n",person1.name,person1.age);
    printf("person2's name: %s  age: %d\n",person2.name,person2.age);

    person1 = person2; // person2内存空间上的数据会逐字节拷贝到person1的内存空间上。----浅拷贝

    printf("person1's name: %s  age: %d\n",person1.name,person1.age);
    printf("person2's name: %s  age: %d\n",person2.name,person2.age);
}

struct Person2{//结构体内含有指针
    char * name;
    int age;
};

void test02()
{
    struct Person2 p1;
    p1.name = malloc(sizeof(char)*64);
    strcpy(p1.name,"Tom");
    p1.age = 18;

    struct Person2 p2;
    p2.name = malloc(sizeof(char)*128);
    strcpy(p2.name,"Jerry");
    p2.age = 19;

    printf("p1's name: %s  age: %d\n",p1.name,p1.age);
    printf("p2's name: %s  age: %d\n",p2.name,p2.age);

    p1 = p2;
    printf("p1's name: %s  age: %d\n",p1.name,p1.age);
    printf("p2's name: %s  age: %d\n",p2.name,p2.age);

    if(p1.name != NULL)
    {
        free(p1.name);
        p1.name = NULL;
    }
    //由于p2赋值给p1时为浅拷贝，逐字节拷贝，赋值之后就会使得p1.name指针同样指向第二块堆区，p1.name和p2.name指向同一个堆区地址。
    //所以当释放p1.name指向的堆区空间时，再释放p2.name指向的堆区空间就会报错，因为二者指向同一个区域，再次释放相当于释放一个野/空指针。
    //总结：浅拷贝使堆区2被重复释放，堆区1内存泄露。
    //把下面对p2.name释放堆区的代码注释掉才不会报错。
/*
    if(p2.name != NULL)
    {
        free(p2.name);
        p2.name = NULL;
    }
*/
}

//解决办法：当结构体中包含指针，并且指针指向堆区时，要利用深拷贝解决浅拷贝的问题
//深拷贝即自己重新申请一块堆区内存，并手动赋值。
void test03()
{
    struct Person2 p1;
    p1.name = malloc(sizeof(char)*64);
    strcpy(p1.name,"Tom");
    p1.age = 18;

    struct Person2 p2;
    p2.name = malloc(sizeof(char)*128);
    strcpy(p2.name,"Jerry");
    p2.age = 19;

    //先释放原来堆区1(p1.name)的空间，然后在堆区重新开辟一块内存，并使p1.name指向它。
    //这样就使p1.name和p2.name各自指向各自的堆区，各自管理。
    if(p1.name != NULL)
    {
        free(p1.name);
        p1.name = NULL;
    }
    //手动赋值：
    p1.name = malloc(sizeof(p2.name)*128);  //或 malloc(strlen(p2.name)+1);
    strcpy(p1.name,p2.name);
    p1.age  = p2.age;

    printf("p1's name: %s  age: %d\n",p1.name,p1.age);
    printf("p2's name: %s  age: %d\n",p2.name,p2.age);

    if(p1.name != NULL)
    {
        free(p1.name);
        p1.name = NULL;
    }
    if(p2.name != NULL)
    {
        free(p2.name);
        p2.name = NULL;
    }
}

int main()
{
    test01();
    test02();
    test03();
}