#include<stdio.h>

int power(int, int);

int main()
{
    int sb=8, db=10, dec=0, oct, rem, i=0;
    printf("Octal Number ");
    scanf("%d", &oct);
    while (oct!=0)
    {
        rem=oct%db;
        dec+=(rem*power(sb, i));
        oct=oct/db;
        i++;
    }
    printf(" Decimal Number : %d ", dec);
    return 0;
}

int power(int x, int y)
{
    if(y==0)
        return 1;
    else
        return x*power(x, y-1);
}

