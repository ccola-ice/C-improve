//
// Created by Cola on 2024/2/28.
//
#include <math.h>
#include <stdio.h>

void print_logarithm(double x)
{
    if (x <= 0.0) {
        printf("Positive numbers only, please.\n");
        return;
    }
    printf("The log of x is %f.\n", log(x));
}

void foo(int x, int y)
{
    if (x >= 0 && y >= 0) {
        printf("both x and y are positive.\n");
        return;
    } else if (x < 0 && y < 0) {
        printf("both x and y are negetive.\n");
        return;
    }
    printf("x has a different sign from y.\n");
}

//编写一个布尔函数int is_leap_year(int year)，判断参数year是不是闰年。如果某年份能被4整除，但不能被100整除，那么这一年就是闰年，此外，能被400整除的年份也是闰年。
int is_leap_year(int year)
{
    if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0) ) {
        printf("%d is leap year.",year);
        return 1;
    } else {
        printf("%d is not leap year.",year);
        return 0;
    }
}

//编写一个函数double myround(double x)，输入一个小数，将它四舍五入。例如myround(-3.51)的值是-4.0，myround(4.49)的值是4.0。可以调用math.h中的库函数ceil和floor实现这个函数。
double myround(double x)
{
    if(x > 0)
    {
        if((x-(int)x) >= 0.5 )
        {
            printf("%.2f\n",(x-(int)x));
            printf("%.1f\n",ceil(x));
            return (ceil(x));
        }
        else if ((x-(int)x) < 0.5)
        {
            printf("%.2f\n",(x-(int)x));
            printf("%.1f\n",floor(x));
            return (floor(x));
        }
    }
    else if(x < 0)
    {
        if((x-(int)x) <= -0.5 )
        {
            printf("%.2f\n",(x-(int)x));
            printf("%.1f\n",floor(x));
            return (floor(x));
        }
        else if ((x-(int)x) > -0.5)
        {
            printf("%.2f\n",(x-(int)x));
            printf("%.1f\n",ceil(x));
            return (ceil(x));
        }
    }
}

/*
编写递归函数求两个正整数a和b的最大公约数（GCD，Greatest Common Divisor），使用Euclid算法：
    如果a除以b能整除，则最大公约数是b。
    否则，最大公约数等于b和a%b的最大公约数。
Euclid算法是很容易证明的，请读者自己证明一下为什么这么算就能算出最大公约数。最后，修改你的程序使之适用于所有整数，而不仅仅是正整数。
*/
int GCD(int a,int b)
{
    if(a % b == 0)
    {
        return b;
    }
    else
    {
        return (GCD(b,(a%b)));
    }
}

/*
编写递归函数求Fibonacci数列的第n项，这个数列是这样定义的：
    fib(0)=1
    fib(1)=1
    fib(n)=fib(n-1)+fib(n-2)
*/
int fibnacci(int n)
{
    if(n == 0)
        return 1;
    else if (n == 1)
        return 1;
    else
        return (fibnacci(n-1)+ fibnacci(n-2));
}

/*
编写程序数一下1到100的所有整数中出现多少次数字9。在写程序之前先把这些问题考虑清楚：
这个问题中的循环变量是什么？
这个问题中的累加器是什么？用加法还是用乘法累积？
在第 2 节 “if/else语句”的习题1写过取一个整数的个位和十位的表达式，这两个表达式怎样用到程序中？
*/
void numof9()
{
    int i = 0;
    int result = 0;
    while(i != 100)
    {
        if((i%10) == 9 || (i/10) == 9)
            result += 1;
        i += 1;
    }
    printf("1-100中出现9的次数为：%d\n",result);
}

/*

 */
int factorial_1(int n)
{
    int result = 1;
    int i = 1;
    do {
        result = result * i;
        i = i + 1;
    } while (i <= n);

    return result;
}

int factorial_2(int n)
{
    int result = 1;
    int i;
    for(i = 1; i <= n; ++i)
        result = result * i;
    return result;
}

//求1-100之间的素数
int is_prime(int n)
{
    int i;
    for (i = 2; i < n; i++)
        if (n % i == 0)
            break;
    if (i == n)
        return 1;
    else
        return 0;
}


int main()
{
    print_logarithm(10.0);

    foo(-2,3);

    if(is_leap_year(1005))
        printf("yes！\n");
    else
        printf("no! \n");

    printf("%.2f四舍五入的结果为:%.1f\n",-3.51,myround(-3.51));
    printf("%.2f四舍五入的结果为:%.1f\n",4.49,myround(4.49));

    printf("%d与%d的最大公约数为：%d\n",10,20,GCD(10,20));

    printf("Fibnacci数列的第%d项为：%d\n", 9,fibnacci(9));

    numof9();

    for (int i = 1; i <= 100; i++)
    {
        if (!is_prime(i))
            continue;
        printf("%d\n", i);
    }

    return 0;
}

