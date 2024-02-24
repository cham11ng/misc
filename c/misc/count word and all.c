#include<stdio.h>
#include<conio.h>
#include<string.h>

void allcount(char *, int *, int *, int *, int *, int *);
int wOc(char *);

int main()
{
    char text[20];
    int vc, cc, sp, sc, di;
    vc = cc = sc = sp = di = 0;
    printf("Line of Text : ");
    fflush(stdin);
    gets(text);
    printf("Number of Word: %d\n", wOc(text));
    allcount(text, &vc, &cc, &sc, &sp, &di);
    printf("Vowels %d Consonants %d Space %d Special Charecter %d Digit %d", vc, cc, sc, sp, di);
    getch();
    return 0;
}

int wOc(char * str)
{
    int i = 0, flag = 0, count = 0;
    while(str[i++] != '\0')
    {
        if(str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
        {
            if(flag)
                count++;
            flag = 0;
        }
        else
            flag = 1;
    }
    if(flag)
        count++;
    return count;
}

void allcount(char * str, int * vc, int * cc, int * sc, int * sp, int * di)
{
    int i = 0;
    strlwr(str);
    while(str[i] != '\0')
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u')
                (*vc)++;
            else
                (*cc)++;
        }
        else if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
            (*sc)++;
        else if (str[i] >= '0' && str[i] <= '9')
            (*di)++;
        else
            (*sp)++;
        i++;
    }
}
