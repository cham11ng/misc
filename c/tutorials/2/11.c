#include<stdio.h>
#include<conio.h>
int main()
{
    int i;
    for(i=32;i<=255;i++)
    {
        printf("%d : %c\t",i,i);
    }
    getch();
    return 0;
}
