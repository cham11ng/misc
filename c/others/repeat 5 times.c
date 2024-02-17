// print programing is fun 5 times using recursion

#include <stdio.h>

void repeat();
int main()
{
    repeat();
    return 0;
}

void repeat()
{
    static i=1;
    if (i<=5)
    {
        printf("Programming is Fun \n");
        i++;
        repeat();
    }
}
