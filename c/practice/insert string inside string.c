#include<stdio.h>
#include<conio.h>
#include<string.h>

char * insert(char *, char *, int);
int main()
{
    char str[20], ins[20];
    int p;
    printf("String : ");
    fflush(stdin); gets(str);
    printf("String to be Inserted : ");
    fflush(stdin); gets(ins);
    printf("Position : ");
    scanf("%d", &p);
    printf("Required String : %s", insert(str, ins, p));
    getch();
    return 0;
}

char * insert(char * str, char * ins, int p)
{
    int i, l = strlen(str), n = strlen(ins);
    static char temp[50];
    for(i=0; i<(l+n); i++)
    {
        if(i<p)
            temp[i] = str[i];
        else if(i<(n+p))
            temp[i] = ins[i-p];
        else
            temp[i] = str[i-n];
    }
    temp[i] = '\0';
    return temp;
}
