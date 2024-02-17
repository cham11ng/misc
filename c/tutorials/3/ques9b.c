#include<stdio.h>
#include<conio.h>

int display();
int main()
{
    display();
    return 0;
}

int display()
{
    int i, j, a=1;
    for(i=1; i<=6; i++)
    {
        for(j=1; j<=i; j++, a++)
            printf(" %d ", a);
        printf("\n");
    }
    return 0;
}
