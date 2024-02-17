#include<stdio.h>
#include<conio.h>
#include<string.h>

int count (char *, int *, int *, int *, int *, int *);
int main()
{
    int vc, cc, dc, wc, sc;
    char string[100];
    vc = cc = dc = wc = sc = 0;
    printf("String : ");
    gets(string);

    count(string, &vc, &cc, &dc, &wc, &sc );
    printf(" Vowel : %d\n Consonant :%d\n Digit : %d\n White Space : %d\n Special Char : %d\n ", vc, cc, dc, wc, sc);
    getch();
    return 0;

}

int count (char string[], int * vc, int * cc, int * dc, int * wc, int * sc)
{
    int i=0;
    strlwr(string);
    while(string[i]!='\0')
    {
        //printf("%c", string[i]);
        if(string[i]>='a' && string[i]<='z')
        {
            if(string[i]=='a' || string[i]=='e' || string[i]=='i' || string[i]=='o' || string[i]=='u')
                (*vc)++;
            else
                (*cc)++;
        }
        else if(string[i]>='0' && string[i]<='9')
            (*dc)++;
        else if(string[i]=='\n' || string[i]==' ' || string[i]=='\t')
            (*wc)++;
        else
            (*sc)++;
        i++;
    }
    return 0;
}
