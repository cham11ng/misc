#include<stdio.h>
void main()
{

    int i,j,k=20;
    for(i=1;i<=k;i++)
    {
        for(j=1;j<=k;j++)
        {
            if(i==j || j==k+1-i)
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
    getch();
}
