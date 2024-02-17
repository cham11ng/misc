#include<stdio.h>

int main()
{
    int i, j, n=12;

    for(i=1; i<=n; i++)
    {
        for(j=n-i; j>=0; j--)
            printf("   ");
        for(j=1; j<=i; j++)
            printf("%d  ", j);
        for(j=j-2; j>=1; j--)
            printf("%d  ", j);
        printf("\n");
    }
    return 0;
}
