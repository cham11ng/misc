#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void rm(int **, int, int);
void dm(int **, int, int);
void mm(int **, int **, int **, int, int, int);
int main()
{
    int ** a, ** b, ** c, m, n, p, q, i;
    printf ("Order of Matrix A? ");
    scanf("%d %d", &m, &n);
    printf ("Order of Matrix B? ");
    scanf("%d %d", &p, &q);
    if (n!=p)
    {
        main();
        exit(0);
    }

    a = (int **) malloc(m * sizeof(int *));
    for(i=0; i<n; i++)
        a[i] = (int *) malloc (n * sizeof(int));
    b = (int **) malloc(m * sizeof(int *));
    for(i=0; i<n; i++)
        b[i] = (int *) malloc (n * sizeof(int));
    c = (int **) malloc(m * sizeof(int *));
    for(i=0; i<n; i++)
        c[i] = (int *) malloc (n * sizeof(int));

    rm(a, m, n);
    rm(b, p, q);
    mm(a, b, c, m, q, n);
    printf("Multiplied Matrix :\n");
    dm(c, m, q);
    return 0;
}

void rm(int ** a, int m, int n)
{
    int i, j;
    printf(" Data's : \n");
    for(i=0; i<m; i++)
        for(j=0; j<n; j++)
            scanf("%d", &a[i][j]);
}

 void dm(int ** a, int m, int n)
{
    int i, j;
    for(i=0; i<m; i++, printf("\n"))
        for(j=0; j<n; j++)
            printf("%d\t", a[i][j]);

}

void mm(int ** a, int ** b, int ** c, int m, int q, int n)
{
    int i, j, k;
    for(i=0; i<m; i++)
        for(j=0; j<q; j++)
        {
            c[i][j] = 0;
            for(k=0; k<n; k++)
                c[i][j] += a[i][k] * b[k][j];
        }
}
