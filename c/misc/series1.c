#include<stdio.h>
void main()
{
   int i,temp=1;
   for(i=1;i<=5;i++)
   {
      printf("%d \t",temp);
      temp=temp*10+1;
   }
   getch();
}
