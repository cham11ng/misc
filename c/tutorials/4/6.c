#include<stdio.h>
#include<conio.h>

void rdmat(int **, int, int);
int chksym(int **, int, int);
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
    if(chksym(a, m, n))
        printf("Matrix is Symmetric");
    else
        printf("Matrix is not Symmetric");
    getch();
}

void rdmat(int ** a, int m, int n)
{
    int i, j;
    for(i=0; i<m; i++)
        for(j=0; j<n; j++)
            scanf("%d", &a[i][j]);
}

int chksym(int **a, int m, int n)
{
    int i, j;
    for(i=0; i<m; i++)
        for(j=0; j<n; j++)
        {
            if(a[i][j]==a[j][i])
                continue;
            else
                return 0;
        }
    return 1;
}

