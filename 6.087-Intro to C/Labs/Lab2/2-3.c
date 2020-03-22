#include<stdio.h>

int test(int num)
{
    int bits=num&0XF;
    return (bits==0X7||bits==0xB||(bits>=0XD));
}
int reverse(int num)
{
    return ((num&0XFF)<<8)|((num&0XFF00)>>8);
}
int rotate(int num)
{
    return ((num&0XF)<<12)|((num&0XFFF0)>>4);
}
int main()
{
    int val=0XCAFE;
    printf("%d\n",test(val));
    printf("%x\n",reverse(val));
    printf("%x\n",rotate(val));
}