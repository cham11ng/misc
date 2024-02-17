#include<stdio.h>
#include<conio.h>
int main()
{
    int i,n;
    printf("Multiplication Table of ??? ");
    scanf("%d",&n);
    for(i=1;i<=10;i++)
        printf("%4d * %2d = %2d\n", n, i, n*i);
    getch();
    return 0;
}
