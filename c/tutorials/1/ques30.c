#include<stdio.h>
#include<conio.h>
void main()
{
    char lwrupr;
    int a;
    //clrscr();
    printf("Enter character in lower case or upper case ");
    scanf("%c",&lwrupr);
    if(lwrupr>='a' && lwrupr<='z')
        lwrupr=lwrupr-32;
    else if(lwrupr>'A' && lwrupr<='Z')
        lwrupr=lwrupr+32;
    printf("\t%c\n",lwrupr);
    getch();
}
