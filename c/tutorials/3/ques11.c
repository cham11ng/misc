#include<stdio.h>

int checkPrime(int);
int checktwinPrime(int);
int main()
{
    int num, check;
    printf("Number : ");
    scanf("%d", &num);

    check=checktwinPrime(num);
    if(check)
        printf("Yes Twin Prime");
    else
        printf("No Twin Prime");
}

int checkPrime(int num)
{
    int c=0, i;
    for(i=1; i<=num; i++)
    {
        if(num % i == 0)
            ++c;
        if(c>2)
            break;
    }
    if(c==2)
        return 1;
    else
        return 0;
}

int checktwinPrime(int num)
{
    if(checkPrime(num))
    {
        if(checkPrime(num-2)==1 || checkPrime(num+2)==1)
            return 1;
        else
            return 0;
    }
    else
    {
        printf("No Prime\n");
    }
    return 0;
}
