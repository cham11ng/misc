#include<stdio.h>
void main()
{
    int i,j,k,l=1;
    for(i=20;i>=1;i--)
    {

        for(j=i-1;j>=1;j--)
        {
            printf(" ");
        }
        for(k=1;k<=l;k++)
        {
            printf("*");
        }
        printf("\n");
        l=l+2;
    }
    getch();
}
