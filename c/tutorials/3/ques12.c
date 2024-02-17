#include<stdio.h>

int readData( int *, int *, int *, int * );
int processData( int *, int *, int *, int *, int *, int * );
int displayData( int *, int * );

int main()
{
    int m, n, p, q, f1, f2;
    readData( &m, &n, &p, &q );
    processData( &f1, &f2, &m, &n, &p, &q );
    displayData( &f1, &f2 );
    return 0;
}

int readData( int * a, int * b, int * c, int * d )
{
    printf("Enter Fractional Number in the Form (5/6) : ");
    scanf("%d/%d", a, b);

    printf("Enter Another Fractional Number           : ");
    scanf("%d/%d", c, d);
    return 0;
}

int processData( int * f1, int * f2, int * a, int * b, int * c, int * d )
{
    *f1= *a + *c;
    *f2= *b + *d;
    return 0;
}

int displayData( int * a, int * b )
{
    printf("Sum of Fractional Number is %d/%d", *a, *b);
}



