/* Armstrong Number from 1 to 1000  */
#include<stdio.h>
int main()
{
   int r,sum=0,num,temp;
   for(num=1;num<=1000;num++)
   {
      temp=num;
      while(temp>0)
      {
	 r=temp%10;
	 sum=sum+r*r*r;
	 temp=temp/10;
      }
      if(sum==num)
      {
	printf("%d \t",num);
      }
      sum=0;
   }
   getch();
   return 0;
}
