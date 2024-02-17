#include<stdio.h>
#include<conio.h>

int sqr(int);

int main()
{
    int i;
    float sum;
    for(i=1;i<=1000;i++)
    {
        sum = (sqr(i)+sqr(i+1)) / ((float)i+2);
        printf(" %.2f, ", sum);
    }
    printf("\b\b \b"); // to remove , (comma) printed above
    getch();
    return 0;
}

int sqr(int a)
{
    int s;
    s=a*a;
    return s;
}
