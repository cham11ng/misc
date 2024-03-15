#include<stdio.h>
#include<conio.h>
void main()
{
    int i;
    float marks[7], total=0, average;
    char name[20];
    //clrscr();
    printf("Enter Name ");
    gets(name);
    for(i=0; i<=6; i++)
    {
        printf("Enter Marks");
        scanf("%f",&marks[i]);
        total=total+marks[i];
    }
    average=total/7;
    printf("%s scored Percentage is %f\n", name, average);
    getch();
}
