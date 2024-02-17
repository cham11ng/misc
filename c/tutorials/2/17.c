#include<stdio.h>
#include<conio.h>
int main()
{
    int n,i,j;
    for(i=1;i<=20;i++)
    {
        printf("Table %d  :", i);
        for(j=1;j<=10;j++)
        {
            n=i*j;
            printf("%4d", n);
        }
        printf("\n");
    }
    getch();
    return 0;
}
