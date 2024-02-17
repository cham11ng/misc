#include<stdio.h>

int sumn( int );
int main()
{
    int n, sum=0;
    printf("Enter number of term : ");
    scanf("%d", &n);
    printf("Sum of %d entered number is %d ", n, sumn(n));
    return 0;
}

int sumn( int n )
{
    int i, sum=0, num;
    for(i=0; i<n; i++)
    {
        printf("Enter Number : ");
        scanf("%d", &num);
        sum+=num;
    }
    return sum;

}

