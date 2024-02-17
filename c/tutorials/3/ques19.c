#include<stdio.h>

int display( char * );
int main()
{
    char string[]="Programming is fun ";

    display( string );

    return 0;
}

int display( char str[] )
{
    static int temp=1;
    if(temp<=5)
    {
        printf("%s\n", str);
        temp++;
        display( str );
    }
    return 0;
}

