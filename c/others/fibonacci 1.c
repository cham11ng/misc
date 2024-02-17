#include <stdio.h>

void fibonacci(int, int, int);
int main()
{
    int a=0, b=1, n=10;

    fibonacci(a, b, n);
    return 0;
}

void fibonacci(int a, int b, int n)
{

    static int c=1;
    if(c<=n)
    {
        printf(" %d\t", a);
        c++;
        fibonacci(b, b+a, n);
    }
}
