#include<stdio.h>
#include<conio.h>
void main()
{
    float base, altitude, area ;
    //clrscr();

    printf("Enter Base and Altitude ");
    scanf("%f %f", &base, &altitude);
    area= 0.5 * base * altitude;
    printf("Area= %.2f", area);

    getch();
}
