#include<stdio.h>
#include<conio.h>
int main()
{
    int n, i, fact=1;
    printf("Number : ");
    scanf("%d",&n);

    for(i=1;i<=n;i++)
        fact=fact*i;

    printf("Factorial of %d : %d", n, fact);
    getch();
    return 0;
}
