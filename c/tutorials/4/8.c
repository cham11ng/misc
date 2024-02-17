#include<stdio.h>
#include<conio.h>
#include<math.h>

void rdmat(int **, int, int);
float norm(int **, int, int);
void main()
{
    int ** a, m, n, i;
    printf("Order of Matrix ");
    scanf("%d %d", &m, &n);
    a = (int **) malloc(m * sizeof(int *));
    for(i=0; i<m; i++)
        a[i] = (int *) malloc(n * sizeof(int *));
    printf("Enter Values ");
    rdmat(a, m, n);
    printf("Norm of Matrix is %f ",norm(a, m, n));
    getch();
}

void rdmat(int ** a, int m, int n)
{
    int i, j;
    for(i=0; i<m; i++)
        for(j=0; j<n; j++)
            scanf("%d", &a[i][j]);
}

float norm(int **a, int m, int n)
{
    int i, j, sum=0;
    for(i=0; i<m; i++)
        for(j=0; j<n; j++)
            sum+=a[i][j]*a[i][j];
    return sqrt(sum);
}


