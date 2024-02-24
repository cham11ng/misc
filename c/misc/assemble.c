#include<stdio.h>
#include<conio.h>
#include<string.h>

void con(char *, char *);

int main()
{
    char str1[50], str2[50];
    printf("String 1 : ");
    fflush(stdin); gets(str1);
    printf("String 2 : ");
    fflush(stdin); gets(str2);
    con(str1, str2);
    printf("\nAssembled String is %s \n", str1);
    getch();
    return 0;
}

void con(char * str1, char * str2)
{
    int i, l=strlen(str1);
    for(i = l; str2[i-l] != '\0'; i++)
        str1[i] = str2[i-l];
    str1[i] = '\0';
}
