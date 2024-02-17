#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>

void rdmat(int **, int, int);
int largst(int **, int, int);
int smalst(int **, int, int);
int main()
{
    int ** a, m, n, i, sum, dif;
    printf("Order of Matrix ");
    scanf("%d %d", &m, &n);
    a = (int **) malloc(m * sizeof(int *));
    for(i=0; i<m; i++)
        a[i] = (int *) malloc(n * sizeof(int *));
    printf("Enter Values ");
    rdmat(a, m, n);
    sum=largst(a, m, n)+smalst(a, m, n);
    dif=largst(a, m, n)-smalst(a, m, n);
    printf("Sum = %d Difference = %d", sum, dif);
    return 0;
}

void rdmat(int ** a, int m, int n)
{
    int i, j;
    for(i=0; i<m; i++)
        for(j=0; j<n; j++)
            scanf("%d", &a[i][j]);
}

int largst(int ** a, int m, int n)
{
    int i, j, large=a[0][0];
    for(i=0; i<m; i++)
        for(j=0; j<n; j++)
            if(large<a[i][j])
                large=a[i][j];
    return large;
}

int smalst(int ** a, int m, int n)
{
    int i, j, small=a[0][0];
    for(i=0; i<m; i++)
        for(j=0; j<n; j++)
            if(small>a[i][j])
                small=a[i][j];
    return small;
}
