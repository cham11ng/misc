#include<stdio.h>
void main()
{
   int num,r,sum=0;
   printf("Enter Number ");
   scanf("%d",&num);
   while(num>9)
   {
       sum=0;
       while(num>0)
       {
          r=num%10;
          sum=sum+r;
          num=num/10;
       }
       num=sum;
   }
   printf("Sum of All digit is %d", sum);
   getch();
}
