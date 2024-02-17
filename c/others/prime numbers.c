/*Prime From 1 to 100 */
#include<stdio.h>
#include<conio.h>
void main()
{

    int i,j,c;
    for(i=1;i<=100;i++)
    {
       j=1;
       c=0;
       do
       {
	  if(i%j==0)
	  {
	     c++;
	  }
	  j++;
       } while(j<=i);
       if(c==2)
       {
	 printf("%d\t",i);
       }
    }
    getch();
}
