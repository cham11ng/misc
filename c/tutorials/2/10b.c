#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int main()
{
    float a, b, m, c, d, n, det, x, y;
    printf("Simultaneous Equation\n");
    printf("Ax+By=M : ");
    scanf("%f %f %f", &a, &b, &m);
    printf("Cx+Dy=N : ");
    scanf("%f %f %f", &c, &d, &n);
    det=c*b-a*d;
    if(det==0)
    {
        printf("Math Error !!! ");
        exit(0);
    }
    else
    {
        x=(b*n-d*m)/det;
        y=(c*m-a*n)/det;
    }
    printf("x=%.2f y=%.2f", x, y);
    getch();
    return 0;
}
