#include<stdio.h>
#include<conio.h>

char * toggle(char *);

int main()
{
    char str[50];
    printf("String : ");
    fflush(stdin);
    gets(str);
    printf("Toggle Word is %s", toggle(str));
    return 0;
}

char * toggle(char * str)
{
    static char tog[50];
    int i = 0;
    while(str[i] != '\0')
    {
        if(str[i] >= 'a' && str[i] <='z')
            tog[i] = str[i] - 32;

        else if(str[i] >= 'A' && str[i] <='Z')
            tog[i] = str[i] + 32;

        else
            tog[i] = str[i];
        i++;
    }
    return tog;
}
