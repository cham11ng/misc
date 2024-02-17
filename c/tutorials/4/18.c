#include<stdio.h>
#include<conio.h>

void ascii(char *);

int main()
{
    char str[50];
    printf("String : ");
    fflush(stdin);
    gets(str);
    ascii(str);
    return 0;
}

void ascii(char * str)
{
    int i;
    printf("String ASCII Code : ");
    for(i=0; str[i]!='\0'; i++)
        printf("%d ", str[i]);
}
