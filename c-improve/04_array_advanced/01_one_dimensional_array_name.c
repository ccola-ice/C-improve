//
// Created by 21739 on 2024/5/8.
//
#include <stdio.h>

//void printArray(int * arr,int len)
void printArray(int arr[],int len)
{
    for(int i =0;i<len;i++)
    {
        printf("%d ",arr[i]);
        printf("%d ",*(arr+i));
    }
    printf("\n");
}

void test01()
{
    int arr[] = {1,2,3,4,5};

    //特殊情况1：sizeof(一维数组名)
    printf("sizeof(arr) = %d\n",sizeof(arr));

    //特殊情况2：对数组名取地址
    printf("%d\n",&arr);
    printf("%d\n",&arr + 1);

    //除了上述两种特殊情况，一维数组数组名就是指向一维数组第一个元素的指针。
    int * p = arr;

    //数组名是指针常量，指针常量的指向不可修改，指向的值可以修改。
    int * const p1;     //p1是指针常量，const离p1近，则p1是不能改的，*p1是能改的。
    const int * p2;     //p2是常量指针，const离*近，则*p2是不能改的，p2是可以改的。
}

void test02()
{
    int arr[]={1,2,3,4,5};

    int *p = arr;

    printf("%d\n",*p);
    printf("%d\n",p[0]);
    p = p + 3;      //p此时指向4.
    printf("%d\n",p[0]);
    printf("%d\n",p[-1]);
    printf("%d\n",p[-2]);
    printf("%d\n",p[-3]);

    //以下几种写法等价：
    printf("p[1]    = %d\n",p[1]);
    printf("*(p+1)  = %d\n",*(p+1));
    printf("*(1+p)  = %d\n",*(1+p));
    printf("1[p]    = %d\n",1[p]);

    printArray(arr,5);
}

int main()
{
    test01();
    test02();
}
