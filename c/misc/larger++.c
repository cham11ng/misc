/*Largest Among Entered Numbers By USER */
#include<stdio.h>
#include<conio.h>
void main()
{
    int large=0,num,input;
    printf("Enter How many Numbers to be Entered ");
    scanf("%d",&num);
    while(num!=0)
    {
       printf("Enter Number ");
       scanf("%d",&input);
       if(input>large)
	 large=input;
       num--;
    }
    printf("Largest No is = %d",large);
    getch();
}
