/*Prime Number or Not */
#include<stdio.h>
#include<conio.h>
void main()
{

    int i=1,num,count=0;
    printf("Enter Number to Check Prime ");
    scanf("%d",&num);
    do
    {
       if(num%i==0)
       {
	 count++;
       }
       i++;
    } while(i<=num);
    if(count==2)
    {
       printf("It is Prime");
    }
    else
    {
       printf("It is Not Prime");
    }
    getch();
}
