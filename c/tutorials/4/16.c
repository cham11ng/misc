#include<stdio.h>
#include<conio.h>
#include<string.h>

void rev(char *, int, int);

int main()
{
    char str[500];
    printf("String : ");
    fflush(stdin);
    gets(str);
    rev(str, 0, strlen(str));
    printf("Reversed word is %s ", str);
    getch();
    return 0;
}

void rev(char * str, int i, int n)
{
    char temp;
    if(i < n/2)
    {
        temp=str[n-i-1];
        str[n-i-1]=str[i];
        str[i]=temp;
        i++;
        rev(str, i, n);
    }
}
