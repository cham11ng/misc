#include <stdio.h>

int main()
{
    char string[20], temp[20];
    int a, b=0, c=0;

    printf("input string ");
    gets(string);


    for(a=0; string[a]!='\0'; a++)
    {
        c++;
    }
    for(a=c-1; a>=0; a--)
    {
        temp[b]=string[a];
        b++;
        printf("temp=%c and string=%c\n",temp[b], string[a]);

    }
    if(temp==string)
    {
        printf("palindrome\n");
    }
    else
    {
        printf("not palindrome\n");
    }
    return 0;
}
