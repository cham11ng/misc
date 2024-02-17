#include<stdio.h>
#include<conio.h>
void main()
{
    float p, n, r, f ;
    //clrscr();
    printf("Enter Principle N Rate");
    scanf("%f %f %f", &p, &n, &r);
    f=p*pow((1+r),n);
    printf("Compound Interest amount is %f ", f);
    getch();
}
