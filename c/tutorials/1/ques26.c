#include<stdio.h>
#include<conio.h>
void main()
{
    int count=0, num;
    //clrscr();
    printf("Enter Integer ");
    scanf("%d",&num);
    while(num!=0)
    {
        count++;
        num=num/10;
    }
    printf("total digit is %d",count);
    getch();
}
