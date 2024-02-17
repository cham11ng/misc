#include<stdio.h>

int main()
{
    long int m, n, product=1, i, j;

    printf("Enter Value of m= ");
    scanf("%ld",&m);
    printf("Enter Value of n= ");
    scanf("%ld",&n);

    for(i=1; i<=n; i++)
    {
        product=product*m;
    }

    printf("%ld to power %ld is = %ld\n", m, n, product);
    return 0;
}
