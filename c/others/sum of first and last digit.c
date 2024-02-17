/* Sum of First and Last digit of 4-digit number */
#include<stdio.h>
void main()
{
    int first,last,num;
    printf("Enter 4-digit No: ");
    scanf("%d",&num);
    first=num/1000;
    last=num%10;
    printf("Sum of FIRST and LAST digit is %d",first+last);
    getch();
}
