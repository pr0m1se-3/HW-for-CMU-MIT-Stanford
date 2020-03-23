#include<stdio.h>
enum sz{S=0,L=3,XL};
int main()
{
    printf("%d\n",sizeof(short int));
    short int s=0XFF0012;
    printf("%x\n",s);
    printf("%d\n",s);
    return 0;

}