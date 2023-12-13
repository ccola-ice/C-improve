//
// Created by Cola on 2023/12/13.
//

//结构体嵌套一级指针

#include <stdio.h>
#include <stdlib.h>

struct Person{
    char * name;
    int age;
};

struct Person ** allocateSpace()
{
    struct Person ** p_Person = malloc(sizeof(struct Perosn *) * 3);

    for(int i=0;i<3;i++)
    {
        //给每个person分配空间：
        p_Person[i] = malloc(sizeof(struct Person));

        //给每个person的name分配空间：
        p_Person[i]->name = malloc(sizeof(char)*64);
        sprintf(p_Person[i]->name,"name_%d",i); //为name赋值

        p_Person[i]->age = 20 + i;
    }
    return p_Person;
}

void printPerson(struct Person ** pp, int len)
{
    for(int i=0;i<len;i++)
    {
        printf("姓名：%s  年龄：%d\n", pp[i]->name, pp[i]->age);
    }
}

void freeSpace(struct Person ** pp,int len)
{
    if(pp == NULL |len < 0)
        return;
    for(int i=0;i<len;i++)
    {
        printf("%s被释放了\n",pp[i]->name);
        //先释放person->name的堆空间
        free(pp[i]->name);
    }
    for(int i=0;i<len;i++)
    {
        //再释放person的堆空间
        free(pp[i]);
    }
    //最后释放ppPerson
    free(pp);
    pp = NULL;
}

void test01()
{
    struct Person ** ppPerson = NULL; //二级指针ppPerson指向一个堆区空间，堆区里存放着3个struct Person *类型的指针，即三个地址

    //分配内存：
    ppPerson = allocateSpace();

    //打印输出：
    printPerson(ppPerson,3);

    //释放内存：与分配内存方向相反
    freeSpace(ppPerson,3);
}

int main()
{
    test01();
}
