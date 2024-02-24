#include<stdio.h>
void main()
{
   int a=0,b=1,sum,i;
   for(i=1;i<=20;i++)
   {
      printf("%d \t",a);
      sum=a+b;
      a=b;
      b=sum;
   }
   getch();
}

