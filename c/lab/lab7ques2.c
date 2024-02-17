#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

char * binconv(int, int *);
int main()
{
    char * bin;
    int count=0, n, i;
    printf("Enter Decimal no. ");
    scanf("%d", &n);
    bin = binconv(n, &count);
    for(i=count-1; i>=0; i--)
        printf("%c", bin[i]);
    getch();
    return 0;
}

char * binconv(int n, int * count)
{
    int i=0;
    static char * a;
    a = (int *) malloc(20 * sizeof(int));
    do
    {
        if(n%2==0)
            a[i]='0';
        else
            a[i]='1';
        i++;
    } while((n/=2)!=0);
    *count=i;
    return a;
}
