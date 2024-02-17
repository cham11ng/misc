#include<stdio.h>
#include<conio.h>

int com (int, int);
int fact (int);
int main()
{
    int i, j, n=10;
    for(i = 0; i <= n; i++)
    {
        for(j = 0; j <= i; j++)
            printf("%3d", com(i, j));
        printf("\n");
    }
    return 0;
}

int com(int n, int r)
{
    return fact(n) / (fact(n - r) * fact(r));
}

int fact(int n)
{
    if(n == 0)
        return 1;
    else
        return n * fact( n-1 );
}
