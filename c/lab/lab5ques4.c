#include<stdio.h>
#include<conio.h>

int fibonacci(int, int, int);

int main()
{
    int a=0, b=1, n;
    printf("enter no. of term ");
    scanf("%d", &n);

    fibonacci(a, b, n);
    return 0;
}

int fibonacci(int x, int y, int n)
{
    static int count=1;
    if(count<=n)
    {
        printf("%d\t",x);
        count++;
        fibonacci(y, x+y, n);
    }
}
