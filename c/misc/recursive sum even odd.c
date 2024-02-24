#include<stdio.h>
#include<conio.h>

void SUM(int, int *, int *);

int main()
{
    int term, odd = 0, eve = 0;
    printf("Term : ");
    scanf("%d", &term);
    SUM(term, &odd, &eve);
    printf("Sum of %d term of even number : %d odd number : %d", term, odd, eve);
    return 0;
}

void SUM(int term, int * e, int * o)
{
    if(term)
    {
        if(term%2)
            (*o)+=term;
        else
            (*e)+=term;
        SUM(term-1, e, o);
    }
}
