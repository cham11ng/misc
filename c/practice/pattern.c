#include<stdio.h>
#include<conio.h>

int main()
{
    int i, j, n=10;
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n-i; j++)
            printf("    ");
        for(j = 1; j <= i; j++)
            printf(" %2d ", j);
        for(j = j - 2; j >=1; j--)
            printf(" %2d ",j);
        printf("\n");
    }
    return 0;
}
