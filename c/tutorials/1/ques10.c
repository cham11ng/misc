#include<stdio.h>
#include<conio.h>
void main()
{
    float time, principle, rate, si;
    //clrscr();
    printf("Enter Principle Time and Rate ");
    scanf("%f %f %f", &principle, &time, &rate);
    si=principle * time * rate / 1000;
    printf("The Simple Interest is %f", si);
    getch();
}
