#include<stdio.h>
void main()
{
    int i, j=0;
    for(i=1; i< 10; i++)
    {
        printf("%d \t", j);
        j+=i;
    }
}
