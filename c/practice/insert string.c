#include<stdio.h>
#include<conio.h>
#include<string.h>

char * (insertt)(char *, char *, int);

int main()
{
    char str_1[500], str_2[200], * finall;
    int l;
    printf("String : ");
    fflush(stdin);
    gets(str_1);
    printf("Position : ");
    scanf("%d", &l);
    printf("String to be Inserted : ");
    fflush(stdin);
    gets(str_2);
    finall=insertt(str_1, str_2, l);
    printf("Final String = %s", finall);
    return 0;
}

char * (insertt)(char * a, char * b, int p)
{
    static char ins[40];
    int i, n, l;
    l = strlen(b);
    n = strlen(a) + l;
    for(i = 0; i < n; i++)
    {
        if(i < p)
            ins[i] = a[i];
        else if(i < p + l)
            ins[i] = b[i - p];
        else
            ins[i] = a[i - l];
    }
    ins[i]='\0';
    return ins;
}
