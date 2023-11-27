//
// Created by Cola on 2023/11/27.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int main()
{
    test01();
}
