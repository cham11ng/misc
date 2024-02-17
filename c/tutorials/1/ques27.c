#include<stdio.h>
#include<conio.h>
void main()
{
    int sum=0, r, num;
    //clrscr();
    printf("Enter Integer ");
    scanf("%d",&num);
    while(num!=0)
    {

        r=num%10;
        sum=sum*10+r;
        num=num/10;
    }
    printf("total digit is %d",sum);
    getch();
}
