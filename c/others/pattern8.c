#include<stdio.h>
void main()
{
    int i,j,k=9;
    for(i=1;i<=k;i++)
    {
        for(j=1;j<=i;j++)
        {
            if((i+j)%2==0)
                printf("0");
            else
                printf("1");
        }
        printf("\n");
    }
    getch();
}
