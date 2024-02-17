#include<stdio.h>

int sumofdigit(int *);
int main()
{
    int num;
    printf("NUMBER ");
    scanf("%d", &num);

    while(num>9)
    {
        sumofdigit(&num);
    }

    printf("Sum of Digit: %d", num);
    return 0;
}

int sumofdigit(int * num)
{
    int sum=0, rem;
    while(*num!=0)
    {
        rem=*num%10;
        sum=sum+rem;
        *num=*num/10;
    }
    *num=sum;
    return 0;
}

