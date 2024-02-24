//fibonacci series recursion
#include<stdio.h>
#include<conio.h>

void fibo(int, int, int);

int main()
{
    int n=10;
    printf("Term : ");
    scanf("%d", &n);
    fibo(0, 1, n);
    getch();
    return 0;
}

void fibo(int a, int b, int n)
{
    if(n)
    {
        printf("%d \t", a);
        fibo(b, a+b, n-1);
    }
}
