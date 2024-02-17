#include<stdio.h>
#include<conio.h>
long int power(int, long int);
int main()
{
    int x, sum=0, pow=1;

    printf("Enter the value of x:");
    scanf("%d", &x);

    while(sum<9999999)
    {
        sum=sum+power(x, pow-1);
        pow++;
    }

    printf("\n Sum : %ld",sum);
    getch();
    return 0;
}

long int power(int x, long int y)
{
    if(y==0)
        return 1;
    else
        return x*power(x, y-1);
}
