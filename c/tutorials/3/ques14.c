#include<stdio.h>
#include<conio.h>

int swap(int *, int *, int *);
int main()
{
    int a, b, c;
    printf("Enter a b c ");
    scanf("%d %d %d", &a, &b, &c);
    printf("before swapping a=%d b=%d c=%d \n", a, b, c);
    swap(&a, &b, &c);
    printf("after swapping a=%d b=%d c=%d \n", a, b, c);
    return 0;
}

int swap(int * a, int * b, int * c)
{
    int temp;
    temp=*a;
    *a=*c;
    *c=*b;
    *b=temp;
    return 0;
}
