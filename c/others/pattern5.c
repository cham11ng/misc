#include<stdio.h>
void main()
{
    int i,j,k,l,m,z;
    printf("Enter Number ");
    scanf("%d",&z);
    for(i=-z;i<=z;i++)
    {
        k=abs(i); l=abs(k-2);
        printf("*");
        for(j=1;j<=l;j++)
        {
            printf(" ");
        }
        printf("*");
        for(m=1;m<=2*k-1;m++)
        {
            printf(" ");
        }
        if(m>1)
            printf("*");
        printf("\n");
    }
    getch();
}
