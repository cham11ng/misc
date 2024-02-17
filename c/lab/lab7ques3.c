#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int multmat(int **,int **,int **, int, int, int, int);
void reamat(int **,int ,int );
void dismat(int **, int, int);
int main()
{
    int **a, **b, **r, n, m, p, q, i;

    printf("Enter the order of matrix : ");
    scanf("%d %d", &m, &n);
    printf("Enter the order of matrix : ");
    scanf("%d %d", &p, &q);
    a=(int **) malloc (m * sizeof(int *));
    for(i=0; i<=m; i++)
        a[i] = (int *) malloc (n * sizeof(int));

    b=(int **) malloc (p * sizeof(int *));
    for(i=0; i<=p; i++)
        b[i] = (int *) malloc (q * sizeof(int));

    r=(int **) malloc (m * sizeof(int *));
    for(i=0; i<=m; i++)
        r[i] = (int *) malloc (q * sizeof(int));

    reamat(a, m, n);

    reamat(b, p, q);
    if(multmat(a,b,r,m,n,p,q))
        dismat (r,m,q);
    else
        printf("Matrices cannot be multiplied");
    getch();
    return 0;
}

void reamat(int ** a, int m, int n)
{
    int i,j;
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
            scanf("%d",&a[i][j]);
}
void dismat(int ** a,int m,int n)
{
    int i,j;
    for(i=0;i<m;i++)
    {
        for (j=0;j<n;j++)
            printf("%d\t",a[i][j]);
        printf("\n");
    }
}
int multmat(int ** a,int ** b,int ** r, int m, int n, int p, int q)
{
    int i,j,k;
    if (n==p) {
        for (i=0;i<m;i++)
            for (j=0;j<q;j++) {
                r[i][j]=0;
                for(k=0;k<n;k++)
                    r[i][j]+=a[i][k]*b[k][j];
            }
        return 1;
    }
    else
        return 0;
}

