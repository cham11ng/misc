#include<stdio.h>
#include<conio.h>
#include<ctype.h>
void main()
{
    char lwrupr;
    //clrscr();
    printf("Enter character in lower or upper case");
    scanf("%c", &lwrupr);

    if(lwrupr>='a' && lwrupr<='z')
        lwrupr=toupper(lwrupr);

    else if(lwrupr>'A' && lwrupr<='Z')
        lwrupr=tolower(lwrupr);

    else
        printf("\t%c\n", lwrupr);
    getch();
}
