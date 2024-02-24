#include<stdio.h>
#include<conio.h>
#include<string.h>

void con(char *, char *);
void rev(char *);
int pal(char *);
int main()
{
    char str1[50], str2[50];
    printf("String 1 : ");
    fflush(stdin);
    gets(str1);
    printf("String 2 : ");
    fflush(stdin);
    gets(str2);
    con(str1, str2);
    printf("\nAssembled String is %s \n", str1);
    if(pal(str1))
        printf("\tPalindrome \n");
    else
        printf("\tNot Palindrome \n");
    rev(str1);
    printf("Reversed String is %s \n", str1);
    return 0;
}

void con(char * str1, char * str2)
{
    int l=0, i;
    l = strlen(str1);

    for(i=0; str2[i] != '\0'; i++, l++)
        str1[l] = str2[i];

    str1[l]='\0';
}

void rev(char * str)
{
    int i, n=strlen(str);
    char temp;
    for(i=0; i<=n/2; i++)
    {
        temp=str[n-i-1];
        str[n-i-1]=str[i];
        str[i]=temp;
    }
}

int pal(char * str)
{
    int i, n=strlen(str);
    for(i=0; i<(n/2); i++)
    {
        if(str[n-i-1]!=str[i])
            return 0;
    }
    return 1;
}
