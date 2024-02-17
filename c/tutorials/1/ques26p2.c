#include<stdio.h>
#include<conio.h>
void main()
{
    int count=0, num;
    //clrscr();
    printf("Enter Integer ");
    scanf("%d",&num);
    count=log(num)+1;
    printf("total digit is %d",count);
    getch();
}

