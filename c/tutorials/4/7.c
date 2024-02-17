#include<stdio.h>
#include<conio.h>

void rdmat(int **, int, int);
int sumdnl(int **, int, int);
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
    printf("Sum of Square of Diagonal Element is %d ",sumdnl(a, m, n));
    getch();
}

void rdmat(int ** a, int m, int n)
{
    int i, j;
    for(i=0; i<m; i++)
        for(j=0; j<n; j++)
            scanf("%d", &a[i][j]);
}

int sumdnl(int **a, int m, int n)
{
    int i, j, sum=0;
    for(i=0; i<m; i++)
        for(j=0; j<n; j++)
            if(i==j)
                sum+=a[i][j]*a[i][j];
    return sum;
}


