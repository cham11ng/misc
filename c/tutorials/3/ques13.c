#include<stdio.h>
#include<conio.h>

int swap(int *, int *);
int main()
{
    int a=2, b=3;
    printf("before swapping a=%d b=%d\n", a, b);
    swap(&a, &b);
    printf("after swapping a=%d b=%d", a, b);
    return 0;
}

int swap(int * x, int * y)
{
    int temp;
    temp=*y;
    *y=*x;
    *x=temp;
    return 0;
}
