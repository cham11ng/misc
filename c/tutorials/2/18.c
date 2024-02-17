#include<stdio.h>
#include<conio.h>

int main()
{
    int num,r,sum=0;
    printf("Enter Number ");
    scanf("%d",&num);

    sum=0;
    while(num>0)
    {
        r=num%10;
        sum=sum+r;
        num=num/10;
    }

    printf("Sum of All digit %d", sum);
    getch();
    return 0;
}

