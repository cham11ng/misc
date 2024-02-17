#include<stdio.h>

int count ( int *, int *, int * );
int main()
{
    int en=0, on=0, num;
    printf("Enter Number : ");
    scanf("%d", &num);
    count( &num, &en, &on);
    printf(" %d contain %d Even Number and %d Odd Number\n", num, en, on);
    return 0;
}

int count( int * number, int *a, int *b)
{
    int rem, bnum;
    bnum=*number;
    while( bnum!=0 )
    {
        rem=bnum%10;
        if( rem%2==0 )
            (*a)++;
        else
            (*b)++;
        bnum/=10;
    }
    return 0;
}
