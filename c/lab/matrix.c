#include<stdio.h>
#include<conio.h>

int multimatrices(int a[][5],int b[][5],int r[][5],int m,int n,int p,int q);
void readmatrices(int a[][5],int *m,int *n);
void displaymatrices(int a[][5],int m,int n);
int main()
{
    int a[5][5],b[5][5],r[5][5],n,m,p,q;
    readmatrices(a,&m,&n);
    readmatrices(b,&p,&q);
    if(multimatrices(a,b,r,m,n,p,q))
        displaymatrices (r,m,q);
    else
        printf("Matrices cannot be multiplied");
    getch();
    return 0;
}

void readmatrices(int a[][5], int *m,int*n)
{
    int i,j;
    printf("Enter he order of matrix:");
    scanf("%d %d",m,n);
    for(i=0;i<*m;i++)
    {
        for(j=0;j<*n;j++)
        {
            printf("Enter Number "); scanf("%d",&a[i][j]);
        }
        printf("\n");
    }
}
void displaymatrices(int a[][5],int m,int n)
{
    int i,j;
    for(i=0;i<m;i++)
    {
        for (j=0;j<n;j++)
            printf("%d\t",a[i][j]);
        printf("\n");
    }
}
int multimatrices(int a[][5],int b[][5],int r[][5],int m,int n,int p,int q)
{
    int i,j,k;
    if (n==p)
    {
        for (i=0;i<m;i++)
            for (j=0;j<q;j++)
            {
                r[i][j]=0;
                for(k=0;k<n;k++)
                    r[i][j]+=a[i][k]*b[k][j];
            }
        return 1;
    }
    else
        return 0;
}
