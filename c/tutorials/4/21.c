#include<stdio.h>
#include<conio.h>
#include<string.h>

int palin(char *);

int main()
{
    char str[500];
    printf("String : ");
    scanf("%s", str);

    if(palin(str))
        printf("String is Palindrome");
    else
        printf("String is Not Palindrome");

    getch();
    return 0;
}

int palin(char * str)
{
    int i, n=strlen(str);
    for(i=0; i<(n/2); i++)
    {
        if(str[n-i-1]!=str[i])
            return 0;
    }
    return 1;
}

