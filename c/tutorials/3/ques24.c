#include<stdio.h>

int hcf( int, int);
int main()
{
    int a, b, c;

    printf("Enter Three Number ");
    scanf("%d %d %d", &a, &b, &c);
    printf("HCF is %d", hcf ( hcf(a, b), c));
    return 0;

}

int hcf( int hcff, int y)
{
    int rem;
    rem = y % hcff;
    if(rem==0)
        return hcff;
    else
    {
        y=hcff;
        hcff=rem;
        return hcf( hcff, y );
    }
}
