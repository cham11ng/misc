#include<conio.h>
#include<stdio.h>
int main()
{
    int n, i, sum=0;
    printf("Number : ");
    scanf("%d",&n);

    if(n>0)
    {
        for(i=n; i<=n*2; i++)
            sum=sum+i;
    }
    else if(n<0)
    {
        for(i=n*2;i<=n;i++)
            sum=sum+i;
    }
    else
        printf("The entered number is zero");
    printf("\n Sum=%d",sum);
    getch();
    return 0;
}
