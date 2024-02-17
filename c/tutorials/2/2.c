#include<stdio.h>
#include<conio.h.>
int main()
{
    int n, i;
    printf("Enter term :");
    scanf("%d",&n);
    printf("\t| Number \t Square \t Cube |\n");
    for(i=1;i<=n;i++)
        printf("\t| %d \t\t %d \t\t %d\n", i, i*i, i*i*i);
    getch();
    return 0;
}
