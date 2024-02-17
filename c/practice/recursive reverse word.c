#include<stdio.h>
#include<conio.h>
#include<string.h>

void reverse(char *, int, int);

int main()
{
    char text[50];
    printf("String : ");
    fflush(stdin); gets(text);
    reverse(text, 0, strlen(text));
    printf("Reversed String : %s", text);
    return 0;
    getch();
}

void reverse(char * text, int i, int n)
{
    char temp;
    if(n / 2)
    {
        temp = text[n-1];
        text[n-1] = text[i];
        text[i] = temp;
        reverse(text, i+1, n-1);
    }
}

