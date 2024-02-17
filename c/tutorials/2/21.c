#include<stdio.h>
#include<conio.h>
int main()
{
    int i, a=4, n;
    printf("Term : ");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        printf("%d, ", i*a);
        a=a+3;
    }
    printf("\b\b \b");
    getch();
    return 0;
}


