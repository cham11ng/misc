#include<stdio.h>
void main()
{

    int i,j,k;
    for(i=5;i>=1;i--)
    {
        for(k=i-1;k>=1;k--)
        {
            printf(" ");
        }
        for(j=5;j>=i;j--)
        {
            printf("%d",i);
        }
        printf("\n");
    }
    getch();
}
