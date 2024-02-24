#include<stdio.h>
#include<conio.h>

int main()
{
    float inc, tax;
    printf("Income : ");
    scanf("%f", &inc);
    if(inc > 100000)
    {
        tax = 0;
        if(inc > 175000)
        {
            tax = (175000 - 100000) * 15 / 100;
            if(inc > 175000)
                tax += (inc - 175000) * 25 / 100;
        }
        else
            tax = (inc - 100000) * 15 / 100;
    }
    else
        tax = 0;
    printf("Taxable Amount : %.2f", tax);
    getch();
    return 0;
}
