#include<stdio.h>
void main()
{
    int i,j,a=1,k=9;
    for(i=1;i<=k;i++)
    {
        for(j=1;j<=i;j++)
        {
            if(a==0){a=1;}
            else{a=0;}
            printf("%d",a);
        }
        printf("\n");
    }
    getch();
}
