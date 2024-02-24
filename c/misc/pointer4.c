#include<stdio.h>
void main()
{
    int x,y;
    int *ptr;
    x=10;
    ptr=&x;
    y=*ptr;
    printf("vlaue of x is %d \n",x);
    printf("%d is stored at addr %u \n",x,&x);
    printf("%d is stored at addr %u \n",*&x,&x);
    printf("%d is stored at addr %u \n",*ptr,ptr);
    printf("%d is stored at addr %u \n",ptr,&ptr);
    printf("%d is stored at addr %u \n",y,&y);
    *ptr=25;
    printf("\n now x=%d\n",x);
}
