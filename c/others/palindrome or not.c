/*PalinDrome No. or NOT */
#include<stdio.h>
#include<conio.h>
void main()
{
    int r,sum=0,num,temp;
    printf("Enter Number ");
    scanf("%d",&num);
    temp=num;
    while(num>0)
    {
       r=num%10;
       sum=sum*10+r;
       num=num/10;
    }
    if(temp==sum)
    {
       printf("It is Palindrome");
    }
    else
    {
       printf("It is not Palindrome");
    }
    getch();
}
