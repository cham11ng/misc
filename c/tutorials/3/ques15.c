#include<stdio.h>

int lwrupr( char * );
int main()
{
    char ch;
    int flag;
    printf("Enter Character : ");
    scanf("%c", &ch);
    flag=lwrupr(&ch);
    if(flag==1)
        printf("The character in lower case is %c ", ch);
    else if(flag==2)
        printf("The character in upper case is %c ", ch);
    else
        printf("\t%c", ch);

}

int lwrupr( char * charac )
{
    if( (*charac)>='A' && (*charac)<='Z' )
    {
        (*charac)+=32;
        return 1;
    }
    else if( (*charac)>='a' && (*charac)<='z' )
    {
        (*charac)-=32;
        return 2;
    }
    else
        return 0;
}
