#include<stdio.h>

int main()
{
    int a=1, i, sum=1;

    for(i=1; i<=10; i++)
    {
        printf("%d\t", sum);
        sum=sum+a;
        a+=2;
    }
    getch();
    return 0;
}
