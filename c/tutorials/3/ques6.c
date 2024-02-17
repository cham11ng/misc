#include<stdio.h>
//#include<conio.h>

int onlyeven( int , int );
int main()
{
    int lpl, upl;
    printf("Lower Limt Number : ");
    scanf("%d", &lpl);
    printf("Upper Limt Number : ");
    scanf("%d", &upl);

    onlyeven(lpl, upl);

    return 0;
}

int onlyeven( int ll, int ul)
{
    int i;
    for(i=ll; i<=ul; i++)
    {
        if( i % 2 == 0 )
            printf("%d \t", i);
    }
    return 0;
}
