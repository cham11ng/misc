#include<stdio.h>
#include<conio.h>


int combin(int, int);
int fact(int);

int main()
{
    int i, j;

    for(i=0; i<6; i++)
    {
        for(j=i; j<6; j++)
            printf(" ");

        for(j=0; j<=i; j++)
            printf("%d ", combin(i, j));
        printf("\n");
    }
    getch();
    return 0;
}


int combin(int n, int r)
{
    int comb;
    comb=fact(n)/(fact(n-r)*fact(r));
    return comb;
}

int fact(int n)
{
    if(n==0)
        return 1;
    else
        return n*fact(n-1);
}

