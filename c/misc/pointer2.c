#include<stdio.h>
void swap(int *,int *);
void main()
{
    int x,y;
    x=5;
    y=2;
    swap(&x,&y);
    printf("swaped value of x=%d and y=%d",x,y);

}

void swap(int *a, int *b)
{
    int p;
    p=*a;
    *a=*b;
    *b=p;
}
