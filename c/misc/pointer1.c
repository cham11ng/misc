#include <stdio.h>

int main()
{
    int *p, x, y;

    x = 50;
    p = &x;
    y = *p;

    printf("y=%d p=%d\n", y, p);

    return 0;
}
