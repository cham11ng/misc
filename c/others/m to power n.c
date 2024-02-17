#include <stdio.h>

int power(int,int);
void main()
{
    int m, n, o;

    printf("Enter value of m= ");
    scanf("%d", &m);

    printf("Enter value of n= ");
    scanf("%d", &n);

    o=power(m, n);
    printf("%d to the power %d = %d \n", m, n, o);
}

int power(int x, int y)
{
    static c=0;
    if(c<y)
    {
        c++;
        return x*power(x, y);
    }
    else
        return 1;
}
