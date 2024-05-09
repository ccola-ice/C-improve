//
// Created by 21739 on 2024/5/8.
//
#include <stdio.h>

//传递二维数组的数组名时有三种方法：
//void print_Array(int array[][3], int row, int col)
//void print_Array(int array[3][3], int row, int col)
void print_Array(int (*array)[3], int row, int col)
{
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            printf("%d ",array[i][j]);  //可读性强
            //printf("%d ",*(*(array+i)+j));   //[][]的本质
        }
        printf("\n");
    }
}

void test01()
{
    /*定义二维数组变量并初始化的方法：*/
    //定义方式1：最后一行的逗号可以省略
    int arr1[3][3]=
            {
                    {1, 2, 3},
                    {4, 5, 6},
                    {7, 8, 9}
            };
    //定义方式2：二维数组的本质也是一个连续存储空间
    int arr2[3][3] = {1,2,3,4,5,6,7,8,9};
    //定义方式3：省略行数,不能省略列数，表示3列一行。根据列数可以推断出行数，最后一行的空缺位置会被补0。
    int arr3[][3] = {1,2,3,4,5,6,7,8,9,10};

    //二维数组名：除了两种特殊情况外，二维数组名的本质是二维数组的第一个元素(一维数组)的首地址，即指向第一个一维数组的数组指针，二维数组名加一是移动到下一行/元素(一维数组)
    int (*p1)[3] = arr1;
    int (*p2)[3][3] = &arr1;

    /*访问二维数组arr1中的“6”这个元素的方法：*/
    //法1：直接法
    printf("%d\n",arr1[1][2]);
    //法2：采用二维数组指针p2,刚初始化后p2指向的是arr1的第0个一维数组，即第0行，(p2+1)指向的是第1个一维数组，即第1行，
    //此时*(p2+1)还是一个指针，指向第2行的第0个数，*(p2+1)+2指向的是第2行的第2个数，此时再解引用*(*(p2+1)+2)就是元素6。
    //其实就想当于把两个[]拆出来。
    printf("%d\n",*(*(arr1+1)+2));
    printf("%d\n",*(*arr1+5));
    printf("%d\n",*(*(p1+1)+2));
    printf("%d\n",*(*(*p2)+5));


    /*两种特殊情况*/
    //1.sizeof(二维数组名)获取的是整个二维数组的空间大小
    printf("%d\n",sizeof(arr1));
    //2.对二维数组名取地址
    int (*p3)[3][3] = &arr1;   //步长是整个二维数组的大小。步进单位是二维数组。
    printf("&arr1 = %d\n",&arr1);
    printf("&arr1 + 1 = %d\n",&arr1 + 1);

    /*获取二维数组的行数和列数*/
    int row = sizeof(arr1) / sizeof(arr1[0]);   //整个二维数组的大小/每一行的大小
    int col = sizeof(arr1[0]) / sizeof(int);    //每一行的大小/一行中某个元素的大小
    printf("row = %d\n",row);
    printf("col = %d\n",col);
    /*遍历二维数组*/
    print_Array(arr1,row,col);  //用二维数组指针去接二维数组名

    printf("&arr1[0][0] = %d\n",&arr1[0][0]);
    printf("arr1 = %d\n",arr1);
    printf("&arr1 = %d\n",&arr1);
    //上面三行的打印结果相同，但是区别在于他们的步长:
    //&arr1[0][0]是二维数组第(0,0)个元素的地址，步长是一个元素的大小(1个int)
    //arr1是二维数组第0个元素(第0个一维数组/第0行)的地址，步长是一个一维数组的大小(3个int)
    //&arr1是整个二维数组的地址，步长是整个二维数组的大小(9个int)
    printf("&arr1[0][0] + 1 = %d\n",&arr1[0][0] + 1);
    printf("arr1 + 1 = %d\n",arr1 + 1);
    printf("&arr1 + 1 = %d\n",&arr1 + 1);

    printf("address of the 2d array: %x\n",&arr1);
    printf("address of 0th row of 2d array: %x\n",arr1+0);
    printf("address of 0th num of 0th row of 2d array: %x\n",arr1[0]+0);
}

int main()
{
    test01();
}