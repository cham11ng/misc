#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void read(int ** a, int m, int n)
{
    int i, j;
    printf("Values : \n");
    for(i = 0; i < m; i++)
        for(j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
}

void display(int ** a, int m, int n)
{
    int i, j;
    for(i = 0; i < m; i++)
    {
        for(j = 0; j < n; j++)
            printf("%3d", a[i][j]);
        printf("\n");
    }
}

void transpose(int **a, int ** b, int m, int n)
{
    int i, j;
    for(i = 0; i < m; i++)
        for(j = 0; j < n; j++)
            b[j][i] = a[i][j];
}

int main()
{
    int i, m, n, ** a, ** b, ** r;
    printf("Dimention : ");
    scanf("%d %d", &m, &n);
    a = (int **) malloc (m * sizeof(int *));
    for(i=0; i < m; i++)
        a[i] = (int *) malloc (n * sizeof(int));

    b = (int **) malloc (n * sizeof(int *));
    for(i=0; i < n; i++)
        b[i] = (int *) malloc (m * sizeof(int));

    read (a, m, n);
    transpose( a, b, m, n);
    display(b, n, m);
    return 0;
}


