#include<stdio.h>
void main()
{
    int a,b,d,c=9,i;
    for(a=1;a<=c;a++)
    {
        for(b=c-a;b>=1;b--)
        {
            printf(" ");
        }

        for(d=1;d<=a;d++)
        {
            printf("%d",d);
        }

        for(i=d-2;i>=1;i--)
        {
            printf("%d",i);
        }

        printf("\n");
    }
    getch();
}
