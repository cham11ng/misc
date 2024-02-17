#include<stdio.h>

int sumn( int , int * );
int main()
{
    int n, sum=0;
    printf("Enter number of term : ");
    scanf("%d", &n);
    sumn(n, &sum);
    printf("Sum of %d entered number is %d ", n, sum);

    return 0;
}

int sumn( int n, int * sum )
{
    static int temp=1, num;
    if(temp<=n)
    {
        printf("Enter Number : ");
        scanf("%d", &num);
        (*sum)+=num;
        temp++;
        sumn( n, sum );
    }
    return 0;

}

