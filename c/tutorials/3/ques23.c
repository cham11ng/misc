#include<stdio.h>

int sumn( int * );
int main()
{
    int sum=0;
    sumn(&sum);
    printf("Sum of non-negetive number is %d ", sum);

    return 0;
}

int sumn( int * sum )
{
    int num;
    printf("Number : ");
    scanf("%d", &num);

    if(num>0)
    {
        (*sum)+=num;
        sumn( sum );
    }
    return 0;
}

