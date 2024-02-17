#include<stdio.h>
#include<conio.h>
int main()
{
    int i,a=3;
    for(i=1;i<=25;i++)
    {
        printf("%3d",a);
        a=a+4;
    }
    getch();
    return 0;
}
