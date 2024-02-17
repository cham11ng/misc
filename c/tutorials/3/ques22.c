#include<stdio.h>
#include<math.h>

int sumn( int, int, int * );
int main()
{
    int n, sum=0;
    printf("Enter number of term : ");

    scanf("%d", &n);

    sumn(n, 0, &sum);
    printf("Sum of %d natural number is %d ", n, sum);

    return 0;
}

int sumn( int num, int ser, int * sum )
{
    static int n=0;
    if(n<=num)
    {
        (*sum)+=ser;
        n++;
        sumn( num, pow((-1), n+1) * n * n , sum);
    }
    return 0;
}

