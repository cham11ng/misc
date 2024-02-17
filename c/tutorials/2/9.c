#include<stdio.h>
#include<conio.h>
int main()
{
    int n,sum=0,i;
    printf("Enter a number:");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        sum=sum+i;
        printf("%d+", i);
    }
    printf("\b=%d", sum);
    getch();
    return 0;
}
