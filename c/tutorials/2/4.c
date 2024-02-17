#include<stdio.h>
#include<conio.h>

int main()
{
    int c=0;
    char string[100];
    printf("Message : ");
    gets(string);

    while ( string[c] !='\0' )
        c++;
    printf(" Number of characters: %d",c);
    getch();
    return 0;
}
