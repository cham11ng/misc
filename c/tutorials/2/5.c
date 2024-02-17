#include<stdio.h>
#include<conio.h>

int main()
{
    char a[100];
    int i=0;
    printf("MESSEGE : ");
    gets(a);

    while ( a[i] != '\0' )
    {
        if(a[i]>='a' && a[i]<='z')
            a[i]-=32;
        else if(a[i]>='A' && a[i]<='Z')
            a[i]+=32;
        i++;
    }
    puts(a);
    getch();
    return 0;
}

