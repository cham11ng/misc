#include<stdio.h>

int fact(int);
void main()
{
    int n=5, n1;

    n1=fact(n);

    printf("factorial = %d", n1);
}
int fact(int a)
{
    printf("%d",a);
    if(a==1)
    {
        return 1;
    }
    else
    {

        return a*fact(a-1);

    }
}
