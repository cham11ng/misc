#include<stdio.h>
//#include<conio.h>

int rever( long int *);
int main()
{
    int num;
    printf("Number : ");
    scanf("%ld", &num);
    rever(&num);

    printf("Reversed Number is %ld", num);
    return 0;
}

int rever( long int * number)
{
    long int reverse=0, rem;
    while(*number!=0)
    {
        rem=*number%10;
        *number=*number/10;
        reverse=reverse*10+rem;
    }
    *number=reverse;
    return 0;
}
