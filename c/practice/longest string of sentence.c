#include<stdio.h>
#include<conio.h>
char * longest(char *);
int main()
{
    char sen[50];
    printf("Sentence : ");
    fflush(stdin); gets(sen);
    printf("Longest String : %s", longest(sen));
    return 0;
}

char * longest(char * sen)
{
    static char temp[10][20];
    int i, b=0, l=0, len=0, ret=0;
    for(i=0; sen[i]!='\0'; i++)
    {
        if(sen[i]==' ' || sen[i]=='\t')
        {
            temp[b++][l] = '\0';
            l = 0;
        }
        else
        {
            if(l > len) {
                ret = b;
                len = l;
            }
            temp[b][l++] = sen[i];
        }
    }
    return temp[ret];
}
