/*
10 20 30 40
20 30 40 50
30 40 50 60
40 50 60 70

*/
#include <stdio.h>

void main()
{
    int i, j, print=10;
    for(i=1; i<=4; i++)
    {
        for(j=1; j<=4; j++)
        {
            printf("%d ", print);
            print+=10;
        }
        print-=30;
        printf("\n");
    }
}
