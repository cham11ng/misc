#include<stdio.h>

int fibo( int, int, int);

int main()
{
    int n;

    printf("Number of Term: ");
    scanf("%d", &n);
    fibo(0, 1, n);
    return 0;
}

int fibo( int a, int b, int n)
{
    static int t=1;
    if(t<=n)
    {
        printf("%d \t", a);
        t++;
        fibo(b, a+b, n);
    }
    return 0;
}


