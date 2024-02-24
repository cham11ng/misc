/* Factorial */
#include<stdio.h>
#include<conio.h>
void main()
{
    long int fact=1,num,loop;
    printf("Enter No. for Factorial Result ");
    scanf("%ld",&num);
    for(loop=1;loop<=num;loop++)
    {
       fact=fact*loop;
    }
    printf("The Factorial of %ld is %ld",num,fact);
    getch();
}
