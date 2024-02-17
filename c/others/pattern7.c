#include<stdio.h>
void main()
{
    int i,j,k,l,m,n=10;

    for(i=-n;i<=n;i++)
    {
        k=abs(i); l=abs(k-n);
        for(j=1;j<=l;j++)
        {
            printf(" ");
        }
        printf("*");
        for(m=1;m<=2*k-1;m++)
        {
            printf("*");
        }
        if(m>1)
            printf("*");
        printf("\n");
    }
    getch();
}
