#include<stdio.h>
#include<conio.h>
void main()
{
    int num, r, sum=0;
    //clrscr();
    printf("Enter 4 digit number ");
    scanf("%d", &num);
    while (num!=0)
    {
        r=num%10;
        sum=sum+r;
        num=num/10;
    }
    printf("%d is sum of digit", sum);
    getch();
}
