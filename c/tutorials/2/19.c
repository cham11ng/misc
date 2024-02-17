#include<stdio.h>

int power(int, int);

int main()
{
    int sb=10, db=8, dec, oct=0, rem, i=0;
    printf("Decimal Number ");
    scanf("%d", &dec);
    while (dec!=0)
    {
        rem=dec%db;
        oct+=(rem*power(sb, i));
        dec=dec/db;
        i++;
    }
    printf(" Octal Number %d ", oct);
    return 0;
}

int power(int x, int y)
{
    if(y==0)
        return 1;
    else
        return x*power(x, y-1);
}
