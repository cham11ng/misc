/*PalinDrome no from 1- 12321 */
#include<stdio.h>
#include<conio.h>
void main()
{

    int r,sum=0,num,temp;
    for(temp=10;temp<=12321;temp++)
    {
    num=temp;
    while(num>0)
    {
       r=num%10;
       sum=sum*10+r;
       num=num/10;
    }
    if(temp==sum)
    {
      printf("%d \t",temp);
    }
    sum=0;
    }

    getch();
}
