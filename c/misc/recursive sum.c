#include<stdio.h>
#include<conio.h>

int SUM(int);

int main()
{
    int term;
    printf("Term : ");
    scanf("%d", &term);
    printf("Sum of %d term of natural number : %d", term, SUM(term));
    return 0;
}

int SUM(int term)
{
    if(!term)
        return 0;
    else
        return term + SUM(term-1);
}
