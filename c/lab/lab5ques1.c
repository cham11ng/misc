#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

long int permut(long int, long int);
long int combin(long int, long int);
long int fact(long int);

int main()
{
    long int n, r, perm, comb;
    printf("enter value of n ");
    scanf("%ld",&n);
    printf("enter value of r ");
    scanf("%ld",&r);
    if(r>n)
    {
        printf("math error");
        exit(0);
    }
    perm=permut(n,r);
    comb=combin(perm,r);

    printf("permutation = %ld combination = %ld\n", perm, comb);
    //getch();
    return 0;
}

long int permut(long int n, long int r)
{
    long int perm;
    perm=fact(n)/fact(n-r);
    return perm;
}

long int combin(long int perm, long int r)
{
    long int comb;
    comb=perm/fact(r);
    return comb;
}

long int fact(long int n)
{
    if(n==0)
        return 1;
    else
        return n*fact(n-1);
}
