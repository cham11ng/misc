#include<stdio.h>

int sumone( int , int * , int *);
int main()
{
    int n=20, esum=0, osum=0;


    sumone(n, &esum, &osum);
    printf("Sum of first %d Odd : %d Even : %d ", n, osum, esum);

    return 0;
}

int sumone( int n, int * esum , int *osum)
{
    static int temp=1;
    if(temp<=n)
    {
        if( temp%2==0 )
            (*esum)+=temp;
        else
            (*osum)+=temp;
        temp++;
        sumone( n, esum, osum );
    }
    return 0;
}
