/* Quadratic Equation b*b<4ac gives imaginery result */
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>
void main()
{
    int x1,x2,i1=0,i2=0,a,b,c,calc;
    printf("Enter Coeffs. A B C: ");
    scanf("%d%d%d",&a,&b,&c);
    calc=b*b-4*a*c;
    if(calc>0)
    {
      x1=(-b+sqrt(calc))/(2*a);
      x2=(-b-sqrt(calc))/(2*a);
    }
    else
    {
      calc=fabs(calc);
      x1=x2=-b/(2*a);
      i1=i2=sqrt(calc)/(2*a);
    }
    printf("Roots of Given equatin is \n x1= %d + %di \n x2= %d - %di",x1,i1,x2,i2);
    getch();
}
