#include<stdio.h>

int fact( int );
int power( int, int );
float sum( int, int );

int main()
{
    int term, x;
    printf(" Term : ");
    scanf("%d", &term);
    printf(" Value of X : ");
    scanf("%d", &x );
    printf("\n%f is Sum of Series", sum(term, x));

    return 0;
}

float sum( int n , int x )
{
    float sumn=0;
    int i, j=1;
    for(i=1; i<=n; i++)
    {
        sumn=sumn+((power(-1, i+1)*power(x, j))/((float)fact(j)));
        j+=2;
    }
    return sumn;
}

int power(int x, int y)
{
    if(y==0)
        return 1;
    else
        return x*power(x, y-1);
}

int fact( int  n )
{
    if(n==0)
        return 1;
    else
        return n*fact(n-1);
}
