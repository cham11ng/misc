/* Quadratic Equation b*b<4ac gives imaginery result */
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>
int main()
{
    int x1,x2,i,x,a,b,c,calc;
    printf("Enter Coeffs. A B C: ");
    scanf("%d%d%d",&a,&b,&c);
    calc=b*b-4*a*c;
    if(calc>0)
    {
        x1=(-b+sqrt(calc))/(2*a);
        x2=(-b-sqrt(calc))/(2*a);
        printf("Roots of Given equatin is \n x1= %d \n x2= %d",x1,x2);
    }
    else
    {
        calc=fabs(calc);
        x=-b/(2*a);
        i=sqrt(calc)/(2*a);
        printf("Roots of Given equatin is \n x1= %d + %di \n x2= %d - %di", x, i, x, i);
    }
    getch();
    return 0;
}

