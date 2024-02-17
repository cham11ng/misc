#include<stdio.h>
#include<conio.h>

char * longwo(char *);
int main()
{
    char str[50], * lwOrd;
    printf("String : ");
    fflush(stdin);
    gets(str);
    lwOrd=longwo(str);
    printf("\nLongest World = %s\n", lwOrd);
    getch();
    return 0;
}

char * longwo(char * str)
{
    static char word[50][50];
    int i, l, r, len, ret;
    len = ret = i = l = r = 0;
    while(str[i]!='\0')
    {
        if(str[i]!=' ' && str[i]!='\t')
        {
            if(l > len)
            {
                len=l;
                ret=r;
            }
            word[r][l++]=str[i];
        }
        else
        {
            word[r++][l]='\0';
            l=0;
        }
        i++;
    }
    return word[ret];
}

