/* largest among 3 numbers */
#include<conio.h>
#include<stdio.h>
void main()
{
   int num_1,num_2,num_3,large;
   printf("Enter Number ");
   scanf("%d",&num_1);
   printf("Enter Number ");
   scanf("%d",&num_2);
   printf("Enter Number ");
   scanf("%d",&num_3);
   if(num_1>num_2)
   {
      if(num_1>num_3)
      {
	large=num_1;
      }
      else
      {
	large=num_3;
      }
   }
   else
   {
      if(num_2>num_3)
      {
	large=num_2;
      }
      else
      {
	large=num_3;
      }
   }
   printf("\n Largest Value %d ",large);
   getch();
}
