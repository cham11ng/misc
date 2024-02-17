#include<stdio.h>
#include<conio.h>
void main()
{
    int n, a, x=5, y, z;
    //clrscr();
    printf("Enter Integer Number\n");
    scanf("%d", &a);
    printf("a=%d",a);

    printf("\nEnter Integer Number\n");
    x=scanf("%d", &n);
    printf("x=%d",x);

    printf("\nEnter Integer Number\n");
    z=scanf("%d %d", &x, &y);
    printf("z=%d",z);

    getch();
}
